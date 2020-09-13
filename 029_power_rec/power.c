#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned power(unsigned x, unsigned y){
  if(x == 0 && y == 0){
    return 1;
  }
  if(y == 1){
    return x;
  }
  if(y > 1){
    return x * power(x,y--);
  } else if(y < 1 && y >= 0){
    return pow(x,y);
  }else if(y < 0){
    x = 1 / x;
    return power(x, -y);
  }
  
}
