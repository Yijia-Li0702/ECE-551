#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstdio>
#include <assert.h>

#include "il.h"

void testList(void){
  //initialize
  IntList tc0;
  assert(tc0.getSize()==0&&tc0.head == NULL&&tc0.tail==NULL);
  
  tc0.addFront(0);//0
  assert(tc0.head->data==0&&tc0[0]==0&&tc0.head==tc0.tail);
  assert(tc0.head->next==NULL&&tc0.tail->next==NULL);
  assert(tc0.head->prev==NULL&&tc0.tail->prev==NULL);
  assert(tc0.tail->data==0);
  assert(tc0.getSize()==1&&tc0.size==1);
  assert(tc0.find(0)==0);
  
  tc0.addFront(1);//1,0
  assert(tc0.head->data==1&&tc0[0]==1&&tc0[1]==0);
  assert(tc0.head->data==1);
  assert(tc0.head->next->data==0);
  assert(tc0.head->next->next==NULL&&tc0.tail->next==NULL);
  assert(tc0.head->prev==NULL&&tc0.tail->prev->prev==NULL&&tc0.head->next->prev == tc0.head);
  assert(tc0.tail == tc0.head->next);
  assert(tc0.tail->prev->data==1);
  assert(tc0.tail->data==0);
  assert(tc0.getSize()==2&&tc0.size==2);
  assert(tc0.find(1)==0);
  assert(tc0.find(4)==-1);
  
  tc0.addBack(2);//1,0,2
  assert(tc0[0]==1&&tc0[1]==0&&tc0[2]==2);
  assert(tc0.head->data==1);
  assert(tc0.head->next->data==0);
  assert(tc0.head->next->next->data==2);
  assert(tc0.head->next->next->next==NULL&&tc0.tail->next==NULL);
  assert(tc0.head->prev==NULL&&tc0.tail->prev->prev->prev==NULL);
  assert(tc0.tail->prev->prev->data==1);
  assert(tc0.tail->prev->data==0);
  assert(tc0.tail->data==2);
  assert(tc0.getSize()==3&&tc0.size==3);
  assert(tc0.find(2)==2);
  
  assert(!tc0.remove(4));
  assert(tc0.remove(0));//1,2
  assert(tc0.head->data==1);
  assert(tc0.head->next->data==2);
  assert(tc0.tail->data==2);
  assert(tc0.getSize()==2&&tc0.size==2);
  assert(tc0.find(0)==-1);
  
  //copy constructer
  IntList tc1(tc0);//1,2
  assert(tc1.head->data==1);
  assert(tc1.head->next->data==2);
  assert(tc1.head->next->next==NULL&&tc1.tail->next==NULL);
  assert(tc1.head->prev==NULL&&tc1.tail->prev->prev==NULL);
  assert(tc1.tail->data==2);
  assert(tc1.getSize()==2&&tc1.size==2);
  assert(tc1.find(0)==-1);
  
  assert(tc1[0] == 1&&tc1[1]==2);
  tc1.addBack(5);
  assert(tc1.head->next->next->data==5&&tc1.tail->data==5);
  assert(tc1.head == tc1.tail->prev->prev);
  tc1.addBack(6);
  assert(tc1.head->next->next->next->data==6&&tc1.tail->data==6);
  assert(tc1.getSize()==4&&tc1.size==4);//1,2,5,6
  tc1.remove(5);//1,2,6
  
  //assign
  IntList tc2(tc1);//1,2,6
  tc0 = tc2;//1,2,6
  assert(tc0[0]==1&&tc0[1]==2&&tc0[2]==6);
  assert(tc0.getSize()==3&&tc0.size==3);
  IntList tc4;
  tc4 = tc1;
  assert(tc4[0]==1&&tc4[1]==2&&tc4[2]==6);
  assert(tc4.getSize()==3&&tc4.size==3&&tc4[2]==6);
  assert(tc4.head->data==1);
  assert(tc4.head->next->data==2);
  assert(tc4.head->next->next->data==6);
  assert(tc4.head->next->next->next==NULL&&tc4.tail->next==NULL);
  assert(tc4.head->prev==NULL&&tc4.tail->prev->prev->prev==NULL);
  assert(tc4.tail->prev->prev->data==1);
  assert(tc4.tail->prev->data==2);
  assert(tc4.tail->data==6);
  assert(tc4.tail->prev->prev == tc4.head);
  assert(tc4.head->next->prev == tc4.head);
  
  IntList tc3;
  tc3.addBack(1);
  tc3.addFront(3);
  tc3.addFront(3);
  tc3.addFront(4);//4,3,3,1
  assert(tc3.find(3) == 1);
  assert(tc3.remove(3));
  assert(tc3.find(3) == 1);
  assert(tc3.remove(3));
  assert(tc3.getSize()==2&&tc3.size==2);
  assert(tc3.remove(1));
  assert(tc3.remove(4));
  assert(tc3.getSize()==0&&tc3.size==0);
  assert(tc3.head == NULL && tc3.tail == NULL);
  
  tc3.~IntList();
  
  
  //github
  }




int main() {
  testList();
  return EXIT_SUCCESS;
}