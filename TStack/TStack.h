#pragma once

using namespace std;

template <class T>
class TStack
{
	T* pMem;
	int MaxSize;
	int CurrInd;
public:
	TStack(int MaxS = 10) {
		if (MaxS < 0)
			throw ("Wrong size");
		MaxSize = MaxS;
		pMem = new T[MaxSize];
		CurrInd = -1;
	}
	TStack(const TStack& s) {
		MaxSize = s.MaxSize;
		pMem = new T[MaxSize];
		CurrInd = s.CurrInd;
		for (int i = 0; i < CurrInd; i++) {
			pMem[i] = s.pMem[i];
		}
	}

	~TStack() {
		delete[] pMem;
	}

	int Size() {
		return MaxSize;
	}
	
	bool IsEmpty() {
		if (CurrInd == -1)
			return true;
		else
			return false;
	}

	bool IsFull() {
		if (CurrInd == MaxSize - 1)
			return true;
		else
			return false;
	}

	void Push(const T& el) {
		if (CurrInd + 1 >= MaxSize)
			throw ("Overflow");
		CurrInd++;
		pMem[CurrInd] = el;
	}
	T Pop() {
		if (CurrInd == -1)
			throw ("Stack is empty");
		CurrInd--;
		return pMem[CurrInd + 1];
	}
	
	void Clear() {
		CurrInd = -1;
		delete[] pMem;
	}
	
	/*friend istream& operator>>(istream& in, TStack& s) {
		for (int i = 0; i < s.MaxSize; i++)
			in >> s.pMem[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, const TStack& s) {
		if (s.CurrInd == -1) {
			out << "Stack Is Empty" << endl;
		}
		else {
			for (int i = 0; i < s.CurrInd; i++)
				out << s.pMem[i] << ' ';
			out << endl;
		}
		return out;
	}
	*/
};

