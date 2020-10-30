#include "rand_story.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//to update the space of story and put the new char into the story 
char * story_change(char * story,size_t i,char c){
  story = realloc(story,(i+1)*sizeof(*story));
  //put the new char into the story
  story[i-1] = c;
  //the end of the line
  story[i] = '\0';
  return story;
}
//read a file and write the story
void parse(FILE * f,catarray_t * cats){
  int c;
  size_t i = 0;
  //if the char is in "blank",ifwrite = 0
  int ifwrite = 1;
  char * story = malloc(sizeof(*story));
  
  while((c = fgetc(f))!=EOF){
    //if not in the blank
    if(ifwrite == 1){
      //meet the first "_"
      if(c == '_'){
	const char * cat = chooseWord("verb", cats);
	//replace the blank with cat
        i = i + 3;
	story = realloc(story,(i+1)*sizeof(*story));
	story = strcat(story, cat);
	story[i] = '\0';
	//enter a blank, stop writing
	ifwrite = 0;
      } else {
	i = i+1;
	story = story_change(story,i,c);
      }
    } else if(ifwrite == 0){
      //c is still in a blank check if it's the end of the blank
      if(c == '_'){
	ifwrite = 1;
      }
      //check if there isn't a matching underscore in the same line
      if(c == '\n'){
	fprintf(stderr, "there's no matching underscore\n");
	exit(EXIT_FAILURE);
      } 
      if(c == '\0'){
	fprintf(stderr, "there's no matching underscore\n");
	exit(EXIT_FAILURE);
      }
      continue;
    }
  }
  printf("%s\n",story);
  free(story);
}
