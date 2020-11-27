#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
//#include "page.h"
#include "story.h"

int main(int argc, char ** argv){
  if (argc != 2) {
    fprintf(stderr, "not enough input error\n");
    return EXIT_FAILURE;
  }
  Story s;
  s.openStory(argv[1]);
  if(!s.checkValid_4()){
    std::cerr<<"invalid story" << std::endl;
    exit(EXIT_FAILURE);
  }
  s.display_5();
  return EXIT_SUCCESS;
}