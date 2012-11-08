#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
vector < unsigned long > table(10000);

inline bool ok(unsigned long m, unsigned long n)
{
	return ((ULONG_MAX / m) >= n);
}

void humble(void)
{
	int n = 0;

	for (unsigned long i = 1; ; i *= 7) {
		for (unsigned long j = 1; ; j *= 5) {
			if (!ok(j, i))
				break;

			for (unsigned long k = 1; ; k *= 3) {
				if (!ok(k, i) || !ok(k, j))
					break;

				if (!ok(j * k, i))
					break;

				for (unsigned long l = 1; ; l <<= 1) {
					if (!ok(l, i) || !ok(l, j) || !ok(l, k))
						break;

					if (!ok(k * l, i) || !ok(k * l, j))
						break;

					if (!ok(j * k * l, i))
						break;

					table[n++] = i * j * k * l;

					if (!ok(l, 2UL))
						break;
				}

				if (!ok(k, 3UL))
					break;
			}

			if (!ok(j, 5UL))
				break;
		}

		if (!ok(i, 7UL))
			break;
	}

	sort(table.begin(), table.begin() + n);
}

int main(void)
{
	char* suf[] = {"th", "st", "nd", "rd"};
	humble();

	while (true) {
		cin >> N;
		if ((N == 0) || cin.eof())
			break;

		cout << "The " << N;

		int tmp = N % 10;
		cout << ((((N % 100) / 10) == 1) ? "th" : ((tmp < 4) ? suf[tmp]
: "th"));
		cout << " humble number is " << table[N - 1] << '.' << endl;
	}

	return 0;
}
