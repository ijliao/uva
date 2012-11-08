#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

unsigned long long table[52];

void reset(void)
{
	for (int i = 0; i < 52; i++)
		table[i] = 0;
}

void freq(string s)
{
	unsigned long long n = s.length();

	for (unsigned long long i = 0; i < n; i++) {
		int tmp = s[i];

		if (tmp >= 'A' && tmp <= 'Z')
			table[tmp - 'A']++;
		else if (tmp >= 'a' && tmp <= 'z')
			table[tmp - 'a' + 26]++;
	}
}

void output(void)
{
	unsigned long long big = 0;

	for (int i = 0; i < 52; i++)
		big = max(big, table[i]);

	for (int i = 0; i < 26; i++)
		if (table[i] == big)
			cout << char(i + 'A');

	for (int i = 26; i < 52; i++)
		if (table[i] == big)
			cout << char(i - 26 + 'a');

	cout << " " << big << endl;
}

int main(void)
{
	while (true) {
		string s;

		getline(cin, s);
		if (cin.eof())
			break;

		reset();
		freq(s);
		output();
	}

	return 0;
}
