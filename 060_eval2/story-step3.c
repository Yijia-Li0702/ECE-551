#include "rand_story.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
  if (argc != 3) {
    fprintf(stderr, "not enough input error\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  //FILE * temp = fopen(argv[2],"r");
  
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  store(f);
  
  if (fclose(f) != 0) {
    fprintf(stderr, "Failed to close the input file!");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
