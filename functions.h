#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#include <iostream>

// intialize template for single list class
template <typename Item_Type>
class Single_List {

private:
  struct Node {
    Item_Type data; 
    Node* next;     
    Node(const Item_Type& data_item, Node* next_ptr = nullptr)
    : data(data_item), next(next_ptr) {}
    };

  Node* head; 
  Node* tail;  
  size_t num_items;  

public:
  Single_List();
  ~Single_List();
  bool empty() const;
  void push_front(const Item_Type& item);
  void push_back(const Item_Type& item);
  void pop_front();
  void pop_back();
  Item_Type& front();
  Item_Type& back();
  void insert(size_t index, const Item_Type& item);
  bool remove(size_t index);
  size_t find(const Item_Type& item) const;
  size_t size() const;
};

#include "functions.cpp"
#endif
