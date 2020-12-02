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
   //std::ifstream ifs;
   //ifs.open(argv[1],std::ifstream::in);
   //if(ifs.fail()){
     //std::cerr<<"can't open the file";
    //}
  Page p;
  //p.setendwin(argv[1]);
  //p.readPage(argv[1]);
  p.inipage(argv[1]);
  p.printPage();
  //ifs.close();
  

}