#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int N;
int M;

inline int gcd(int i, int j)
{
	return (j == 0) ? i : gcd(j, i % j);
}

void calc(vector < int > &table)
{
	M = 0;

	for (int i = 0; i < table.size() - 1; i++)
		for (int j = i + 1; j < table.size(); j++)
			if (gcd(table[i], table[j]) == 1)
				M++;

	if (M == 0)
		cout << "No estimate for this data set." << endl;
	else {
		double pi = sqrt(double(6) * (N * (N - 1) / 2) / M);
		cout << setprecision(7) << pi << endl;
	}
}

int main(void)
{
	while (true) {
		cin >> N;
		if (N == 0)
			break;

		vector < int > table(N);

		for (int i = 0; i < N; i++)
			cin >> table[i];

		calc(table);
	}

	return 0;
}
