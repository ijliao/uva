#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X;
vector < int > card(20);

int lucky(vector < bool > &pos)
{
	int n = 0;

	for (int i = 0; i < N; i++)
		if (pos[i])
			n++;

	return n;
}

void MASH(vector < bool > &pos)
{
	int n = 0;

	while (true) {
		int cycle = card[n++];
		int tmp = 0;

		for (int i = 0; i < N; i++) {
			if (pos[i])
				tmp++;

			if ((tmp % cycle) == 0)
				pos[i] = false;

			if (lucky(pos) == X) {
				bool first = true;

				for (int j = 0; j < N; j++) {
					if (pos[j]) {
						if (!first)
							cout << ' ';
						else
							first = false;

						cout << j + 1;
					}
				}

				cout << endl << endl;
				return;
			}
		}
	}
}

int main(void)
{
	int sel = 1;

	while (true) {
		cin >> N >> X;
		if (cin.eof())
			break;

		vector < bool > pos(N);

		for (int i = 0; i < N; i++)
			pos[i] = true;

		for (int i = 0; i < 20; i++)
			cin >> card[i];

		cout << "Selection #" << sel++ << endl;
		MASH(pos);
	}

	return 0;
}
