#include <iostream>

using namespace std;

unsigned long long cnr(unsigned long long n, unsigned long long r)
{
	if (r == 0)
		return 1;

	if (r == 1)
		return n;

	unsigned long long* c = new unsigned long long[r + 1];

	for (unsigned long long i = 0; i <= r; i++)
		c[i] = 1;

	for (unsigned long long i = 1; i <= n - r; i++)
		for (unsigned long long j = 1; j <= r; j++)
			c[j] += c[j - 1];

	return c[r];
}

int main(void)
{
	while (true) {
		unsigned long long n, k;

		cin >> n >> k;
		if (!n && !k)
			break;

		if (k > n / 2)
			k = n - k;

		cout << cnr(n, k) << endl;
	}

	return 0;
}
