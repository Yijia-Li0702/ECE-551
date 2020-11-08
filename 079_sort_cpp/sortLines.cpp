#include <algorithm>  //std::sort
#include <cstdlib>    //EXIT_SUCCESS
#include <fstream>    //std::ifstream
#include <iostream>   //std::cin std::cout std::ceer
#include <vector>     //std::vector

int main(int argc, char ** argv){
  if(argc==1){
    std::vector<std::string> str;
    std::string s;
    while(getline(std::cin,s)){
    str.push_back(s);
    }
    if(is.eof()!=1||is.good()!=1){
    error;}
    std::sort(str.begin(),str.end());
    std::vector::iterator it = str.begin();
    for(it != str.end()){
    std::cout <<*it<<std.endl;
    ++it;
    }
    }
    else if(argc == 2){
    std::vector<std::string> str;
    std::ifstream myF(argc[1]);
    int i = 0;
    while(getline(myF,str[i])){
      str.pushback(s);
      i++;
    }
    }
}