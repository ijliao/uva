#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[8];
int n;

long asc2int(void)
{
	long result = 0;

	for (int i = 0; i < n; i++) {
		result *= 10;
		result += s[i] - '0';
	}

	return result;
}

bool isvalid(void)
{
	bool digit[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	for (int i = 0; i < n; i++) {
		if (digit[s[i] - '0'])
			digit[s[i] - '0'] = false;
		else
			return false;
	}

	return true;
}

bool run(void)
{
	bool t[7] = {1, 1, 1, 1, 1, 1, 1};

	int pos = 0;
	t[pos] = false;

	for (int i = 0; i < n - 1; i++) {
		pos = (pos + s[pos] - '0') % n;
		if (!t[pos])
			return false;
	}

	pos = (pos + s[pos] - '0') % n;
	if (pos != 0)
		return false;

	return true;
}

int main(void)
{
	int time = 1;

	while (true) {
		cin.getline(s, sizeof s);
		if (strcmp(s, "0") == 0)
			break;

		n = strlen(s);
		long tmp = asc2int();

		do {
			do {
				sprintf(s, "%ld", tmp++);
			} while (!isvalid());
		} while (!run());

		cout << "Case " << time++ << ": " << s << endl;
	}

	return 0;
}
