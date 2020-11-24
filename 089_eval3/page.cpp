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
    std::ifstream ifs;
    ifs.open(filename,std::ifstream::in);
    if(ifs.fail()){
     std::cerr<<"can't open the file";
    }
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
  
  void Page::readPage(const char * filename){
 //void Page::readPage(std::ifstream ifs){
    std::ifstream ifs;
    ifs.open(filename,std::ifstream::in);
    if(ifs.fail()){
     std::cerr<<"can't open the file";
    }
    //justify if it's option
    bool ifoption = true;
    std::string str;
    size_t colon;
    //if there are options
    while(!ifs.eof()){
       getline(ifs,str);
        //if(str.front()=='#'){
        if(str[0] == '#'){
          ifoption = false;
          continue;
        }
        //if this line is an option
        if(ifoption){
          if(!endPage){
            if ((colon = str.find_first_of(":")) == std::string::npos) {
              std::cerr << "Invalid option!" << std::endl;
              exit(EXIT_FAILURE);
            }
            //copy the text of option to a new string
            std::string optiontext = str.substr(colon+1);
            std::string pagenum = str.substr(0, colon);
            //convert the number of page to unsigned int
            unsigned num = std::stoul(pagenum);
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
        std::cout << i << ". " << option[i-1] <<std::endl;
      }  
    }
  }
  
  void Page::openPage(char * filename){
    unsigned i = 1;
    while(true){
      std::string pagename = std::string(filename) + "//page"+std::to_string(i)+".txt";
      std::cout<<pagename<<std::endl;
      const char * n = pagename.c_str(); 
      i++;
      std::ifstream ifs;
      ifs.open(n,std::ifstream::in);
      if(ifs.fail()){
        break;
      }
      Page p;
      p.setendwin(n);
      p.readPage(n);
       //p.setendwin(ifs);
      //p.readPage(ifs);
      p.printPage();
      ifs.close();
    }
 
}