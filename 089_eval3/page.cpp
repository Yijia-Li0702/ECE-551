#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <page.h>



void Page::setendwin(std::ifstream & infile){
    std::string str;
    if(!infile.eof()){
      //get the first line of infile
      getline(infile,str);
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
  }
  
  void Page::readPage(std::ifstream & infile){
    //justify if it's option
    bool ifoption = true;
    std::string str;
    size_t colon;
    //if there are options
    while(!infile.eof()){
       getline(infile,str);
        if(str.front()=='#'){
          ifoption = false;
          continue;
        }
        //if this line is an option
        if(isoption){
          if(!endPage){
            if ((colon = str.find_first_of(":")) == std::string::npos) {
              std::cerr << "Invalid option!" << std::endl;
              exit(EXIT_FAILURE);
            }
            //copy the text of option to a new string
            str::string optiontext = substr(colon+1);
            str::string pagenum = substr(0, colon);
            //convert the number of page to unsigned int
            unsigned num = std::stoul(pagenum);
            option.push_back(optiontext);
            numoption.insert(optiontext,num);    
          }  
      } else {
        text+=str;
        }
      }  
  }
  
  void Page::printPage(){
    //print the text of the page
    std::cout << text << std::endl;
    std::cout << "\n" <<std::endl;
    if(endpage){
      if(worl){
        std::cout << "Congratulations! You have won. Hooray!" <<std::endl;
      } else {
        std::cout << "Sorry, you have lost. Better luck next time!" <<std::endl;
      }
    } else {
      std::cout << "What would you like to do?\n" <<std::endl;
      std::cout << "\n" <<std::endl;
      for(size_t i = 0; i<option.size();i++){
        std::cout << i << ". " << option[i] << "\n"<<std::endl;
      }  
    }
  }