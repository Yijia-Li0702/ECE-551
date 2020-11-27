#include "node.h"
#include "bitstring.h"
void Node::buildMap(BitString b, std::map<unsigned,BitString> & theMap) {
  //WRITE ME!
  if(sym == NO_SYM){
    this->right->buildMap(b.plusOne(), theMap);
    //BitString l = b.
    //this->right->buildMap(b.insertByte('1'), theMap);
    this->left->buildMap(b.plusZero(), theMap);
  } else{
    theMap.insert(std::pair<unsigned,BitString>(sym,b));
  }
  return;
  
}

