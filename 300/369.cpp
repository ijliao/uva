#include <iostream>
#include <vector>

using namespace std;

unsigned long cnr(int n, int r)
{
	vector < unsigned long > t(n);

	for (int i = 0; i <= r; i++)
		t[i] = 1;

	for (int i = 1; i <= n - r; i++)
		for (int j = 1; j <= r; j++)
			t[j] += t[j - 1];

	return t[r];
}

int main(void)
{
	while (true) {
		int n, k;

		cin >> n >> k;
		if (!n && !k)
			break;
		cout << n << " things taken " << k << " at a time is " << cnr(n, k) << " exactly." << endl;
	}

	return 0;
}
