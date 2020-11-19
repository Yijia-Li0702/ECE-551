#ifndef _LL_H_
#define _LL_H_
#include <cstdlib>
#include <exception>
#include <assert.h>

//YOUR CODE GOES HERE


class Error : public std::exception {
 public:
  virtual const char * what() const throw() {
    return "The requested item does not exist\n";
  }
};
template <typename T>
class LinkedList{
private:
 class Node{
 public:
   T data;
   Node * next;
   Node * prev;
   Node() : data(0), next(NULL), prev(NULL){};
   Node(const T & d,Node * p1,Node* p2) : data(d), next(p1), prev(p2){};
 };
 Node * head;
 Node * tail;
 int size;
public:
  LinkedList(): head(NULL),tail(NULL),size(0){};
  void addFront(const T &item){
    head = new Node(item,head,NULL);
    if(tail == NULL){
      tail =head;
    }
    else {
      head->next->prev=head;
    }
    size++;
  }
  void addBack(const T &item){
    tail = new Node(item,NULL,tail);
    if(head == NULL){
       head = tail;
    }
    else {
      tail->prev->next=tail;
    }
    size++;
  }
  bool remove(const T &item){
    Node ** ptr = &head;
    while(*ptr!= NULL){
     if(((*ptr)->data) == item){
      if((*ptr)->next!=NULL){
        (*ptr)->next->prev= (*ptr)->prev;
      } else{
       tail = (*ptr)->prev;  
       }
       (*ptr) = (*ptr)->next;
       size--;
       return true;
     }
     ptr = &((*ptr)->next);
    }
    return false;
  }
  T & operator[](int index){
    int i = index;
    Node * ptr = head;
    while(ptr != NULL && i > 0){
      i--;
      ptr = ptr->next;
      }
      if(ptr == NULL){
        throw Error();
      }
       return ptr->data;
      
  }
  T & operator[](int index) const{
    int i = index;
    Node * ptr = head;
    while(ptr != NULL && i > 0){
      i--;
      ptr = ptr->next;
      }
      if(ptr == NULL){
        throw Error();
      }
       return ptr->data;
      
  }
  int find(const T &item){
    int i = 0;
    Node * ptr = head;
    while(ptr != NULL){
      if(ptr->data == item){
        return i;
      }
      i++;
      ptr = ptr->next;
    }
    return -1;
  }
  ~LinkedList(){
  while(head!=NULL){
      Node * temp = head -> next;
      delete head;
      head = temp;
    }
  }
  LinkedList(const LinkedList & rhs){
    head = NULL;
    tail = NULL;
    //LinkedList ans;
    Node * ptr = rhs.head;
    while(ptr != NULL){
      //Node n = new Node(ptr->data);
      this->addBack(ptr->data);
      ptr = ptr->next;
    }
  }
  LinkedList & operator=(const LinkedList & rhs){
  if(this != &rhs){
    LinkedList * ans = new LinkedList();
    Node * ptr = rhs.head;
    while(ptr != NULL){
      //Node n = new Node(ptr->data);
      ans->addBack(ptr->data);
      ptr = ptr->next;
    }
    delete this;
    this = ans;
    }
     return *this;
  }
  int getSize() const{
    int mysz = 0;
    for (Node * p = head; p != NULL; p = p->next) {
    mysz++;
  }
  return mysz;
    //return size;
  }
};




#endif



