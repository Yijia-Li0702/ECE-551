#include <cstdlib>

#include "function.h"

int binarySearchForZero(Function<int, int> * f, int low, int high) {
  while (low + 1 < high) {
  if(low == high || low == high - 1){
     return low;
   }
   if (f->invoke(low) >= 0) {
    return low;
  }
  if (f->invoke(high - 1) <= 0) {
    return high - 1;
  }
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