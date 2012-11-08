#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, H, V, S;
vector< int > table; 

int calc(int n)
{
	int res = 0;
	int tmp = n;

	do {
		res++;
		n = (n % 2) ? (3 * n + 1) : (n / 2);
		if (n > 1 && n < H && table[n] != 0) {
			res += table[n];
			break;
		}
	} while (n != 1);

	table[tmp] = res;

	return res;
}

int main(void)
{
	while (!cin.eof()) {
		cin >> L >> H;
		if (cin.fail())
			break;

		if (L == 0 && H == 0)
			break;

		if (L > H)
			swap(L, H);

		V = L; S = 0;
		table = vector < int > (H + 1);
		for (int i = 0; i <= H; i++)
			table[i] = 0;

		for (int tmp = L; tmp <= H; tmp++) {
			int i = calc(tmp);

			if (S < i) {
				S = i;
				V = tmp;
			}
		}

		cout << "Between " << L << " and " << H << ", " << V << " generates the longest sequence of " << S << " values." << endl;
	}

	return 0;
}
