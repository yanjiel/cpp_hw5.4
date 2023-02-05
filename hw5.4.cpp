#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
using namespace std;


int f(double d) {return static_cast <int> (2 * d);}





//
//template<typename T1, typename T2>
//class ctr {
//public:
//	ctr():count(0) {}
//
//	ctr(T1(*func)(T2)) {
//		count = 0;
//		fun = func;
//		//cout << typeid(func).name() << ", " << typeid(func).name() << ", " << typeid(*fun).name() << endl;
//	}
//
//	T1 operator()(T2 arg) const {
//		count += 1;
//		return (*fun)(forward<T2>(arg));
//		//return (*fun)(arg);
//		//return static_cast<T1> (1);
//	}
//
//	void print() {
//		cout << "here" << endl;
//		cout << (*fun)(static_cast<T2>(3)) << endl;
//	}
//
//private:
//	static int count;
//	T1 (*fun) (T2) = NULL;
//};
//
//template <typename T1, typename T2>
//int ctr<T1, T2>::count = 0;
//






class Counter2 {
public:
	Counter2() : count(0) {}

	template<typename T1, typename T2>
	Counter2(T1(*func)(T2)) { 
		count = 0; 
		T1 (*fun)(T2) = move(func); 
	}

	template<typename T2>
	auto operator()(T2&& arg) {
		count += 1;
		return fun<auto, T2>(forward<T2>(arg));
	}

	/*template<typename t2>
	operator<T1>() (T2&& arg) {count += 1; }*/

private:
	int count;
	template <typename T1, typename T2>
	static T1 (*fun) (T2);

};


		

int main() {
	/*int i = 2;
	auto up = makeUnique<Class1>(i);*/
	/*Counter cf(f);
	cf(1.3);*/
	//cf(2.4);

	/*ctr<int, double> cf(f);
	cf.print();
	cout << cf(1.3);*/

}