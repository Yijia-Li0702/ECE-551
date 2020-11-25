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
  //std::set<std::pair<bool, Page>> reachPage;
  //std::set<Page> reachPage;
  std::set<unsigned> reachPage;
public:
  Story():pages(),reachPage(){}
  bool openPage(char * filename, int i);
  void openStory(char * filename);
  bool checkValid_4();
  void ifnum(std::string pagenum);
  void display_5();
  void setReachP();
  void printUnreach();
  

};