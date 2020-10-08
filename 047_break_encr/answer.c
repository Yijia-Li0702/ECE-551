#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int max(int* a){
  int max_num=0;
  int max_ind = 0;
  for(int i = 0;i<26;i++){
    if(a[i]>max_num){
      max_num = a[i];
      max_ind = i;
    }
  }
  return max_ind+97;
  
}

int decrypt(FILE * f){
  int c;
  int a[26]={0,0,0,0};
  while ((c = fgetc(f)) != EOF) {
    if(isalpha(c)) {
      a[c-97]++;
    }
  }
  int ans = max(a);
  return ans;
}



int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }

  int max_ind = decrypt(f);
  int key;
  if(max_ind >= 101){
    key = max_ind - 101;
  } else {
    key = 26 +max_ind -101;

  }
  fprintf(stdout, "%d\n",key);
  /*if(max_ind>=0){
    fprintf(stdout,"%c\n",max_ind);
  } else {
    fprintf(stderr,"Couldn't find e");
    return EXIT_FAILURE;
  }*/

  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
