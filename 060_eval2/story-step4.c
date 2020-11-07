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
  //check if there's -n in argument
  if(argc == 3){
    ifremove = 0;
    f = tryop(argv[2]);
    temp = tryop(argv[1]);
  } else if(argc == 4){
    ifremove = 1;
    //check if the second argument is -n
    if(strcmp(argv[1],"-n")!=0){
      report_err("invalid command line argument\n");
    }
    f = tryop(argv[3]);
    temp = tryop(argv[2]);
  }
  step3_4(f,temp,ifremove);
  //close file
  trycls(f);
  trycls(temp);
  return EXIT_SUCCESS;
}
