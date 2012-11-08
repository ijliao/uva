#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ISBN(string s)
{
	int n = s.length();
	vector < int > s1(81);
	int tmp = 0;

	s1[0] = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == ' ')
			continue;
		else if ((s[i] >= '0') && (s[i] <= '9')) {
			cout << s[i];
			s1[tmp + 1] = s1[tmp] + s[i] - '0';
			tmp++;
		}
		else if (s[i] == 'X') {
			cout << 'X';
			s1[tmp + 1] = s1[tmp] + 10;
			tmp++;
		}
		else
			cout << s[i];
	}

	if (tmp != 10) {
		cout << " is incorrect." << endl;
		return;
	}

	int s2 = 0;

	for (int i = 1; i <= 11; i++)
		s2 += s1[i];

	if ((s2 % 11) == 0)
		cout << " is correct." << endl;
	else
		cout << " is incorrect." << endl;
}

int main(void)
{
	while (true) {
		string s;

		getline(cin, s);
		if (cin.eof())
			break;

		ISBN(s);
	}

	return 0;
}
