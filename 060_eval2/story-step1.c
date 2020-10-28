#include "rand_story.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "not enough input error\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  char * story = malloc(sizeof(*story));
  catarray_t * cats = NULL;
  parse(f,story,cats);
  printf("%s\n",story);
  free(story);
  
  return EXIT_SUCCESS;
}
  
