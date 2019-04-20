#include "dsa\src\vector\vector.h"

//����ջ��ģ����
template <typename T> class Stack :public Vector<T> {
public:
	void push(T const & e) { insert(size(), e); }
	T pop() { return remove(size() - 1); }
	T& top() { return (*this)[size() - 1]; }

	void print() {
		for (__int64 i = size() - 1; i != -1; std::cout << (*this)[i--]);
		std::cout << std::endl;
	}
};

//Ӧ��1���������
// ����ת��
void convert(Stack<char>& S, __int64 n, int base) {
	static char digit[] =
	{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (n>0)
	{
		int remainder = (int)(n%base);
		S.push(digit[remainder]);
		n /= base;
	}
}

//Ӧ��2: �ݹ�Ƕ��
//ջ��ϴ
bool paren(const char exp[], int lo, int hi) {
	Stack<char> S;
	for (int i = lo; i <= hi; i++) {
		switch (exp[i])
		{
		case'(':case'[':case'{':S.push(exp[i]); break;
		case')':if ((S.empty()) || ('(' != S.pop()))return false; break;
		case']':if ((S.empty()) || (']' != S.pop()))return false; break;
		case'}':if ((S.empty()) || ('}' != S.pop()))return false; break;
		default:
			break;
		}
	}
	return S.empty();
}

//Ӧ��3: �ӳٻ���

void chap4_stack() {
	int n;
	Stack<char> nbase;
	string s;
	cin >> s;
	string::size_type ls = s.length();
	const char *sc = s.c_str();
	bool prn = paren(sc, 0, ls);
	std::cout << prn << std::endl;
}