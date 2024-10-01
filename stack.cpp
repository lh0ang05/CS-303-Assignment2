#include "stack.h"
#include <iostream>

void Stack::push(int value) {
  stack.push_back(value);
}


// poping element from stack
void Stack::pop() {
  if (!stack.empty()) { 
    stack.pop_back(); 
    } 
  else {
    std::cout << "stack empty, cannot pop" << std::endl;
    }
    
}

// checking if the stack is empty
bool Stack::isEmpty() {
  return stack.empty(); 
}

// finding top element of stack
int Stack::top() {
  if (!stack.empty()) {
    return stack.back(); 
    } 
  else {
    std::cout << "stack empty" << std::endl;
    return -1;
  }

}

// calculating avg value of stack elements
double Stack::average() {
  if (stack.empty()) {
    std::cout << "stack empty, average is 0" << std::endl;
    return 0.0; 
    }
    
  int sum = 0;
  for (int val : stack) {
    sum += val; 
    }
    
  return static_cast<double>(sum) / stack.size();

}
