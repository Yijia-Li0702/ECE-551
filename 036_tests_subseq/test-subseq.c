#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);

void run_check(int * array, size_t n, size_t expected_ans){
  if(maxSeq(array, n) != expected_ans){
     printf("you are wrong!");
     exit(EXIT_FAILURE);
  }
}

int main(void){

  int array1[] = {};
  run_check(array1, 0, 0);
  
  int array4[10] = {2, 4, 2, 3, 6, 8, 1, 3, 5, 8};
  run_check(array4, 10, 4);

  int array2[4] = {-4, -2, 0, -2};
  run_check(array2, 4, 3);

  int array3[1] = {1};
  run_check(array3, 1, 1);

  int array5[20] = {99, 2000, 1999, 3001, 4000, 5000, 7000, 2, 4, 5, 2, 15, 2, 4, 7, 1, 1, 17, 4};
  run_check(array5, 20, 5);

  int array6[6] = {-5, -5, 0, 1, 4, 4};
  run_check(array6, 6, 4);

  int array7[8]={-2,-2,-3,-2,-1,0,1,1};
  run_check(array7,8,5);
  
  return EXIT_SUCCESS;
}
