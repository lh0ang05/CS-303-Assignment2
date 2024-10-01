#include "functions.h"

// initialize empty list
template <typename Item_Type>
Single_List<Item_Type>::Single_List()
    : head(nullptr), tail(nullptr), num_items(0) {}

// empty up memory for all nodes
template <typename Item_Type>
Single_List<Item_Type>::~Single_List() {
  while (!empty()) {
    pop_front();
    }

}
  

// check if list is empty
template <typename Item_Type>
bool Single_List<Item_Type>::empty() const {
  return num_items == 0;
}


// add element to front of list
template <typename Item_Type>
void Single_List<Item_Type>::push_front(const Item_Type& item) {
  head = new Node(item, head);
  if (tail == nullptr) { 
    tail = head;
  }

  num_items++; 

}


// adding element to back of list
template <typename Item_Type>
void Single_List<Item_Type>::push_back(const Item_Type& item) {
  Node* new_node = new Node(item);
  if (tail != nullptr) { 
    tail->next = new_node;  
    tail = new_node;        
    } 
  else {  
    head = tail = new_node;
    }
  num_items++;  

}



// removing 1st element in list
template <typename Item_Type>
void Single_List<Item_Type>::pop_front() {
  if (empty()) {
    return; 
    }

  Node* old_head = head;
  head = head->next;
  delete old_head;
  num_items--;
  if (head == nullptr) {
    tail = nullptr;
    }

}


// removing the last element in the list
template <typename Item_Type>
void Single_List<Item_Type>::pop_back() {
  if (empty()) {
    return;
    }

  if (head == tail) {
    delete head;
    head = tail = nullptr;
    } 
  else {
    Node* current = head;
    while (current->next != tail) {
      current = current->next;
      }

    delete tail;
    tail = current;
    tail->next = nullptr;
    }

  num_items--; 

}


// getting 1st element in list
template <typename Item_Type>
Item_Type& Single_List<Item_Type>::front() {
  return head->data;
}


// getting the last element in list
template <typename Item_Type>
Item_Type& Single_List<Item_Type>::back() {
  return tail->data;
}


// inserting item at certain index
template <typename Item_Type>
void Single_List<Item_Type>::insert(size_t index, const Item_Type& item) {
  if (index == 0) {  
    push_front(item);
    } 
  else if (index >= num_items) {
    push_back(item);
    } 
  else {
    Node* current = head;
    for (size_t i = 1; i < index; ++i) {
      current = current->next;
      }

    Node* new_node = new Node(item, current->next);
    current->next = new_node; 
    num_items++;
    }

}


// removing item at certain index
template <typename Item_Type>
bool Single_List<Item_Type>::remove(size_t index) {
  if (index >= num_items) {
    return false;  
    }

  if (index == 0) {
    pop_front();
    return true;
    }

  Node* current = head;
  for (size_t i = 1; i < index; ++i) {
    current = current->next;
    }

  Node* node_to_delete = current->next;
  current->next = node_to_delete->next; 
  delete node_to_delete;
  if (current->next == nullptr) { 
    tail = current;
    }

  num_items--;  
  return true;

}


// finding index of 1st occurrence of item
template <typename Item_Type>
size_t Single_List<Item_Type>::find(const Item_Type& item) const {
  Node* current = head;
  size_t index = 0;
  while (current != nullptr) {
    if (current->data == item) {
      return index;
      }

    current = current->next;
    index++;
    }

  return num_items;

}


// getting size of list
template <typename Item_Type>
size_t Single_List<Item_Type>::size() const {
  return num_items;
}