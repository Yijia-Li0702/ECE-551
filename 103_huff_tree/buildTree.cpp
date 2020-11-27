#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stdint.h>
#include "node.h"

Node *  buildTree(uint64_t * counts) {
  //WRITE ME!
	priority_queue_t pd;
  for(size_t i=0;i< 257;i++){
  if(counts[i]!=0){
  	pd.push(new Node(i,counts[i]));
   }
  }
  while(pd.size()>1){
  	Node* left=pd.top();
   pd.pop();
   Node * right = pd.top();
   pd.pop();
//   if(pd.size()==1){
//   Node * n =new Node(left,right);
//   return n;
//   }
 	
 	//uint64_t n-freq = left.n-freq+right.n-freq;
 	Node * n =  new Node(left,right);
 	pd.push(n);
  
}  
return pd.top();
}
