#include <iostream>

using namespace std;

int bin[3][3];

void pack(void)
{
	char res[] = "   ";
	int max = 0;

	for (int B = 0; B < 3; B++) {
		for (int C = 0; C < 3; C++) {
			if (B == C)
				continue;

			int G = 3 - B - C;
			int tmp = bin[B][0] + bin[G][1] + bin[C][2];

			if (tmp > max) {
				max = tmp;
				res[B] = 'B';
				res[G] = 'G';
				res[C] = 'C';
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			sum += bin[i][j];

	cout << res << ' ' << sum - max << endl;
}

int main(void)
{
	while (true) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cin >> bin[i][j];

		if (cin.eof())
			break;

		pack();
	}

	return 0;
}
