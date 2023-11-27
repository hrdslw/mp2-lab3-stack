#include <iostream>
#include <string.h>
#include "TStack.h"
using namespace std;
class TCalc
{
	string infix, postfix;
	TStack<char> C;
	TStack<double> D;
public:
	double Calc();
	int Prior(const char el);
	double CalcPostfix();
	void ToPostfix();
};

