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
  catarray_t * carr = step2(f);
  printWords(carr);
  free_carr(carr);
  trycls(f);
  return EXIT_SUCCESS;
}
