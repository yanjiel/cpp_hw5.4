#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
#include<format>
using namespace std;


int f(double d) {return static_cast <int> (2 * d);}


template<typename T1, typename T2>
class Counter {
public:
	static int count;

	Counter():count(0) {}

	Counter(T1(*func)(T2)) {
		count = 0;
		fun = move(func);
	}

	T1 operator()(T2 arg) const {
		count += 1;
		return (*fun)(forward<T2>(arg));
	}

	/*void print() {
		cout << "here" << endl;
		cout << (*fun)(static_cast<T2>(3)) << endl;
	}*/

private:
	T1 (*fun) (T2) = NULL;
};

template <typename T1, typename T2>
int Counter<T1, T2>::count = 0;



//class CounterWrapper {
//public:
//	template<typename T1, typename T2>
//	CounterWrapper(T1(*func)(T2)) {
//		cout << typeid(func).name() << ", " << typeid(*func).name() << endl;
//		Counter<T1, T2> *counter = new Counter<T1, T2>(func);
//		cout << typeid(counter).name() << ", " << typeid(*counter).name() << endl;
//	}
//
//	template<typename T1, typename T2>
//	T1 operator()(T2&& arg) {
//		return (Counter<T1, T2> *counter)(arg);
//	}
//
//private:
//	template<typename T1, typename T2>
//	static Counter<T1, T2> counter;
//
//};
//

//
//
//class Counter2 {
//public:
//	Counter2() : count(0) {}
//
//	template<typename T1, typename T2>
//	Counter2(T1(*func)(T2)) { 
//		count = 0; 
//		//T1 (*fun)(T2) = move(func); 
//		fun = func;
//	}
//
//	template<typename T3, typename T4>
//	T3 operator()(T4&& arg) {
//		count += 1;
//		return fun<T3, T4>(forward<T4>(arg));
//	}
//
//	/*template<typename t2>
//	operator<T1>() (T2&& arg) {count += 1; }*/
//
//private:
//	int count;
//	template <typename T1, typename T2>
//	static T1 (*fun) (T2);
//
//	template <typename T1, typename T2>
//	static T1(*op) (T2);
//
//};
//

		

int main() {

	Counter cf(f);
	//cf.print();
	cf(1.3); cf(2.4);
	cout << format("f was called {} times\n", cf.count);
}