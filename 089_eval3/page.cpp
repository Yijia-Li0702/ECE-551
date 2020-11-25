#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "page.h"

void Page::setendwin(const char * filename){
 // void Page::setendwin(std::ifstream ifs){
    std::ifstream ifs = tryopen(filename);
    std::string str;
    if(!ifs.eof()){
      //get the first line of infile
      getline(ifs,str);
      //std::cout << str<<std::endl;
    }
    if(str == "LOSE"){
      endPage = true;
      ifwin = 0;
    } else if(str == "WIN"){
      endPage = true;
      ifwin = 1;
    } else {
      endPage = false;
      ifwin = 0;
    }
    ifs.close();
  }
  
  std::ifstream Page::tryopen(const char * filename){
    std::ifstream ifs;
    ifs.open(filename,std::ifstream::in);
    if(ifs.fail()){
     std::cerr<<"can't open the file";
      exit(EXIT_FAILURE);
    }
    return ifs;
  }
  
  void Page::ifnum(std::string pagenum){
    for(size_t i = 0; i < pagenum.size();i++){
      if(!isdigit(pagenum[i])){
         std::cerr<<"invalid page number 1" << std::endl;
         exit(EXIT_FAILURE);
      }
    }
  }
  
  void Page::readPage(const char * filename){
 //void Page::readPage(std::ifstream ifs){
    std::ifstream ifs = tryopen(filename);
    //if this line is an option
    bool ifoption = true;
    std::string str;
    size_t colon;
    while(!ifs.eof()){
       getline(ifs,str);
        if(str[0] == '#'){
          ifoption = false;
          //check if there is option
          if(option.size()==0&&!endPage){
            std::cerr << "There's no option!" << std::endl;
              exit(EXIT_FAILURE);
          }
          continue;
        }
        //if this line is an option
        if(ifoption){
          if(!endPage){
           //if there's no :
            colon = str.find_first_of(":");
            if (colon == std::string::npos || colon == 0) {
              std::cerr << "there is no :" << std::endl;
              exit(EXIT_FAILURE);
            }
            //copy the text of option to a new string
            std::string optiontext = str.substr(colon+1);
            std::string pagenum = str.substr(0, colon);
            //check if content before : is a number 
            this->ifnum(pagenum);
            //convert the number of page to unsigned int
            unsigned num = std::stoul(pagenum);
            if(num<=0){
              std::cerr << "Invalid page number 2!" << std::endl;
              exit(EXIT_FAILURE);
            }
            numofop.push_back(num);
            option.push_back(optiontext);
            numoption.insert({optiontext,num});    
          }  
      } else {
        text+=str;
        text+="\n";
        }
      } 
    ifs.close(); 
  }
  

  void Page::printPage(){
    //print the text of the page
    std::cout << text ;
    if(endPage){
      if(ifwin){
        std::cout << "Congratulations! You have won. Hooray!" <<std::endl;
      } else {
        std::cout << "Sorry, you have lost. Better luck next time!" <<std::endl;
      }
    } else {
      std::cout << "What would you like to do?\n" <<std::endl;
      for(size_t i = 1; i<=option.size();i++){
        std::cout << " "<<i << ". " << option[i-1] <<std::endl;
      }  
    }
  }
  
  void Page::inipage(const char * filename){
    setendwin(filename);
    readPage(filename);
  }
  
  
