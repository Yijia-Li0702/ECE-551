#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned power(unsigned x, unsigned y){
  if(x == 0 && y == 0){
    return 1;
  }
  if(y == 0){
    return 1;
  }
  if(y == 1){
    return x;
  }
  if(y > 1){
    return x * power(x,y--);
  }
  /*else if(y < 1 && y >= 0){
    return pow(x,y);
  }else if(y < 0){
    x = 1 / x;
    return power(x, -y);
  }*/
  
}
/*void run_check(unsigned x, unsigned y, unsigned expected_ans){
  if(power(x,y) != expected_ans){
    printf("you are wrong!");
    exit(EXIT_FAILURE);
  }
}


int main(void){
  run_check(-1,2,1);
  run_check(-2,-1,-0.5);
  run_check(-2,0,1);
  run_check(1000,2,1000000);
  run_check(2,0.5,sqrt(2));
  run_check(0,0,1);
  run_check(-1,-1,-1);
  run_check(0.4,1,0.4);
  return EXIT_SUCCESS;
}
*/
