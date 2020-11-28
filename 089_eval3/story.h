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
  //the first is the page num the second is num of option
  std::set<std::pair<unsigned,unsigned>> sucPath;
public:
  Story():pages(),reachPage(),sucPath(){}
  bool openPage(char * filename, int i);
  void openStory(char * filename);
  bool checkValid_4();
  void ifnum(std::string pagenum);
  void display_5();
  void setReachP();
  void printUnreach();
  void findSucPath();
  void traceBack(unsigned pagenum);
  void printSucPath();
};