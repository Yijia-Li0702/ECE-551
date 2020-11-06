#include "rand_story.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
  if (argc < 3) {
    fprintf(stderr, "not enough input error\n");
    return EXIT_FAILURE;
  }
  int ifremove;
  FILE * f;
  FILE * temp;
  if(argc == 3){
    ifremove = 0;
    f = fopen(argv[2], "r");
    temp = fopen(argv[1],"r");
  } else if(argc == 4){
    ifremove = 1;
    //check if the second argument isn't -n???????
    f = fopen(argv[3], "r");
    temp = fopen(argv[2],"r");
  }
  if (f == NULL || temp == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  step3_4(f,temp,ifremove);
   
  int i = fclose(f);
  int j = fclose(temp);
  if (i != 0||j!=0) {
    fprintf(stderr, "Failed to close the input file!");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
