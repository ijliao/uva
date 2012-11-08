#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

void prime(int n, vector < int > &table)
{
	table.push_back(1);

	if (n > 2)
		table.push_back(2);
	else if (n > 1) {
		table.push_back(2);
		return;
	}
	else
		return;

	int tmp = (n - 3) / 2 + 1;
	vector < bool > sieve(tmp + 1);

	for (int i = 0; i < tmp; i++)
		sieve[i] = true;

	for (int i = 0; i < tmp; i++) {
		if (sieve[i]) {
			int prime = i + i + 3;

			for (int k = prime + i; k < tmp; k += prime)
				sieve[k] = false;
		}
	}

	for (int i = 0, k = 2; i <= tmp; i++)
		if (sieve[i])
			table.push_back(i + i + 3);
}

void output(vector < int > &table, int C)
{
	int n = table.size();
	int mid = (n - (n & 1)) / 2;
	int amount = C * 2 - (n & 1);
	int begin = mid - C + (n & 1);

	for (int i = max(begin, 0); i < min(begin + amount, n); i++)
		cout << ' ' << table[i];

	cout << endl;
}

int main(void)
{
	while (true) {
		cin >> N >> C;
		if (cin.eof())
			break;

		vector < int > table;

		prime(N, table);
		cout << N << ' ' << C << ':';
		output(table, C);
	}

	return 0;
}
