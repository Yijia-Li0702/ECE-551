#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include "page.h"

int main(int argc, char ** argv){
  if (argc != 2) {
    fprintf(stderr, "not enough input error\n");
    return EXIT_FAILURE;
  }
  Page p;
  p.setendwin(argv[1]);
  p.readPage(argv[1]);
  p.printPage();
  

}