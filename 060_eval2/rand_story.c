#include "rand_story.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// this function is to update the space of story and put the new char into the story
char *story_change(char *story, size_t i, char c) {
  story = realloc(story, (i + 1) * sizeof(*story));
  // put the new char into the story
  story[i - 1] = c; 
  story[i] = '\0'; // the end of the line
  return story;
}

// read a file and write the story
void step1(FILE *f, catarray_t *cats) {
  int c;
  size_t i = 0;
  // if the char is in "blank",ifwrite = 0
  int ifwrite = 1;
  char *story = malloc(sizeof(*story));
  story[0]='\0';
  while ((c = fgetc(f)) != EOF) {
    // if not in the blank
    if (ifwrite == 1) {
      // meet the first "_"
      if (c == '_') {
        const char *cat = chooseWord("verb", cats);
        // replace the blank with cat
        i = i + 3;
        story = realloc(story, (i + 1) * sizeof(*story));
        story = strcat(story, cat);
        story[i] = '\0';
        // enter a blank, stop writing
        ifwrite = 0;
      } else {
        i = i + 1;
        story = story_change(story, i, c);
      }
    } else if (ifwrite == 0) {
      // c is still in a blank check if it's the end of the blank
      if (c == '_') {
        ifwrite = 1;
      }
      // check if there isn't a matching underscore in the same line
      if (c == '\n' || c == '\0') {
        report_err("there's no matching underscore\n");
      }
      continue;
    }
  }
  printf("%s", story);
  free(story);
}

//this function is to add words to a catarray
catarray_t *carr_change(catarray_t *carr, const char *curr, const char *ptr) {
  carr->n++;
  carr->arr = realloc(carr->arr, carr->n * sizeof(*carr->arr));
  carr->arr[carr->n - 1].name = strndup(curr, ptr - curr);
  carr->arr[carr->n - 1].words = malloc(sizeof(*carr->arr[carr->n - 1].words));
  size_t len = strlen(ptr + 1);
  carr->arr[carr->n - 1].words[0] = strndup(ptr + 1, len - 1);
  carr->arr[carr->n - 1].n_words = 1;
  return carr;
}

//check if the pointer is NULL
void checkPtr(char * ptr,char * curr){
  if (ptr == NULL) {
    report_err("there's no colon\n");
  } 
}

/*This program should read from the file and 
  store the words into a catarray_t and print them using
  the provided function printWords.*/
catarray_t * step2(FILE *f) {
  char *curr = NULL;
  size_t sz = 0;
  catarray_t *carr = malloc(sizeof(*carr));
  carr->n = 0;
  carr->arr = malloc(sizeof(*carr->arr));
  while (getline(&curr, &sz, f) >= 0) {
    char *ptr = strchr(curr, ':');
    // error if : doesn't exist
    checkPtr(ptr,curr);
    // cut the first part before : as name
    char *part1 = strndup(curr, ptr - curr);
    // check if there is the same category before
    int nothave_name = 1;
    for (size_t i = 0; i < carr->n; i++) {
      // arr[i] is a pointer or category
      if (strcmp(carr->arr[i].name, part1) == 0) {
        carr->arr[i].n_words++;
        size_t end = carr->arr[i].n_words - 1;
        // realloc the space of words to add one more word
        carr->arr[i].words = realloc(carr->arr[i].words,
                                     (end + 1) * sizeof(*carr->arr[i].words));
        // put the new word to the end of words
        size_t len = strlen(ptr + 1);
        carr->arr[i].words[end] = strndup(ptr + 1, len - 1);
        nothave_name = 0;
        continue;
      }
    }
    free(part1);
    // create a new category and put it into catarray carr
    if (nothave_name) {
      carr = carr_change(carr, curr, ptr);
      nothave_name = 1;
    }
  }
  free(curr);
  return carr;
}

//update the array of previous words
char **prev_change(char **prev, size_t prev_l, const char *cat) {
  prev = realloc(prev, prev_l * sizeof(*prev));
  prev[prev_l - 1] = strdup(cat);
  return prev;
}
//update the story
char *s_change(char *story, size_t i, const char *cat) {
  story = realloc(story, (i + 1) * sizeof(*story));
  story = strcat(story, cat);
  story[i] = '\0';
  return story;
}

//remove the used word from it catagory
catarray_t * rm_word(catarray_t * carr, int k, const char * cat) {
  size_t j = 0;//length of new words
  char ** new_wds = malloc(sizeof(*new_wds));//create a new words
  for (size_t i = 0; i < carr->arr[k].n_words; i++) {
    if (strcmp(carr->arr[k].words[i], cat) != 0) {
      j++;
      new_wds=realloc(new_wds,j*sizeof(*new_wds));
      new_wds[j-1] = strdup(carr->arr[k].words[i]);
    }
  }
  for(size_t m = 0;m<carr->arr[k].n_words; m++){
    free(carr->arr[k].words[m]);
  }
  free(carr->arr[k].words);//free old words
  carr->arr[k].words = new_wds;
  carr->arr[k].n_words = j; //update number of word
  return carr;
}

//update prv_ct and story
char * update_ps(category_t * prv_ct,char *story,size_t i,const char * cat){
  story = s_change(story, i, cat);
  prv_ct->n_words++;
  prv_ct->words = prev_change(prv_ct->words, prv_ct->n_words, cat);
  return story;
}

//free the catagory_t
void free_catag(category_t * prv_ct){
  for (size_t st = 0; st <prv_ct->n_words; st++) {
    free(prv_ct->words[st]);
  }
  free(prv_ct->words);
  free(prv_ct);
}

//check if the char c is equal to '\n' or '\0'
void checkC(char c){
  if (c == '\n' || c == '\0') {
    report_err("there's no matching underscore\n");
  }
}

//this function parses the story to replace blank with word
void step3_parse(FILE *f, catarray_t *carr, int ifremove) {
  int c;
  size_t i = 0; // length of the new story
  char *story = malloc(sizeof(*story));
  story[0]='\0';
  category_t * prv_ct = malloc(sizeof(*prv_ct));
  prv_ct->name = NULL;
  prv_ct->n_words=0;
  prv_ct->words = malloc(sizeof(*prv_ct->words));
  while ((c = fgetc(f)) != EOF) {
    // meet the first "_"
    if (c == '_') {
      char *blank = malloc(sizeof(*blank)); 
      int ifvalid = 0;
      blank[0] = '\0';// string in the blank
      size_t j = 0;
      // enter a blank
      while ((c = fgetc(f)) != EOF) {
        if (c == '_') {
          break;
        }
        // check if there isn't a matching underscore in the same line
        checkC(c);
        j = j + 1;
        blank = story_change(blank, j, c);
      }
      if (blank[0] >= 48 && blank[0] <= 57 && j == 1) {
        int num = atoi(blank);
        if(num > prv_ct->n_words||num<=0){
          report_err("there is not a valid integer\n");
        }
        size_t pos = prv_ct->n_words - num; // index of the reused word
        // reuse previous word, update story and prev
        i = i + strlen(prv_ct->words[pos]);
        story = update_ps(prv_ct,story,i,prv_ct->words[pos]);
        ifvalid = 1;
        free(blank);
      } else {
        for (size_t k = 0; k < carr->n; k++) {
	  //find the same name before
          if (strcmp(carr->arr[k].name, blank) == 0) {
            const char *cat = chooseWord(carr->arr[k].name, carr);
            //use the randomly chosen word and update story and prev
            i = i + strlen(cat);
            story = update_ps(prv_ct,story,i,cat);
            ifvalid = 1;
            if (ifremove) {
              carr = rm_word(carr, k, cat);
            }
            free(blank);
            break;
          }
        }  
      }
      //if there's no valid word to replace the blank
      if(!ifvalid){
        report_err("there is not a valid catagory name\n");
      }
    } else {
      i = i + 1;
      story = story_change(story, i, c);
    }
  }
  free_catag(prv_ct);
  printf("%s", story);
  free(story);
}

//free space malloced by catarray_t * carr
void free_carr(catarray_t * carr){
  for (size_t i = 0; i < carr->n; i++) {
    for (size_t j = 0; j < carr->arr[i].n_words; j++) {
      free(carr->arr[i].words[j]);
    }
    free(carr->arr[i].words);
    free(carr->arr[i].name);
  }
  free(carr->arr);
  free(carr);
}

//take two stream and print the correct story
void step3_4(FILE *f, FILE *temp, int ifremove) {
  catarray_t *carr = step2(temp);
  step3_parse(f, carr, ifremove);
  free_carr(carr);
}

//open a file
FILE * tryop(char * arg){
  FILE * f = fopen(arg, "r");
  if (f == NULL) {
    report_err("Could not open file");
  }
  return f;
}

//close a file
void trycls(FILE *f){
  if (fclose(f) != 0) {
    report_err("Failed to close the input file!");
  }
}

//report error
void report_err(const char * report){
  fprintf(stderr,"%s", report);
  exit(EXIT_FAILURE);
}

