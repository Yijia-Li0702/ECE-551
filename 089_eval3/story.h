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
  Story():pages(){}
  
  //open each page in a file and put it into pages
  bool openPage(char * filename, int i){
    std::string pagename = std::string(filename) + "//page"+std::to_string(i)+".txt";
    const char * n = pagename.c_str();
    std::ifstream ifs;
    ifs.open(n,std::ifstream::in);
    if(ifs.fail()){
      if(i == 1){
        std::cerr<<"there is no page1.txt";
        exit(EXIT_FAILURE);
      }else{
        return false;
      }
    }
    Page p;
    p.inipage(n); 
    pages.push_back(p); 
    //p.printPage();
    ifs.close();
    return true;
  }
  
  //take the name of a story as input, create an object story, read each page, 
  void openStory(char * filename){
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
  
  bool checkValid_4(){
    size_t szpages = pages.size();
    //int myarr[szpages]={0}; 
    std::vector<int> myarr(szpages,0);
    bool checkwin = false;
    bool checklose = false;
    size_t numofpage = szpages+1;
    //bool checkValid = true;
    std::vector<Page>::iterator it = pages.begin();
    //check each page
    while(it!=pages.end()){
      //check each option of one page
      for(size_t i = 0; i < it->numofop.size(); i++){
       //check if page is referenced is valid
        if(it->numofop[i] > numofpage || it->numofop[i]<=0){
          //checkValid = false;
          return false;
        }
        myarr[it->numofop[i]-1] = 1;
      }
      //check if there's at least one page is win and lose
      //if(it->getifwin()&&it->getendPage()){
      if(it->ifwin&&it->endPage){
        checkwin = true;
      }
      //if((!it->getifwin())&&it->getendPage()){
      if((!it->ifwin)&&it->endPage){
        checklose = true;
      } 
      ++it;
    }
    //check if all pages are referred
    for(size_t i = 1;i<pages.size();i++){
      if(myarr[i] != 1){
        return false;
      }
    }
    return checklose && checkwin;
  }
  
  void ifnum(std::string pagenum){
    for(size_t i=0; i < pagenum.size();i++){
      if(!isdigit(pagenum[i])){
         std::cerr<<"invalid page number 1" << std::endl;
         exit(EXIT_FAILURE);
      }
    }
  }
  
  void display_5(){
    Page curr = pages[0]; 
    curr.printPage();
    while(true){
      std::string input;
      getline(std::cin, input);
      ifnum(input);
      unsigned num = std::stoul(input);
      if(num <=0 || num > curr.option.size()){
        std::cout << "That is not a valid choice, please try again" <<std::endl;
        continue;
      }
      std::string slct_page = curr.option[num-1];
      int curr_num = curr.numoption[slct_page];
      curr = pages[curr_num-1];
      curr.printPage();
      if(curr.endPage){
        //exit(EXIT_SUCCESS);
        return;
      } 
    } 
  }
  

};