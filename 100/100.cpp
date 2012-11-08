#include <iostream>
#include <algorithm>

using namespace std;

int calc(int n)
{
	int res = 1;

	while (n != 1) {
		res++;
		n = (n % 2) ? (3 * n + 1) : (n / 2);
	}

	return res;
}

int main(void)
{
	while (!cin.eof()) {
		int i, j;
		int maxium = 0;

		cin >> i >> j;
		if (cin.fail())
			break;

		cout << i << " " << j << " ";

		if (i > j)
			swap(i, j);

		for (int tmp = i; tmp <= j; tmp++)
			maxium = max(maxium, calc(tmp));

		cout << maxium << endl;
	}

	return 0;
}
