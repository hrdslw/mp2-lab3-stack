#include "TCalc.h"

int TCalc::Prior(const char el) {
	if (el == '+' || el == '-')
		return 1;
	if (el == '*' || el == ':')
		return 2;
	if (el == '^')
		return 3;
}

double TCalc::CalcPostfix() {
	double x2, x1, y;
	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			D.Push(postfix[i] - '0');
		}
		else if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == ':') || (postfix[i] == '^')) {
			x2 = D.Pop();
			x1 = D.Pop();
			if (postfix[i] == '+')
				y = x1 + x2;
			else if (postfix[i] == '-')
				y = x1 - x2;
			else if (postfix[i] == '*')
				y = x1 * x2;
			else if (postfix[i] == ':')
				y = x1 / x2;
			else if (postfix[i] == '^')
				y = pow(x1, x2);
			D.Push(y);
		}
	}
	return D.Pop();
}

void TCalc::ToPostfix() {
	C.Clear();
	string str = "(" + infix + ")";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			C.Push('(');
		else if ((str[i] >= '0') && (str[i] <= '9'))
			postfix += str[i];
		if (str[i] == ')') {
			char el = C.Pop();
			while (el != '(') {
				postfix += el;
				el = C.Pop();
			}
			if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == ':') || (postfix[i] == '^')) {
				char el = C.Pop();
				while (Prior(el) >= Prior(str[i])) {
					postfix += el;
					el = C.Pop();
				}
			}
		}
	}
}
