#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

char				key[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector < string >	dic;
string				cipher;

inline int index(char c)
{
	return (c == ' ') ? 0 : (c - 'A' + 1);
}

inline char trans(char c, int i)
{
	return key[(index(c) + i) % 27];
}

void output(string s)
{
	int		counter = 0;
	char*	str = (char*)s.c_str();
	char*	ptr;

	ptr = strtok(str, " ");
	cout << ptr;
	counter = strlen(ptr);
	while ((ptr = strtok(NULL, " ")) != NULL) {
		if (counter + strlen(ptr) >= 60) {
			cout << endl;
			counter = strlen(ptr);
		}
		else {
			cout << ' ';
			counter += strlen(ptr) + 1;
		}

		cout << ptr;
	}

	cout << endl;
}

void solve(void)
{
	int		match[27];
	string	plain;

	for (int i = 0; i < 27; i++) {
		plain = cipher;

		for (int j = 0; j < plain.length(); j++)
			plain[j] = trans(plain[j], i);

		int		counter = 0;
		char*	str = (char*)plain.c_str();
		char*	ptr;

		ptr = strtok(str, " ");
		if (find(dic.begin(), dic.end(), ptr) != dic.end())
			counter++;

		while ((ptr = strtok(NULL, " ")) != NULL) {
			if (find(dic.begin(), dic.end(), ptr) != dic.end())
				counter++;
		}

		match[i] = counter;
	}

	int	K = max_element(match, match + 27) - match;
	plain = cipher;
	for (int i = 0; i < plain.length(); i++)
		plain[i] = trans(plain[i], K);

	output(plain);
}

int main(void)
{
	while (true) {
		string	tmp;

		getline(cin, tmp);
		if (tmp[0] == '#')
			break;

		dic.push_back(tmp);
	}

	getline(cin, cipher);

	solve();

	return 0;
}
