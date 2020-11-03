#include <string>
#include <iostream>

//count the number of occurance of the word
void count (std::string s, std::string c){
  int times = 0;
  int position = 0;
  while((position=s.find(s,position))!=std::string::npos){
      //std::cout<<"position  "<<i<<" : "<<position<<endl;
        position++;
        times++;
    }
  std::cout<<times<<std::endl;
}

//replace the word with the specific string 
void rep_s(std::string s, std::string c){
  std::string sen("WAS_HERE");
  while(s.find(c)!=std::string::npos){
    s = s.replace(s.find(c), c.length(),sen);
  }	
}
//read strings from the stdin
void read(std::string s, std::string c){
  std::getline(std::cin,s);
  std::getline(std::cin,c);
  if(!std::cin.good()){
    std::cin.clear();
  }
}

int main(int argc, char ** argv){
  std::string s;
    std::getline(std::cin,s);
    std::string c ;
    std::getline(std::cin,c);
  std::cout<<s<<std::endl;
   std::cout<<c<<std::endl;
   //read(s, c);
  count(s,c);
  rep_s(s,c);
}
