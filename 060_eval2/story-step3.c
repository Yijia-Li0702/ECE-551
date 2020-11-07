#include "rand_story.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
  if (argc != 3) {
    fprintf(stderr, "not enough input error\n");
    return EXIT_FAILURE;
  }
  FILE * f =  tryop(argv[2]);
  FILE * temp =  tryop(argv[1]);
  
  int ifremove = 0;
  step3_4(f,temp,ifremove);  
  trycls(f);
  trycls(temp);
  return EXIT_SUCCESS;
}
