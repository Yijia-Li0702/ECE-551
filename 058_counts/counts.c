#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * c = malloc(sizeof(*c));
  c->arr = NULL;
  c->sz = 0;
  c->unknown = 0;
  return c;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name == NULL){
    c->unknown++;
  } else {
    int new = 1;
    for(size_t i = 0; i<c->sz;i++){
      if(strcmp(c->arr[i].c,name)==0){
	new = 0;
	c->arr[i].len++;
	break;
      }
    }
    if(new == 1){
      c->arr = realloc(c->arr,(c->sz+1)*sizeof(*c->arr));
      c->arr[c->sz].c = strdup(name);
      c->arr[c->sz].len = 1;
      c->sz++;
    }
  }
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(size_t i = 0;i < c->sz;i++){
    fprintf(outFile,"%s: %d\n",c->arr[i].c,c->arr[i].len);
  }
  if(c->unknown > 0){
    fprintf(outFile,"<unknown>: %d\n",c->unknown);
  }
  
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(size_t i = 0;i < c->sz;i++){
    free(c->arr[i].c);
  }
  free(c->arr);
  free(c); 
}
