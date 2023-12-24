#include <iostream>
#include <string.h>
#include <math.h>
#include "TStack.h"
#include <stdlib.h>
#include <string>
using namespace std;
class TCalc
{

	string infix, postfix;
	TStack<double> D;
	TStack<char> C;
	

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
	string set_infix(string s) {
		infix = s;
	}
	string set_infix() {
		string s;
		cin >> s;
		infix = s;
	}
	double CalcPostfix();
	void ToPostfix();			
	double Calc();
	void Print() {
		while (!D.IsEmpty())
			cout << D.Pop();
	}
	void get_infix() {
		cout << infix;
	};
	void get_postfix() {
		cout << postfix;
	};
};

//#pragma once
//#include <string>
//#include <cmath>
//#include <string.h>
//#include "TStack.h"
//
//using namespace std;
//
//class TCalculator
//{
//	string  inf, postf;
//	TStack<char> c = TStack<char>(10);
//	TStack<double> d = TStack<double>(10);
//
//	int prioritet(char op)
//	{
//		if (op == '(' || op == ')')
//			return 0;
//		if (op == '+' || op == '-')
//			return 1;
//		if (op == '*' || op == '/')
//			return 2;
//		if (op == '^')
//			return 3;
//	}
//	void CurrIndostfix();
//public:
//	TCalculator(string& str) :inf(str) { CurrIndostfix(); };
//	bool expression();
//	void set_infix(string str);
//	string get_postfix();
//	string get_infix();
//	double CalcPostfix();
//	double calc();
//
//};
//
