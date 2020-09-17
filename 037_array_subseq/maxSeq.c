#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
  if(n == 0){
    return 0;
  }
  size_t len=1;
  // int max = array[0];
  size_t mlen=1;
  for(size_t i = 1;i < n; i++){
    if(array[i]>array[i-1]){
      len++;
      if(len > mlen){
	mlen = len;
      }
    } else {
	len = 1;
      }
    }
    return mlen;
}

