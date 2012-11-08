#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string			in1, in2;
int				num1, num2;
vector < int >	fact;
int				pos;

inline int atoi(char c)
{
	switch (c) {
		case '|' : return 1;
		case 'n' : return 10;
		case '9' : return 100;
		case '8' : return 1000;
		case 'r' : return 10000;
		default : return 0;
	}
}

void stoi(void)
{
	num1 = num2 = 0;

	for (int i = 0; i < in1.length(); i++)
		num1 += atoi(in1[i]);

	for (int i = 0; i < in2.length(); i++)
		num2 += atoi(in2[i]);
}

void factor(void)
{
	fact.clear();

	int		tmp = num2;

	for ( ; tmp != 0; tmp /= 2)
		fact.push_back(tmp % 2);
}

inline char itoa(int n)
{
	switch (n) {
		case     1 : return '|';
		case    10 : return 'n';
		case   100 : return '9';
		case  1000 : return '8';
		case 10000 : return 'r';
	}
}

void itos(int n)
{
	int			base = 1;

	do {
		int		rem = n % 10;
		char	symbol = itoa(base);

		for (int i = 0; i < rem; i++) {
			cout << symbol;
		}

		if (rem > 0) {
			cout << ' ';
			pos++;
		}

		pos += rem;

		n /= 10;
		base *= 10;
	} while (n > 0);
}

void multi(void)
{
	factor();

	int		left = 1, right = num1;
	int		count = 0;

	do {
		pos = 1;
		itos(left % 100000);
		if (fact[count] == 1) {
			cout << '*';
			pos++;
		}

		for (int i = 0; i < 35 - pos; i++)
			cout << ' ';

		itos(right % 100000);
		cout << endl;

		left <<= 1;
		right <<= 1;
		count++;
	} while (left <= num2);

	cout << "The solution is: ";
	itos((num1 * num2) % 100000);
	cout << endl;
}

int main(void)
{
	while (true) {
		getline(cin, in1);
		getline(cin, in2);
		if (cin.eof())
			break;

		stoi();
		multi();
	}

	return 0;
}
