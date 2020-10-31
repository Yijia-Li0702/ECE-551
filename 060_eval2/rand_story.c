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

void store(FILE * f){
  char * curr = NULL;
  size_t sz = 0;
  catarray_t * carr = malloc(sizeof(*carr));
  carr->n = 0;
  carr->arr = malloc(sizeof(*carr->arr));
  while(getline(&curr,&sz,f)>=0){
    //error if : doesn't exist
    char * ptr = strchr(curr,':');
    if(ptr == NULL){
      fprintf(stderr, "there's no colon");
      exit(EXIT_FAILURE);
    }
    //cut the first part before : as name
    char * part1 = strndup(curr,ptr-curr);
    //check if there is the same category before
    int nothave_name = 1;
    for(size_t i = 0;i < carr->n;i++){
      //if(0){
      //arr[i] is a pointer or category 
      if(strcmp(carr->arr[i].name,part1)==0){
	carr->arr[i].n_words++;
	size_t end = carr->arr[i].n_words-1;
	//realloc the space of words to add one more word
	carr->arr[i].words = realloc(carr->arr[i].words, (end+1)*sizeof(*carr->arr[i].words));
	//put the new word to the end of words
	carr->arr[i].words[end]=strdup(ptr+1);
	curr = NULL;
	nothave_name = 0;
	continue;
      }
    }
    //create a new category and put it into catarray carr
    if(nothave_name){
      carr->n++;
      carr->arr = realloc(carr->arr,carr->n*sizeof(*carr->arr));
      carr->arr[carr->n-1].name = malloc(sizeof(*carr->arr[carr->n-1].name));
      carr->arr[carr->n-1].name = part1;
      carr->arr[carr->n-1].words = malloc(sizeof(*carr->arr[carr->n-1].words));
      carr->arr[carr->n-1].words[0]=strdup(ptr+1);
      carr->arr[carr->n-1].n_words = 1;
      curr = NULL;
      nothave_name = 1;
    }
  }
  printWords(carr);
  for(size_t i = 0; i<carr->n;i++){
    free(carr->arr[i].words);
    free(carr->arr[i].name);
  }
  free(carr->arr);
  free(carr);
}

  
