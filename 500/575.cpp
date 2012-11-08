#include <iostream>
#include <string>

using namespace std;

inline unsigned long skew(int n)
{
	return (1 << n) - 1;
}

void calc(string s)
{
	int n = s.length();
	unsigned long result = 0;

	for (int i = 0; i < n; i++)
		result += (unsigned long)(s[i] - '0') * skew(n - i);

	cout << result << endl;
}

int main(void)
{
	while (!cin.eof()) {
		string skew;

		cin >> skew;
		if (skew == "0")
			break;

		calc(skew);
	}

	return 0;
}
