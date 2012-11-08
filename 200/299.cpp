#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;

int train(vector < int > &table)
{
	int n = table.size();
	int count = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			if (table[j] < table[i]) {
				swap(table[i], table[j]);
				count++;
			}

	return count;
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> L;

		vector < int > table(L);

		for (int j = 0; j < L; j++)
			cin >> table[j];

		cout << "Optimal train swapping takes " << train(table) <<
			" swaps." << endl;
	}

	return 0;
}
