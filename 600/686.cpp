#include <iostream>
#include <vector>

using namespace std;

void init(int n, vector < bool > &prime)
{
	prime[0] = prime[1] = true;

	for (int i = 2; i <= n; i++) {
		while (prime[i] != false)
			i++;

		for (int j = 2 * i; j < n; j += i)
			prime[j] = true;
	}
}

int solve(int n, vector < bool > &prime)
{
	int x = 0;
  
	for (int i = 2; i <= n / 2; i++)
		if (prime[i] == false && prime[n - i] == false)
			x++;

	return x;
}

int main(void)
{
	while (true) {
		int n;

		cin >> n;
		if (!n)
			break;

		vector < bool > prime(n + 1, false);
		init(n, prime);

		cout << solve(n, prime) << endl;
	}

	return 0;
}
