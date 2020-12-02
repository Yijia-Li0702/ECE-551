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

//to set if the page is endpage and win/lose
  void Page::setendwin(const char * filename){
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
  
  //try to open a page
  std::ifstream Page::tryopen(const char * filename){
    std::ifstream ifs;
    ifs.open(filename,std::ifstream::in);
    if(ifs.fail()){
      report_err("can't open the file");
    }
    return ifs;
  }
  
  //report error and exit
  void Page::report_err(const char * report){
     std::cerr<<report<< std::endl;
     exit(EXIT_FAILURE);
  }
  
  //check if the string is a number
  void Page::ifnum(std::string pagenum){
    for(size_t i = 0; i < pagenum.size();i++){
      if(!isdigit(pagenum[i])){
         report_err("invalid page number 1");
      }
    }
  }
  
  //read one Page and initialize some fields
  void Page::readPage(const char * filename){
    std::ifstream ifs = tryopen(filename);
    //if this line is an option
    bool ifoption = true;
    std::string str;
    size_t colon;
    while(!ifs.eof()){
       getline(ifs,str);
       //if this line is #
        if(str[0] == '#'){
          ifoption = false;
          //check if there is option
          if(option.size()==0&&!endPage){
              report_err("There's no option!");
          }
          continue;
        }
        //if this line is an option
        if(ifoption){
          if(!endPage){
           //if there's no :
            colon = str.find_first_of(":");
            if (colon == std::string::npos || colon == 0) {
              report_err("there is no :");
            }
            //copy the text of option to a new string
            std::string optiontext = str.substr(colon+1);
            std::string pagenum = str.substr(0, colon);
            //check if content before : is a number 
            this->ifnum(pagenum);
            //convert the number of page to unsigned int
            unsigned num = std::stoul(pagenum);
            if(num<=0){
              report_err("Invalid page number 2!");
            }
            //put value into containers
            numofop.push_back(num);
            option.push_back(optiontext);
            numoption.insert({optiontext,num});    
          }  
      } else {
        //write text
        text+=str;
        text+="\n";
        }
      } 
    ifs.close(); 
  }
  
  //print a page
  void Page::printPage(){
    //print the text of the page
    std::cout << text ;
    //print option of a page
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
  
  //initialzie a page
  void Page::inipage(const char * filename){
    setendwin(filename);
    readPage(filename);
  }
  
  
  //get function
   bool Page::getifwin(){
    return ifwin;
  }
  
  bool Page::getendPage(){
    return endPage;
  }
  
  std::map<std::string,unsigned> Page::getnumoption(){
    return numoption;
  }
  std::vector<std::string> Page::getoption(){
    return option;
  }
  std::vector<unsigned> Page::getnumofop(){
    return numofop;
  }
  
  std::string Page::gettext(){
    return text;
  }
  
  
