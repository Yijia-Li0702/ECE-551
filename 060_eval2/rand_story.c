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

catarray_t * carr_change(catarray_t * carr,const char * curr,const char * ptr){
   carr->n++;
   carr->arr = realloc(carr->arr,carr->n*sizeof(*carr->arr));
   carr->arr[carr->n-1].name = strndup(curr,ptr-curr);
   carr->arr[carr->n-1].words = malloc(sizeof(*carr->arr[carr->n-1].words));
   size_t len = strlen(ptr+1);
   carr->arr[carr->n-1].words[0]=strndup(ptr+1,len-1);
   carr->arr[carr->n-1].n_words = 1;
   return carr;
}

catarray_t * store(FILE * f){
  char * curr = NULL;
  size_t sz = 0;
  catarray_t * carr = malloc(sizeof(*carr));
  carr->n = 0;
  carr->arr = malloc(sizeof(*carr->arr));

  while(getline(&curr,&sz,f)>=0){
    char * ptr = strchr(curr,':');
    //error if : doesn't exist
    if(ptr == NULL){
      fprintf(stderr, "there's no colon");
      exit(EXIT_FAILURE);
    }
    //cut the first part before : as name
    char * part1 = strndup(curr,ptr-curr);
    //check if there is the same category before
    int nothave_name = 1;
    for(size_t i = 0;i < carr->n;i++){
      //arr[i] is a pointer or category 
      if(strcmp(carr->arr[i].name,part1)==0){
	carr->arr[i].n_words++;
	size_t end = carr->arr[i].n_words-1;
	//realloc the space of words to add one more word
	carr->arr[i].words = realloc(carr->arr[i].words, (end+1)*sizeof(*carr->arr[i].words));
	//put the new word to the end of words
 size_t len = strlen(ptr+1);
	carr->arr[i].words[end]=strndup(ptr+1,len-1);
	nothave_name = 0;
	continue;
      }
    }
    free(part1);
    //create a new category and put it into catarray carr
    if(nothave_name){
      carr = carr_change(carr,curr,ptr);
      nothave_name = 1;
    }
  }
  free(curr);
  return carr;
}

char** prev_change(char** prev, size_t prev_l,const char * cat){
     prev = realloc(prev,prev_l*sizeof(*prev));
     prev[prev_l-1] = strdup(cat);
     return prev;
}
char * s_change(char * story,size_t i,const char * cat){
  	  story = realloc(story,(i+1)*sizeof(*story));
	  story = strcat(story, cat);
	  story[i] = '\0';
     return story;
}

void step3_parse(FILE * f,catarray_t * carr){
  int c;
  size_t i = 0;
  char * story = malloc(sizeof(*story));
  char ** prev = malloc(sizeof(*prev));
  size_t prev_l = 0;
  while((c = fgetc(f))!=EOF){
      //meet the first "_"
      if(c == '_'){
	char * blank = malloc(sizeof(*blank));
	size_t j = 0;
	while((c = fgetc(f))!=EOF){
	  if(c == '_'){
	    break;
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
	  j = j+1;
	  blank = story_change(blank,j,c);
	}
	//check the category is a number
	if(blank[0]>=48 && blank[0]<=57&&j == 1){
     int num = atoi(blank);
     size_t pos = prev_l-num;
     i = i + strlen(prev[pos]);
     story = s_change(story,i,prev[pos]);
	  //story = realloc(story,(i+1)*sizeof(*story));
	  //story = strcat(story, prev[pos]);
	  //story[i] = '\0';
      prev_l++;
     prev = prev_change(prev,prev_l,prev[pos]);
	  free(blank);
	} else {
	  for(size_t k= 0;k < carr->n;k++){ 
	    if(strcmp(carr->arr[k].name,blank)==0){
	      const char * cat = chooseWord(carr->arr[k].name, carr);
             prev_l++;
             prev = prev_change(prev,prev_l,cat);
	      i = i + strlen(cat);
         story = s_change(story,i,cat);
	      //story = realloc(story,(i+1)*sizeof(*story));
	      //story = strcat(story, cat);
	      //story[i] = '\0';
	      free(blank);
	      break;
	    }
	  }
	}
      } else {
	i = i+1;
	story = story_change(story,i,c);
      }
      // printf("%s\n",story);
      //printf("%ld\n",i);
  }
  printf("%s\n",story);
  free(story);
}

void step3(FILE * f, FILE * temp){
  catarray_t * carr = store(temp);
  step3_parse(f,carr);
}

  
