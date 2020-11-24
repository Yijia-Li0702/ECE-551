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
  //Page():text(NULL),option(NULL),endPage(false),ifwin(false){}
  Page():text(),option(),endPage(false),ifwin(false){}
  //void readPage(std::ifstream ifs);
  //void setendwin(std::ifstream ifs);
  void setendwin(const char * filename);
  void readPage(const char * filename);
  void printPage();
  void openPage(char * filename);
  
  
};