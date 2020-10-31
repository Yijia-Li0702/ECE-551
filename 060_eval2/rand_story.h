#ifndef __RAND_STORY_H__
#define __RAND_STORY_H__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "provided.h"

//any functions you want your main to use
char * story_change(char * story,size_t i,char c);
void parse(FILE * f, catarray_t * cats);
catarray_t * carr_change(catarray_t * carr,const char * curr,const char * ptr);
catarray_t * store(FILE *f);

#endif
