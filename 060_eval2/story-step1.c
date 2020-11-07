#include "rand_story.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "not enough input error\n");
    return EXIT_FAILURE;
  }
  FILE * f = tryop(argv[1]);
  catarray_t * cats = NULL;
  step1(f,cats);
  trycls(f);
  return EXIT_SUCCESS;
}  
