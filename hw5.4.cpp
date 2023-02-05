#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
using namespace std;


int f(double d) {return static_cast <int> (2 * d);}






template<typename T1, typename T2>
class ctr {
public:
	ctr():count(0) {}

	ctr(T1(*func)(T2)) {
		count = 0;
		fun = func;
		//cout << typeid(func).name() << ", " << typeid(fun).name() << ", " << typeid(*fun).name() << endl;
	}

	T1 operator()(T2 arg) const {
		count += 1;
		return (*fun)(forward<T2>(arg));
		//return (*fun)(arg);
		//return static_cast<T1> (1);
	}

	void print() {
		cout << "here" << endl;
		cout << (*fun)(static_cast<T2>(3)) << endl;
	}

private:
	static int count;
	T1 (*fun) (T2) = NULL;
};

template <typename T1, typename T2>
int ctr<T1, T2>::count = 0;

class Counter {
public:
	template<typename T1, typename T2>
	Counter(T1(*func)(T2)) {
		cout << typeid(func).name() << ", " << typeid(*func).name() << endl;
		ctr<T1, T2> *counter = new ctr<T1, T2>(func);
		cout << typeid(counter).name() << ", " << typeid(*counter).name() << endl;
	}

	/*template<typename T1, typename T2>
	T1 operator()(T2&& arg) {
		return (*counter)(forward<T2>(arg));
	}*/

private:
	template<typename T1, typename T2>
	static ctr<T1, T2> counter;

};






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


		

int main() {

	/*Counter2 cf(f);
	cf(1.3);*/
	
	Counter cf(f);

	/*ctr<int, double> cf(f);
	cf.print();
	cout << cf(1.3);*/

}