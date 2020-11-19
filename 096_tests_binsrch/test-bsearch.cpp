#include <math.h>

#include <cstdio>
#include <cstdlib>

#include "function.h"

int binarySearchForZero(Function<int, int> * f, int low, int high);

class SinFunction : public Function<int, int> {
 public:
  virtual int invoke(int arg) { return 10000000 * (sin(arg / 100000.0) - 0.5); }
};

class CountedIntFn : public Function<int, int> {
 protected:
  unsigned remaining;
  Function<int, int> * f;
  const char * mesg;

 public:
  CountedIntFn(unsigned n, Function<int, int> * fn, const char * m) :
      remaining(n),
      f(fn),
      mesg(m) {}
  virtual int invoke(int arg) {
    if (remaining == 0) {
      fprintf(stderr, "Too many function invocations in %s\n", mesg);
      exit(EXIT_FAILURE);
    }
    remaining--;
    return f->invoke(arg);
  }
};

void check(Function<int,int> * f,
           int low,
           int high,
           int expected_ans,
           const char * mesg){
          
           //unsigned n = high > low ? log(2*(high-low)) + 1:1;
           int n=high > low ? log(high - low) / log(2) + 1 : 1;
           CountedIntFn* c = new  CountedIntFn(n,f,mesg);
           int ans = binarySearchForZero(c,low,high);
           if(ans != expected_ans){
             fprintf(stderr, "Wrong Answer in %s\n", mesg);
             exit(EXIT_FAILURE);
           }
           
           
           }
           

int main() {
  SinFunction sin;
  check(&sin, 0, 80000, 52359, "sin1");
  check(&sin, 0, 52360, 52359, "sin1");
  check(&sin, 0, 52359, 52358, "sin1");
  check(&sin, 52359, 80000, 52359, "sin1");
  check(&sin, 0, 52359 * 2 - 1, 52359, "sin1");
    check(&sin, 52358, 52359, 52358, "sin1");
  check(&sin, 52359, 52359, 52359, "sin1");

  return EXIT_SUCCESS;
}
