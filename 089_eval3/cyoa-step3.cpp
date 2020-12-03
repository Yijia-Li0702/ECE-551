#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include "story.h"


int main(int argc, char ** argv){
  if (argc != 2) {
    std::cerr<< "not enough input error"<<std::endl;
    return EXIT_FAILURE;
  }
  Story s;
  s.openStory(argv[1]);
  if(!s.checkValid_4()){
    s.report_err("invalid story");
  }
  s.setReachP();
  s.printUnreach();
  return EXIT_SUCCESS;
}
