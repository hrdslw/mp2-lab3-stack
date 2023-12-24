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
	void ToPostfix() {
		C.Clear();
		string str = '(' + infix + ')';

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
			{
				C.Push('(');
			}

			if ((str[i] >= '0') && (str[i] <= '9'))
			{
				postfix += str[i];
			}

			if (str[i] == ')')
			{
				char el = C.Pop();
				while (el != '(')
				{
					postfix += el;
					el = C.Pop();
				}
			}

			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
			{
				char el = C.Pop();
				while (Prior(el) >= Prior(str[i]))
				{
					postfix += el;
					el = C.Pop();
				}
				C.Push(el);
				C.Push(str[i]);
			}
		}
	};
public:
	TCalc(string s) : infix(s){
		this->ToPostfix();
	}
	void SetInfix(string s) {
		infix = s;
	}
	void SetInfix() {
		string s;
		cin >> s;
		infix = s;
	}
	double CalcPostfix();
				
	double Calc();
	void Print() {
		while (!D.IsEmpty())
			cout << D.Pop();
	}
	string GetInfix() {
		return infix;
	};
	string GetPostfix() {
		return postfix;
	};
};

