#include <iostream>

using namespace std;

void output(int N[])
{
	bool printable = false;
	bool first = true;

	for (int i = 0; i < 9; i++) {
		if (N[i] != 0)
			printable = true;
		else
			continue;

		if (printable) {
			bool neg = false;

			if (N[i] == 0)
				continue;
			else if (N[i] < 0) {
				neg = true;
				N[i] *= -1;
			}

			if (!neg) {
				if (!first)
					cout << " + ";
			}
			else
				if (!first)
					cout << " - ";
				else
					cout << "-";

			if ((i == 8) || (N[i] != 1))
				cout << N[i];

			first = false;

			if (i < 7)
				cout << "x^" << 8 - i;
			else if (i == 7)
				cout << "x";
		}
	}

	if (!printable)
		cout << "0";

	cout << endl;
}

int main(void)
{
	while (true) {
		int N[9];

		for (int i = 0; i < 9; i++)
			cin >> N[i];

		if (cin.eof())
			break;

		output(N);
	}

	return 0;
}
