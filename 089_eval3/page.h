#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>

class Page {
public:
  std::string text;
  std::vector<std::string> option;
  std::vector<unsigned> numofop;
  bool endPage;
  bool ifwin;
  //first unsigned is the prevpage, the second is its corresponding option
  std::pair<unsigned,unsigned> prevPage;
  bool visited;
  std::map<std::string,unsigned> numoption;
public:
  Page():text(),option(),numofop(),endPage(false),ifwin(false),prevPage(),visited(false),numoption(){}
  void setendwin(const char * filename);
  void readPage(const char * filename);
  void printPage();
  void inipage(const char * filename);
  std::ifstream tryopen(const char * filename);
  void ifnum(std::string pagenum);
  bool getifwin();
  bool getendPage();
  std::map<std::string,unsigned> getnumoption();
  std::vector<std::string> getoption();
  std::vector<unsigned> getnumofop();
  std::string gettext();
  void report_err(const char * report);
  ~Page(){}
  
};
  //Page():text(NULL),option(NULL),endPage(false),ifwin(false){}
  //bool openPage(char * filename);
  //void openStory(char * filename);
  //void readPage(std::ifstream ifs);
  //void setendwin(std::ifstream ifs);