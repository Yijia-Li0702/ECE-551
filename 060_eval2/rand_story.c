#include "rand_story.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void parse(FILE * f,char * story, catarray_t * cats){
  int c;
  int i = strlen(story);
  //if the char is in "blank"
  int ifwrite = 1;
  
  while((c = fgetc(f))!=EOF){
    if(ifwrite == 1){
      if(c == '_'){
	const char * cat = chooseWord("verb", cats);
	i = strlen(story)+strlen(cat);
	//i =i+strlen(cat);
	story = realloc(story,i*sizeof(*story));
	story = strcat(story, cat);
	ifwrite = 0;
      } else if(c == '\n'){
	i = strlen(story)+1;
	//i++;
	story = realloc(story,i*sizeof(*story));
	story[i-1] = c;
      } else {
	//i = strlen(story)+1;
	i++;
	story = realloc(story,i*sizeof(*story));
	story[i-1] = c;
      }
      //printf("%d\n",i);
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
    //printf("%s\n",story);
  }
  i++;
  story = realloc(story,i*sizeof(*story));
  story[i-1] = '\0';
  printf("%s\n",story);
}
