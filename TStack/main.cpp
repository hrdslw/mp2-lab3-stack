#include <iostream>
#include <string.h>
#include "TStack.h"
using namespace std;

int main() {
	//string str = "(2 + 2) * 2 + (3 * 4)";
	TStack<char> s(5);
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
	s.Clear();
	//cout << s;
}
