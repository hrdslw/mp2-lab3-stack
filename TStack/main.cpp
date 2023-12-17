#include <iostream>
#include <string.h>
#include "TStack.h"
using namespace std;

int main() {
	TStack<int> s(10);
	

	s.Push(4);
	s.Push(5);

	TStack<int> s1(s);
	

	int count = 0;
	while (!s.IsEmpty() && !s1.IsEmpty()) {
		int a, b;
		a = s.Pop(); cout << a << "    ";
		b = s1.Pop(); cout << b << endl;
		
		count++;
	}
	cout << "Count: " << count;
	


	//string str = "(2 + 2) * 2 + (3 * 4)";
	//TStack<char> s(5);
	//int res = 0;
	/*for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			s.Push(str[i]);
		else if (str[i] == ')') {
			if (!s.IsEmpty())
				s.Pop();
			else
				res = 1;
		}
	}
	if (!s.IsEmpty())
		res = 2;

	cout << res;
	*/

	//cin >> s;
	//s.Clear();
	//cout << s;
}
