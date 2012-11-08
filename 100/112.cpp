#include <iostream>
#include <cctype>

using namespace std;

int leftP = 0, rightP = 0;

int parse(int S)
{
	while (cin.get() != '(')
		;

	leftP++;

	char c;
	bool flag = true;
	int num = 0, left, right;
	while ((c = cin.get()) != ')') {
		if (isdigit(c)) {
			num = num * 10 + (c - '0');
			flag = false;
		}

		bool sign = false;
		if (c == '-')
			sign = true;

		if (cin.peek() == '(') {
			if (sign)
				num = -num;

			if ((left = parse(S - num)) > 0)
				return 1;

			if ((right = parse(S - num)) > 0)
				return 1;
		}
	}

	rightP++;

	if (flag)
		return -1;  
	else if ((left < 0) && (right < 0) && (num == S))
		return 1;
	else
		return 0;
}

void clear(void)
{
	while (leftP != rightP) {
		char c = cin.get();

		if (c == '(')
			leftP++;
		else if (c == ')')
			rightP++;
	}

	leftP = rightP = 0;
}

int main(void)
{
	while (true) {
		int S;

		cin >> S;
		if (cin.eof())
			break;

		cout << ((parse(S) > 0) ? "yes" : "no") << endl;

		clear();
	}

	return 0;
}
