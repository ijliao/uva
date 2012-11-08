#include <iostream>
#include <algorithm>

using namespace std;

int T;
int N;
int table[12];
int sol[12];
int n;
bool found;

void sum(int pos, int rest)
{
	if (rest == 0) {
		found = true;
		copy(sol, sol + n - 1, ostream_iterator < int > (cout, "+"));
		cout << sol[n - 1] << endl;
		return;    
	}

	for (int i = pos; i < N; i++) {
		while ((i != pos) && (table[i] == table[i - 1]))
			i++;

		if (table[i] <= rest) {
			sol[n] = table[i];
			n++;
			sum(i + 1, rest - table[i]);
			n--;
		}
	}
}

int main(void)
{
	while (true) {
		cin >> T >> N;
		if (!T && !N)
			break;

		for (int i = 0; i < N; i++)
			cin >> table[i];

		cout << "Sums of " << T << ":" << endl;    
		n = 0; found = false;
		sum(0, T);

		if (!found)
			cout << "NONE" << endl;
	}

	return 0;
}
