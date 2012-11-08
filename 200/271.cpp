#include <iostream>
#include <cstring>

using namespace std;

int judge(char* s)
{
	if (*s == NULL)
		return 0;

	if ((s[0] >= 'p') && (s[0] <= 'z'))
		return 1;

	int n = strlen(s);

	switch (s[0]) {
		case 'N' :
			if (n < 2)
				return 0;

			return judge(s + 1) + 1;

		case 'C' : case 'D' : case 'E' : case 'I' :
			if (n < 3)
				return 0;

			int tmp = judge(s + 1);

			if (tmp > 0)
				return judge(s + tmp + 1) + tmp + 1;
	}

	return 0;
}

int main(void)
{
	while (true) {
		char s[257];

		cin.getline(s, sizeof s);
		if (cin.eof())
			break;

		if (judge(s) == strlen(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
