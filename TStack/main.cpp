#include <iostream>
#include <string.h>
#include "TStack.h"
#include "TCalc.h"
using namespace std;

int main() {
	
	
	TCalc s("(2 + 2) ^ 3 + (3 * 4) ^ 2");
	cout << s.Calc();
	
}
