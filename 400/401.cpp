#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char map[] = {
	'A', ' ', ' ', ' ', '3', ' ', ' ', 'H', 'I', 'L', ' ', 'J',
	'M', ' ', 'O', ' ', ' ', ' ', ' ', 'T', 'U', 'V', 'W', 'X',
	'Y', '5', '1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' '
};

bool pali(string s)
{
	string tmp(s);

	reverse(tmp.begin(), tmp.end());
	return (s == tmp);
}

bool mirror(string s)
{
	string tmp(s);

	reverse(tmp.begin(), tmp.end());
	int n = tmp.length();

	for (int i = 0; i < n; i++) {
		int pos;

		if (tmp[i] <= '9')
			pos = tmp[i] - '1' + 26;
		else
			pos = tmp[i] - 'A';

		tmp[i] = map[pos];
	}

	return (s == tmp);
}

int main(void)
{
	while (true) {
		string s;

		getline(cin, s);
		if (cin.eof())
			break;

		cout << s << " -- ";
		bool p = pali(s), m = mirror(s);

		if (p && m)
			cout << "is a mirrored palindrome." << endl << endl;
		else if (p && !m)
			cout << "is a palindrome." << endl << endl;
		else if (!p && m)
			cout << "is a mirrored string." << endl << endl;
		else if (!p && !m)
			cout << "is not a palindrome." << endl << endl;
	}

	return 0;
}
