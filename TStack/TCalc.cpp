#include "TCalc.h"
#include <stdlib.h>
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

double TCalc::Calc() {
	C.Clear(); D.Clear();
	string str = '(' + infix + ')';
	for (int i = 0; i < str.size(); i++) {					// ïðîâåðêà óñëîâèé äëÿ ïîäñ÷åòà îïåðàöèé
		if (str[i] == '(') C.Push(str[i]);
		if (str[i] == ')') {
			char el = C.Pop();
			while (el != ')') {
				double x1 = D.Pop();
				double x2 = D.Pop();
				double y = 0;
				if (el == '+') y = x1 + x2;
				if (el == '-') y = x1 - x2;
				if (el == '*') y = x1 * x2;
				if (el == '/') y = x1 / x2;					// äîáàâèòü ôóíêöèþ ^ - âîçâåäåíèå â ñòåïåíü, ïðèîðèòåò = 3
				D.Push(y);
				el = C.Pop();
			}
		}
		if ((str[i] >= '0') && (str[i] <= '9')) {				//Вычисление числа 
			size_t pos;
			double x;
			x = stod(&str[i], &pos);
			D.Push(x);
			i = i + pos - 1;
		}
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/')) {			//äîáàâëÿåò â ñòåê îïåðàíäû, âû÷èñëÿåò, åñëè
			char el = C.Pop();																//ïðèîðèòåò ìåíüøå, ÷òî ñ÷èòàåò
			while (Prior(el) > Prior(str[i])) {
				double y;
				double x2 = D.Pop();
				double x1 = D.Pop();
				if (el == '+') y = x1 + x2;
				if (el == '-') y = x1 - x2;
				if (el == '*') y = x1 * x2;
				if (el == '/') y = x1 / x2;	// ìîæåò áûòü íåòî÷íûé îòâåò. Ïðè òåñòå ñðàâíèâàåì íå âðó÷íóþ âáèòûå çíà÷åíèÿ, à òî, ÷òî ïîñ÷èòàåò êîìïèëÿòîð
				D.Push(y);
				el = C.Pop();
			}
			C.Push(el);
			C.Push(str[i]);
		}
	}
	return D.Pop();
}

