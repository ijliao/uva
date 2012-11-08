#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef pair < string, string > PAIR;

vector < string > ignore;
vector < PAIR > title;

bool operator<(PAIR x, PAIR y)
{
	return (strcmp(x.first.c_str(), y.first.c_str()) < 0) ? true : false;
}

void tolower(string& s)
{
	int n = s.length();

	for (int i = 0; i < n; i++)
		if (s[i] <= 'Z' && s[i] != ' ')
			s[i] += 32;
}

void toupper(string& s)
{
	int n = s.length();

	for (int i = 0; i < n; i++)
		s[i] -= 32;
}

void store(string& s)
{
	tolower(s);
	int n = s.length();

	for (int i = 0; i < n; i++) {
		char* tmp = new char[1000];
		strcpy(tmp, s.c_str());
		int save = i;

		while (s[i] != ' ' && s[i] != '\0')
			i++;

		string up(&tmp[save], &tmp[i]);
		if (find(ignore.begin(), ignore.end(), up) != ignore.end())
			continue;

		toupper(up);
		copy(up.begin(), up.end(), tmp + save);
		PAIR p(up, tmp);
		title.push_back(p);
	}
}

int main(void)
{
	while (true) {
		string tmp;

		cin >> tmp;
		if (tmp == "::")
			break;

		tolower(tmp);
		ignore.push_back(tmp);
	}

	while (true) {
		string tmp;

		getline(cin, tmp);
		if (cin.eof())
			break;

		store(tmp);
	}

	stable_sort(title.begin(), title.end());
	for (int i = 0; i < title.size(); i++)
		cout << title[i].second << endl;

	return 0;
}
