#ifndef STACK_H
#define STACK_H

#include <vector>

class Stack {
private:
  std::vector<int> stack; 

public:
  void push(int value);
  void pop();
  bool isEmpty();
  int top();
  double average();

};

#endif