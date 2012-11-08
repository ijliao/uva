#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int prime[] = {
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
};

int factor[25];
int N;

int main(void)
{
	while (true) {
		cin >> N;
		if (N == 0)
			break;

		cout << setw(3) << N << "! =";

		int i;

		for (i = 0; i < 25; i++)
			factor[i] = 0;

		for (i = 0; i < 25; i++) {
			if (N < prime[i])
				break;

			int exam = N;

			do {
				factor[i] += exam / prime[i];
				exam /= prime[i];
			} while (exam >= 1);
		}

		for (int j = 0; j < i; j++) {
			if (j == 15)
				cout << endl << "      ";

			cout << setw(3) << factor[j];
		}

		cout << endl;
	}

	return 0;
}
