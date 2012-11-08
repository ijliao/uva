#include <iostream>
#include <string>

using namespace std;

unsigned long long pow(int base, int n)
{
	unsigned long long res = 1;

	for (int i = 0; i < n; i++)
		res *= base;

	return res;
}

unsigned long long atoi(string s, int base)
{
	int n = s.length();
	unsigned long long result = 0;

	for (int i = 0; i < n; i++) {
		char tmp = s[i];
		int mul;

		if (tmp >= 'A')
			mul = tmp - 'A' + 10;
		else
			mul = tmp - '0';

		result += mul * pow(base, n - i - 1);
	}

	return result;
}

void output(unsigned long long n, int base)
{
	char result[8];

	result[7] = '\0';
	for (int i = 6; i >= 0; i--) {
		int tmp = n % base;
		n /= base;
		if (tmp < 10)
			result[i] = tmp + '0';
		else
			result[i] = tmp - 10 + 'A';

		if (n == 0) {
			for (int j = 0; j < i; j++)
				result[j] = ' ';

			break;
		}
	}

	if (n != 0)
		cout << "  ERROR" << endl;
	else
		cout << result << endl;
}

int main(void)
{
	while (true) {
		string n;
		int fromb, tob;
		unsigned long long N;

		cin >> n >> fromb >> tob;
		if (cin.eof())
			break;

		N = atoi(n, fromb);
		output(N, tob);
	}

	return 0;
}
