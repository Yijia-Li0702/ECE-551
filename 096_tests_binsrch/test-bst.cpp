#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstdio>
#include <assert.h>

#include "function.h"

int binarySearchForZero(Function<int, int> * f, int low, int high);

class CountedIntFn : public Function<int,int>{
protected:
  unsigned remaining;
  Function<int,int> * f;
  const char * mesg;
public:
  CountedIntFn(unsigned n, Function<int,int> * fn, const char * m): 
  remaining(n), f(fn), mesg(m) {}
  
  virtual int invoke(int arg) {
    if (remaining == 0) {
      fprintf(stderr,"Too many function invocations in %s\n", mesg);
      exit(EXIT_FAILURE);
    }
    remaining--;
    return f->invoke(arg);
  }

};

class SinFunction : public Function<int, int> {
public:
  virtual int invoke(int arg) {
    return 10000000 * (sin(arg/100000.0) - 0.5);
  }
};

void check(Function<int,int> * f,
           int low,
           int high,
           int expected_ans,
           const char * mesg){
          
           unsigned n = high > low ? log(2*(high-low)) + 1;
           CountedIntFn* c = new  CountedIntFn(n,f,m);
           int ans = binarySearchForZero(c,low,high);
           if(n != expected_ans){
             fprintf(stderr, "Wrong Answer in %s\n", mesg);
             exit(EXIT_FAILURE);
           }
           
           
           }



int main() {
  SinFunction * sin = new SinFunction();
  check(sin, 0, 150000,52359,"test1");
  return EXIT_SUCCESS;
}