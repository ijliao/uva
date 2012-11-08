#include <iostream>

using namespace std;

unsigned long L, H, P, D;

unsigned long divisor(unsigned long n)
{
	int count = 0;
	unsigned long i;

	for (i = 1; i * i < n; i++)
		if ((n % i) == 0)
			count++;

	return count * 2 + (i * i == n);
}

void main(void)
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		P = 0; D = 0;
		cin >> L >> H;
		for (unsigned long j = L; j <= H; j++) {
			unsigned long tmp = divisor(j);

			if (tmp > D) {
				D = tmp;
				P = j;
			}
		}

		cout << "Between " << L << " and " << H << ", "
		     << P << " has a maximum of " << D << " divisors." << endl;
	}
}
