#include <iostream>

using namespace std;

int table[100][100];
int N;

bool even(void)
{
	for (int i = 0; i < N; i++) {
		int col = 0, row = 0;

		for (int j = 0; j < N; j++) {
			col += table[i][j];
			row += table[j][i];
		}

		if (((col % 2) != 0) || ((row % 2) != 0))
			return false;
	}

	return true;
}

bool canfix(void)
{
	for (int i = 0; i < N; i++) {
		int sum = 0;

		for (int j = 0; j < N; j++)
			sum += table[i][j];

		if ((sum % 2) != 0) {
			for (int j = 0; j < N; j++) {
				table[i][j] = !table[i][j];
				if (even()) {
					cout << "Change bit (" << i + 1 << "," << j + 1 << ")" << endl;
					return true;
				}
				else
					table[i][j] = !table[i][j];
			}
		}
	}

	return false;
}

int main(void)
{
	while (true) {
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> table[i][j];

		if (even())
			cout << "OK" << endl;
		else if (!canfix())
			cout << "Corrupt" << endl;
	}

	return 0;
}
