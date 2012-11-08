#include <iostream>
#include <vector>

using namespace std;

unsigned long long B, P, M;
vector < int > table(32);

void decomp(void)
{
	unsigned long long tmp = P;

	for (int i = 31; i >= 0; i--) {
		table[i] = tmp & 1;
		tmp >>= 1;
	}
}

void calc(void)
{
	decomp();

	unsigned long long result = 1, tmp = B;

	for (int i = 31; i >= 0; i--) {
		if (table[i] == 1)
			result = (result * tmp) % M;

		tmp = (tmp * tmp) % M;
	 }

	cout << result << endl;
}

int main(void)
{
	while (true) {
		cin >> B >> P >> M;
		if (cin.eof())
			break;

		calc();
	}

	return 0;
}
