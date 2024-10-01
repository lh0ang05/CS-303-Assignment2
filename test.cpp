#include "functions.h"
#include <iostream>
using namespace std;

int main() {
  Single_List<int> list;
  list.push_front(10);  
  list.push_back(20);
  cout << "Front element: " << list.front() << endl; 
  cout << "Back element: " << list.back() << endl;  

}