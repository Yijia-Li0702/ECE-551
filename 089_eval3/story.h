#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include "page.h"

class Story {
private:
  std::vector<Page> pages;
public:
  story():pages<Page>(){}
  bool Story::openPage(cahr * filename, int i){
    std::string pagename = std::string(filename) + "//page"+std::to_string(i)+".txt";
    const char * n = pagename.c_str();
    std::ifstream ifs;
    ifs.open(n,std::ifstream::in);
    if(ifs.fail()){
      if(i = 1){
        std::cerr<<"there is no page1.txt";
        exit(EXIT_FAILURE);
      }else{
        return false;
      }
    }
    Page p;
    p.setendwin(n);
    p.readPage(n); 
    pages.insert(p); 
    p.printPage();
    ifs.close();
    return true;
  }
  
  //take the name of a story as input, create an object story, read each page, 
  void Story::openStory(char * filename){
    unsigned i = 1;
    //if the file exist
    bool ifexist;
    ifexist = openPage(filename, i);
    i++;
    while(ifexist){
      ifexist = openPage(filename, i);
      i++;
    }
  }
  
  bool checkwandl(){
    bool checkwin = false;
    bool checklose;
    std::vector::iterator it = pages.begin();
    while(it!=pages.end()){
      if(*it.getifwin()&&*it.getendPage()){
        checkwin = true;
      }
      
      if((!*it.getifwin())&&*it.getendPage()){
        checklose = true;
      }
      ++it;
    }
    return checklose && checkwin;
  }
  

}