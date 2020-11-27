#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdint.h>
#include <map>
#include <queue>
#include <assert.h>
#include <functional>
#include <stdlib.h>
#include "readFreq.h"
#include "node.h"



void writeHeader(BitFileWriter * bfw, const std::map<unsigned,BitString> &theMap) {
  for (int i =0 ; i < 257; i++) {
    std::map<unsigned,BitString>::const_iterator it = theMap.find(i);
    if (it != theMap.end()) {
      bfw->writeByte(it->second.size());
      bfw->writeBitString(it->second);
    }
    else {
      bfw->writeByte(0);
    }
  }
}

void writeCompressedOutput(const char* inFile,
			   const char *outFile,
			   const std::map<unsigned,BitString> &theMap ){
  BitFileWriter bfw(outFile);
  writeHeader(&bfw,theMap);

  //WRITE YOUR CODE HERE!
  //open the input file for reading
  std::ifstream ifs;
  ifs.open(inFile, std::ifstream::in);
  int c;
  while((c=ifs.get())!=EOF){
    //std::map<unsigned,BitString>::iterator it = theMap.find(c);
   // if(it!=theMap.end()){
      bfw.writeBitString(theMap.find(c)->second);
    //}
    
  }
  //You need to read the input file, lookup the characters in the map,
  //and write the proper bit string with the BitFileWriter

  //dont forget to lookup 256 for the EOF marker, and write it out.
    //std::map<unsigned,BitString>::iterator it = theMap.find(c);
   // if(it!=theMap.end()){
      bfw.writeBitString(theMap.find(256)->second);
    //}
    
    ifs.close();
  //BitFileWriter will close the output file in its destructor
  //but you probably need to close your input file.
}

int main(int argc, char ** argv) {
  if (argc != 3) {
    fprintf(stderr,"Usage: compress input output\n");
    return EXIT_FAILURE;
  }
  //WRITE YOUR CODE HERE
  //Implement main
  //hint 1: most of the work is already done. 
  //hint 2: you can look at the main from the previous tester for 90% of this
  uint64_t * freq = readFrequencies(argv[1]);
  Node * root= buildTree(freq);
  BitString b;
  std::map<unsigned,BitString> theMap;
  root->buildMap(b,theMap);
  writeCompressedOutput(argv[1], argv[2], theMap);
  delete[] freq;
  delete root;
  return EXIT_SUCCESS;

}
