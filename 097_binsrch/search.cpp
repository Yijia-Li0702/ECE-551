#include <math.h>
#include <cstdio>
#include <cstdlib>

#include "function.h"

int binarySearchForZero(Function<int, int> * f, int low, int high){
   if(f->invoke(high) <= 0){
     return high-1;
   }
   if(f->invoke(low) >= 0){
     return low;
   }
   int mid = (low+high)/2;
   printf("%d\n",mid);
   int val = f->invoke(mid);
   if( val == 0){
     return mid;
   }
   if(low == high || low == high - 1){
     return low;
   }
   if(val < 0){
     //printf("%d\n",mid);
     return binarySearchForZero(f, mid, high); 
   } else {
   //printf("%d\n",mid);
     return binarySearchForZero(f, low, mid);
   }  
 }
