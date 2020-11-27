#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include "readFreq.h"

void printSym(std::ostream & s, unsigned sym) {
  if (sym > 256 ) {
    s << "INV";
  }
  else if (sym == 256) {
    s << "EOF";
  }
  else if (isprint(sym)) {
    char c = sym;
    s << "'" << c << "'";
  }
  else {
    std::streamsize w = s.width(3);
    s << std::hex << sym << std::dec;
    s.width(w);
  }
}
uint64_t * readFrequencies(const char * fname) {
  //WRITE ME!
  std::ifstream ifs;
  ifs.open(fname, std::ifstream::in);
  if(ifs.fail()){
    std::cerr<<"can't open the file";
    exit(EXIT_FAILURE);
  }
  uint64_t * arr = new uint64_t[257]();
   int c;
  while((c = ifs.get())!=EOF){
   
    arr[c]++;
  }
  arr[256] = 1;
  ifs.close();
  return arr;
}

//uint64_t * readFrequencies(const char * fname) {
//  uint64_t * ans = new uint64_t[257]();
//  std::ifstream file;
//  file.open(fname);
//  int ind;
//  while ((ind = file.get()) != EOF) {
//    ans[ind]++;
//  }
//  ans[256] = 1;
//  file.close();
//  return ans;
//}

