#ifndef __RAND_STORY_H__
#define __RAND_STORY_H__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "provided.h"

//any functions you want your main to use
char * story_change(char * story,size_t i,char c);
void step1(FILE * f, catarray_t * cats);
catarray_t * carr_change(catarray_t * carr,const char * curr,const char * ptr);
catarray_t * step2(FILE *f);
char** prev_change(char** prev, size_t prev_l,const char * cat);
char * s_change(char * story,size_t i,const char * cat);
catarray_t * rm_word(catarray_t * carr, int k, const char * cat);
void step3_parse(FILE * f,catarray_t * carr, int ifremove);
void free_carr(catarray_t * carr);
void step3_4(FILE * f, FILE * temp, int ifremove);

#endif
//put free to function 
//put open file to function 
