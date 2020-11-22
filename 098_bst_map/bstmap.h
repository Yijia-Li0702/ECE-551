#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "map.h"

template<typename K, typename V>
class BstMap : public Map<K, V> {
  class Node {
   public:
    K key;
    V value;
    Node * left;
    Node * right;
    Node() : key(0), value(0), left(NULL), right(NULL) {}
    Node(K k, V v) : key(k), value(v), left(NULL), right(NULL) {}
  };
  Node * root;

 public:
  BstMap() : root(NULL) {}
   virtual void add(const K & key, const V & value) {
    Node * ptr = root;
    while(ptr!=NULL){
      if(ptr->key>=key){
        ptr = ptr->left;
      }else {
        ptr = ptr->right;
      }
    }
    ptr = new Node(key,value,NULL,NULL);
  }
  virtual const V & lookup(const K& key) const throw (std::invalid_argument) {
     Node * ptr = root;
    while(ptr!=NULL){
      if(ptr->key>key){
        ptr = ptr->left;
      }else if(ptr->key<key){
        ptr = ptr->right;
      } else{
        return ptr->value;
      }
       throw std::invalid_argument("The key is not found!\n");
  }
  }
 virtual void remove(const K& key) {
     Node * ptr = root;
    while(ptr!=NULL){
      if(ptr->key>key){
        ptr = ptr->left;
      }else if(ptr->key<key){
        ptr = ptr->right;
      } else{
      break;
      }
      }
      if(ptr!=NULL){
        if(ptr->left == NULL && ptr->right == NULL){
          delete ptr;
          ptr = NULL;
          return ;
        } else if(ptr->left == NULL && ptr->right != NULL){
          ptr->key = ptr->right->key;
          ptr->value = ptr->right->value;
          delete ptr->right;
          ptr->right = NULL;
          return;
        }else if(ptr->left != NULL && ptr->right == NULL){
          ptr->key = ptr->left->key;
          ptr->value = ptr->left->value;
          delete ptr->left;
          ptr->left = NULL;
          return;
        } else {
          Node * ptr1 = ptr->left;
          while(ptr1->right !=NULL){
            ptr1=ptr1->right;
          }
          ptr->key = ptr1->key;
          ptr->value = ptr1->value;
          delete ptr1->right;
          ptr1->right == NULL;
          return;
        }
      }
  }
    virtual ~BstMap<K, V>() { destroy(root); }

  void destroy(Node * current) {
    if (current != NULL) {
      destroy(current->left);
      destroy(current->right);
      delete current;
    }
  }


};