#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>

class Page {
private:
  std::string text;
  std::vector<std::string> option;
  bool endPage;
  bool ifwin;
  //nextPage
  std::map<std::string,unsigned> numoption;
public:
  Page():text(NULL),option(NULL),endPage(false),worl(false){}
  void Page::setendwin(std::ifstream & infile);
  void Page::readPage(std::ifstream & infile);
  void Page::printPage();
  
  
};