#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <stack>
#include "story.h"

 //open each page in a file and put it into pages
  bool Story::openPage(char * filename, int i){
    //open the page
    std::stringstream ss;
    std::string num_str;
    ss<<i;
    ss>>num_str;
    //std::string pagename = std::string(filename) + "//page"+std::to_string(i)+".txt";
    std::string pagename = std::string(filename) + "//page"+num_str+".txt";
    const char * n = pagename.c_str();
    std::ifstream ifs;
    ifs.open(n,std::ifstream::in);
    if(ifs.fail()){
      //if there's no page1
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
    ifs.close();
    return true;
  }
  
  //take the name of a story as input, create an object of Story, read each page, 
  void Story::openStory(char * filename){
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
  
  //check if the story is valid
  bool Story::checkValid_4(){
    //the amount of pages
    size_t numofpage = pages.size();
    //index represents one page, and the item = 1 means it is referred
    std::vector<int> referred(numofpage,0);
    //if there is one page is win and lose
    bool checkwin = false;
    bool checklose = false;
    std::vector<Page>::iterator it = pages.begin();
    //check each page
    while(it!=pages.end()){
      //check each option of one page
      for(size_t i = 0; i < it->numofop.size(); i++){
       //check if page is referenced is valid
        if(it->numofop[i] > numofpage || it->numofop[i]<=0){
          std::cout << "invalid numofop checkValid_4" <<std::endl;
          return false;
        }
        //the page that it refers should be put to 1
        referred[it->numofop[i]-1] = 1;
      }
      //check if there's at least one page is win and lose
      if(it->ifwin&&it->endPage){
        checkwin = true;
      }
      if((!it->ifwin)&&it->endPage){
        checklose = true;
      } 
      ++it;
    }
    //check if all pages are referred except page1
    for(size_t i = 1;i<pages.size();i++){
      if(referred[i] != 1){
        std::cout << "there's no page refer to "<<i+1<<" checkValid_4" <<std::endl;
        return false;
      }
    }
    return checklose && checkwin;
  }
  
  //if the string is number, if not return false
  bool Story::ifnum(std::string pagenum){
    for(size_t i=0; i < pagenum.size();i++){
      if(!isdigit(pagenum[i])){
         return false;
      }
    }
    return true;
  }
  
  //report error
  void Story::report_err(const char * report){
     std::cerr<<report<< std::endl;
     exit(EXIT_FAILURE);
  }
  
  //display current page and let user to make choice
  void Story::display_5(){
    Page curr = pages[0]; 
    curr.printPage();
    while(true){
      //get user's choice
      std::string input;
      getline(std::cin, input);
      if(!ifnum(input)){
        std::cout << "That is not a valid choice, please try again" <<std::endl;
        continue;
      }
      //convert it into a number
      //unsigned num = std::stoul(input);
      unsigned num = atoi(input.c_str());
      if(num <=0 || num > curr.option.size()){
        std::cout << "That is not a valid choice, please try again" <<std::endl;
        continue;
      }
      //go to the chosen page
      std::string slct_page = curr.option[num-1];
      int curr_num = curr.numoption[slct_page];
      curr = pages[curr_num-1];
      curr.printPage();
      if(curr.endPage){
        return;
      } 
    } 
  }
  
  
  //get the reachabele page set
  void Story::setReachP(){
    //put page1 into set
    reachPage.insert(1);
    //check if there is new page reachable
    bool ifchange = 1;
    while(ifchange){
      ifchange = 0;
      //check all pages in reachable set
      std::set<unsigned>::iterator it = reachPage.begin();
      while(it != reachPage.end()){
        //if this page isn't checked
        Page curr = pages[*it-1];
        //check each choice of the page
        for(size_t i = 0; i < curr.numofop.size();i++){
            unsigned p_num = curr.numofop[i];
            if(reachPage.count(p_num)==0){
              reachPage.insert(p_num);
              ifchange = 1;
            }
          }
          ++it;
      }
    }
  }
  
  //print unreachable page
  void Story::printUnreach(){
    size_t szpages = pages.size();
    //std::cout << pages.size()<<std::endl;
    //check each page
     for(unsigned i = 1;i <= szpages;i++){
      if(reachPage.count(i)!=1){
        std::cout << "Page " << i <<" is not reachable"<<std::endl;
      }
   }
  }
  
  //check if there is a successful path
  bool Story::ifSucPathExist(){
    //iterate through the story's reachable set
    std::set<unsigned>::iterator it=reachPage.begin();
    while(it!=reachPage.end()){
      //find the page that is win
      if(pages[*it-1].getifwin()&&pages[*it-1].getendPage()){
        //sucPath.insert(std::pair<unsigned,unsigned>(*it,0));
        //traceBack(*it);
        return true;
      }
      ++it;
    }
    return false;
  }

  //get the successful path
  void Story::findSucPath(){
    std::stack<unsigned> tempS;
    pages[0].visited = true;
    tempS.push(1);
    while(!tempS.empty()){
      unsigned curr = tempS.top();
      std::vector<unsigned> numofop=pages[curr-1].getnumofop();
      tempS.pop();
      //iterate available page of curr
      for(unsigned i = 0;i<numofop.size();i++){
      unsigned pagenum = numofop[i];
      std::set<unsigned>::iterator itofnum=reachPage.find(pagenum);
      //check if the page is reachable
      if(itofnum!=reachPage.end()){
        if(!pages[pagenum-1].visited){
          pages[pagenum-1].visited=true;
          tempS.push(pagenum);
          //pages[pagenum-1].prevPage = std::pair<unsigned,unsigned>(curr,i+1);
          pages[pagenum-1].prevPage = std::make_pair(curr,i+1);
          if(pages[pagenum-1].getifwin()){
            traceBack(pagenum);
            //sucPath.insert(std::pair<unsigned,unsigned>(pagenum,pages.size()+1));
            sucPath.insert(std::make_pair(pagenum,pages.size()+1));
            return;
          }
        }
        }
      }
    }
  
  }
  
  //trace back from the win page
  void Story::traceBack(unsigned pagenum){
    if(pagenum ==  1){
      return;
      //sucPath.insert(pages[numofop[i]-1].prevPage);
    }
    //traceBack(std::get<0>(pages[pagenum-1].prevPage));
    traceBack(pages[pagenum-1].prevPage.first);
    //std::cout<<"trace "<<std::get<0>(pages[pagenum-1].prevPage)<<std::endl;
    sucPath.insert(pages[pagenum-1].prevPage);
    return;
  
  }

  //print successful path
  void Story::printSucPath(){
    std::set<std::pair<unsigned,unsigned> >::iterator it = sucPath.begin();
    //std::cout<<"size "<<sucPath.size()<<std::endl;
    while(it != sucPath.end()){
      //if(std::get<1>(*it) != pages.size()+1){
      if((*it).second != pages.size()+1){
        std::cout<<"Page "<<(*it).first<<" Choice "<<(*it).second<<std::endl;

      } else {
        std::cout<<"Page "<<(*it).first<<" WIN"<<std::endl;
      }
      ++it;
    }
  }
  
  //  void Story::findSucPath(){
//    //iterate through the story's reachablt set
//    std::set<unsigned>::iterator it=reachPage.begin();
//    while(it!=reachPage.end()){
//      //find the page that is win
//      if(pages[*it-1].getifwin()){
//      std::cout << "Page " << *it+1 <<std::endl;
//        sucPath.insert(std::pair<unsigned,unsigned>(*it,0));
//        traceBack(*it);
//        return;
//      }
//    }
//  }
  
//  void Story::traceBack(unsigned pagenum){
//    std::set<unsigned>::iterator it=reachPage.begin();
//    while(it!=reachPage.end()){
//      std::vector<unsigned> numofop=pages[*it-1].getnumofop();
//      std::vector<unsigned>::iterator itofnum=numofop.find(pagenum);
//      //if we can find pagename in the file's numofop
//     if(itofnum!=numofop.end()){
//     unsigned num = *it-numof.begin()+1;
//     std::cout << "Page " << i+1 <<std::endl;
//      sucPath.insert(std::pair<unsigned,unsigned>(*it,i+1));
//      if(*it != 1){
//          traceBack(*it);
//        }
//        return;
//        }
////     for(size_t i = 0;i<numofop.size();i++){
////       if(numofop[i] == pagenum){
////       std::cout << "Page " << i+1 <<std::endl;
////        sucPath.insert(std::pair<unsigned,unsigned>(*it,i+1));
////        if(*it != 1){
////          traceBack(*it);
////        }
////        return;
////       }
////      }
//    }
//    std::cout << "no succes path" << std::endl;
//    return;
//  }
//  
  
  
  