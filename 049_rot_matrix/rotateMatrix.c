#include <stdio.h>
#include <stdlib.h>

void rotate(FILE * f){
  int a;
  int r =0;
  int c = 0;
  char m[10][10]={0};
  while ((c = fgetc(f)) != EOF) {
    if(a!='\n'){
      if(a < 0 || a >255){
	fprintf(stderr, "error\n");
	exit(EXIT_FAILURE);
      }
      if(r >= 10 || c >= 10){
	fprintf(stderr, "error\n");
	exit(EXIT_FAILURE);
      }
      m[r][c] = a;
      c++;
    } else{
      if(c != 10){
        fprintf(stderr, "error\n");
        exit(EXIT_FAILURE);
      }
      c = 0;
      r++;
      if(r > 10){
	fprintf(stderr, "error\n");
	exit(EXIT_FAILURE);
      }
    }
  }

  if(c != 10 || r!= 10){
    fprintf(stderr, "error\n");
    exit(EXIT_FAILURE);
  }
  for(int j = 0;j <10;j++){
    for(int i = 9; i > -1; i--){
      fprintf(stdout, "%c", m[i][j]);
    }
    fprintf(stdout, "\n");
  }
}

int main(int argc, char ** argv){
  if (argc != 2) {
    fprintf(stderr, "Usage:rotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  rotate(f);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

