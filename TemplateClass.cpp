
#include <iostream>
#include"clsInputValidate.h"
using namespace std;

template <class T>
class Calculator {
	T Number1, Number2;

public:
	Calculator(T n1, T n2) {
		Number1 = n1;
		Number2 = n2;
	}

	void Print() {
		cout << "Numbers " << Number1 << " And " << Number2;
		cout << "\n\nResult:\n";
		cout << Number1 << " + " << Number2 << " = " << Add() <<endl;
		cout << Number1 << " - " << Number2 << " = " << Subtract() << endl;
		cout << Number1 << " * " << Number2 << " = " << Multiply() << endl;
		cout << Number1 << " / " << Number2 << " = " << Devide() << endl;
	}

	T Add() {
		return Number1 + Number2;
	}

	 T Subtract() {
		return (Number1 > Number2) ? Number1 - Number2 : Number2 - Number1;
	}

	T Multiply() {
		return Number1 * Number2;
	}

	T Devide() {
		if (Number2 == 0)
			Number2 = 1;

		return Number1 / Number2;
	}

};
int main()
{
	Calculator <int >intCalc(2, 1);
	Calculator <float>FloatCalc(2.4, 1.2);
	cout << "int Result:\n";
	intCalc.Print();
	cout << endl;

	cout << "\nfloat Result:\n";
	FloatCalc.Print();
	cout << endl;
	
	

	system("pause>0");

}





