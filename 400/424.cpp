#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigNum {
private:
	string content;
public:
	BigNum(string s) : content(s) { }
	void add(const BigNum&);
	int size(void) const { return content.size(); }
	char operator[](int n) const { return content[n]; }
	string& tostr(void) { return content; }
};

void BigNum::add(const BigNum& n)
{
	int n1 = content.size();
	int n2 = n.size();
	int pos1 = n1 - 1, pos2 = n2 - 1;
	int nres = max(n1, n2);
	bool over = false;
	char* tmp = new char[nres + 2];

	fill(tmp, tmp + nres + 2, '0'); tmp[nres + 1] = '\0';

	for (int i = nres; i > 0; i--) {
		int tmp1 = (pos1 >= 0) ? (content[pos1--] - '0') : 0;
		int tmp2 = (pos2 >= 0) ? (n[pos2--] - '0') : 0;
		int tmpr = tmp[i] - '0' + tmp1 + tmp2;
		tmp[i] = (tmpr % 10) + '0';
		tmp[i - 1] = (tmpr / 10) + '0';
	}

	content = (tmp[0] == '0') ? string(tmp + 1) : string(tmp);
}

int main(void)
{
	string s;
	BigNum n("0");

	while (true) {
		cin >> s;
		if (s == "0")
			break;

		n.add(s);
	}

	cout << n.tostr() << endl;

	return 0;
}
