#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "set.h"


template<typename T>
class BstSet : public Set<T>{
 private:
  class Node {
   public:
    T key;
    Node * left;
    Node * right;
    Node() : key(0), left(NULL), right(NULL) {}
    Node(T k) : key(k), left(NULL), right(NULL) {}
  };
  Node * root;
public:
  BstSet() : root(NULL) {}
  BstSet(const BstSet & rhs){
   root = copy(rhs.root); 
  }
  BstSet & operator=(const BstSet & rhs){
    if(this != &rhs){
    destroy(root);
    root = copy(rhs.root);  
    }
    return *this;
  }
  Node * copy(Node * rhs){
    if(rhs == NULL){
      return rhs;
    }
    Node * curr = new Node(rhs->key);
    curr->left = copy(rhs->left);
    curr->right = copy(rhs->right);
    return curr;
  }  
  virtual void add(const T & key){
     Node ** curr = &root;
     while (*curr != NULL) {
      if (key == (*curr)->key) {
        return;
      }
      if (key < (*curr)->key) {
        curr = &(*curr)->left;
      }
      else {
        curr = &(*curr)->right;
      }
    }
    *curr = new Node(key);
  }
  virtual bool contains(const T& key) const {
     Node * ptr = root;
    while(ptr!=NULL){
      if(ptr->key>key){
        ptr = ptr->left;
      }else if(ptr->key<key){
        ptr = ptr->right;
      } else{
        return true;
      }
      }
      return false; 
  }
  virtual void remove(const T& key) {
     Node ** ptr = &root;
    while((*ptr)!=NULL){
      if((*ptr)->key>key){
        ptr = &(*ptr)->left;
      }else if((*ptr)->key<key){
        ptr = &(*ptr)->right;
      } else{
      break;
      }
      }
      if((*ptr)!=NULL){
        if((*ptr)->left == NULL && (*ptr)->right == NULL){
          delete *ptr;
          //ptr = NULL;
          return ;
        } else if((*ptr)->left == NULL && (*ptr)->right != NULL){
          Node * curr = *ptr;
          *ptr = (*ptr)->right;
          delete curr;
          return;
        }else if((*ptr)->left != NULL && (*ptr)->right == NULL){
          Node * curr = *ptr;
          *ptr = (*ptr)->left;
          delete curr;
          return;
        } else {
          Node * ptr1 = (*ptr)->left;
          while(ptr1->right !=NULL){
            ptr1=ptr1->right;
          }
          //ptr->key = ptr1->key;
          //ptr->value = ptr1->value;
          Node * curr = *ptr;
          ptr1->right = (*ptr)->right;
          *ptr = ptr1;
          delete curr;
         // ptr1->right == NULL;
          return;
        }
      }
  }
    void destroy(Node * current) {
    if (current != NULL) {
      destroy(current->left);
      destroy(current->right);
      delete current;
    }
  }
  virtual ~BstSet<T>() {
    destroy(root);
  }
//for test
  void printPreorder(Node * curr) {
    if (curr != NULL) {
      std::cout << curr->key << " ";
      printPreorder(curr->left);
      printPreorder(curr->right);
    }
  }

  void printBstset() {
    printPreorder(root);
    std::cout << "\n";
  }

};