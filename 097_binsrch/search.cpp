#include <cstdlib>

#include "function.h"

int binarySearchForZero(Function<int, int> * f, int low, int high) {
    if(low == high || low == high - 1){
     return low;
   }
  
  while (low + 1 < high) {

    int mid = (low + high) / 2;
    int val = f->invoke(mid);
    if (val == 0) {
      return mid;
    }
    if (val < 0) {
      low = mid;
    }
    else {
      high = mid;
    }
  }
  return low;
}