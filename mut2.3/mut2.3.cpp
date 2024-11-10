#include <iostream>
#include <mutex>

using namespace std;

class Data {
public:
	int value;
	mutex m;

	Data(int val) : value(val) {}
};

// Вариант 1: с использованием lock
void swapDataLock(Data& d1, Data& d2) {
	lock_guard<mutex> lock1(d1.m), lock2(d2.m); 
	swap(d1.value, d2.value); 
}

// Вариант 2: с использованием scoped_lock
void swapDataScopedLock(Data& d1, Data& d2) {
	scoped_lock<mutex, mutex> lock(d1.m, d2.m); 
	swap(d1.value, d2.value); 
}

// Вариант 3: с использованием unique_lock
void swapDataUniqueLock(Data& d1, Data& d2) {
	unique_lock<mutex> lock1(d1.m), lock2(d2.m);
	swap(d1.value, d2.value); 
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	Data d1(10), d2(20);

	cout << "До обмена: d1 = " << d1.value << ", d2 = " << d2.value << endl;

	swapDataLock(d1, d2);
	cout << "После swapDataLock: d1 = " << d1.value << ", d2 = " << d2.value << endl;

	swapDataScopedLock(d1, d2);
	cout << "После swapDataScopedLock: d1 = " << d1.value << ", d2 = " << d2.value << endl;

	swapDataUniqueLock(d1, d2);
	cout << "После swapDataUniqueLock: d1 = " << d1.value << ", d2 = " << d2.value << endl;

	return 0;
}

