#include <iostream>
#include <string.h>
#include <math.h>
#include "TStack.h"
#include <stdlib.h>
#include <string>// я тут дописал немного
using namespace std;
class TCalc
{
	string infix, postfix;
	TStack<double> D;
	TStack<char> C;
	string set_infix(string s) {
		infix = s;
	}
	string set_infix() {
		string s;
		cin >> s;
		infix = s;
	}
	void get_infix() {
		cout << infix;
	};
	void get_postfix() {
		cout << postfix;
	};

	int Prior(char el) {
		if ((el == '(') || (el == ')')) return 0;
		if ((el == '+') || (el == '-')) return 1;
		if ((el == '*') || (el == '/')) return 2;
		if (el == '^') return 3;
	}
public:
	TCalc() {
		infix = "";
	}
	TCalc(string s) {
		infix = s;
	}
	double CalcPostfix();
	void ToPostfix();			
	double Calc();

	
};

