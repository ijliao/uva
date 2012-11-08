#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <cstdio>

extern "C" {
	char *crypt(const char *key, const char *salt);
}

using namespace std;

string					pass;
vector < string >		map;

int						num[] = { 0, 2, 4, 8 };

inline void ins(char* s)
{
	int		len = strlen(s);

	if ((len <= 1) || (len > 5))
		return;

	string		str(s);

	if (find(map.begin(), map.end(), str) == map.end())
		map.push_back(str);
}

void check(char* s)
{
	if (!s)										// empty string
		return;

	int		leng = strlen(s);
	char	tmp[80];
	int		count = 0;

	for (int i = 0; i < leng; i++) {
		if (isalpha(s[i]))
			tmp[count++] = tolower(s[i]);
		else {
			tmp[count] = '\0';
			ins(tmp);
			count = 0;
		}
	}

	tmp[count] = '\0';
	ins(tmp);
}

void parse(string s)
{
	char*		input = (char*)s.c_str();
	char*		ptr;

	ptr = strtok(input, " ");
	check(ptr);

	while (ptr = strtok(NULL, " "))
		check(ptr);
}

void brute(void)
{
	int		size = map.size();

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			char	tmp[80];

			for (int k = 0; k < 4; k++) {
				sprintf(tmp, "%s%d%s", map[i].c_str(), num[k], map[j].c_str());

				int		len = strlen(tmp);

				if (len > 8)
					continue;
				else {
					char*	res = crypt(tmp, pass.c_str());

					if (pass == string(res)) {
						cout << tmp << endl;
						return;
					}
				}
			}
		}
	}
}

int main(void)
{
	cin >> pass;

	string		tmp;

	getline(cin, tmp);				// strip training '\n'

	do {
		getline(cin, tmp);
		parse(tmp);
	} while (!cin.eof());

	brute();

	return 0;
}
