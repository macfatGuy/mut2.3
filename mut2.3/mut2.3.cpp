#include <iostream>
#include <mutex>
#include <algorithm>

using namespace std;

class Data {
public:
  int value;
  mutex m;

  Data(int val) : value(val) {}
};


void swapData(Data& d1, Data& d2) {
  scoped_lock<mutex, mutex> lock(d1.m, d2.m); 
  swap(d1.value, d2.value); 
}


int main() {
  setlocale(LC_ALL, "Russian");
  
  Data d1(10), d2(20);

  cout << "До обмена: d1 = " << d1.value << ", d2 = " << d2.value << endl;

  swapData(d1, d2);
  cout << "После обмена: d1 = " << d1.value << ", d2 = " << d2.value << endl;

  return 0;
}

