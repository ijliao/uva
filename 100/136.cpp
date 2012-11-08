#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

inline bool isover(unsigned long m, unsigned long n)
{
	return ((ULONG_MAX / m) >= n);
}

int main(void)
{
	int n = 0;
	vector < unsigned long > ugly(2000);

	for (unsigned long i = 1; ; i *= 5) {
		for (unsigned long j = 1; ; j *= 3) {
			if (!isover(j, i))
				break;

			for (unsigned long k = 1; ; k <<= 1) {
				if (!isover(k, i) || !isover(k, j))
					break;

				if (!isover(j * k, i))
					break;

				ugly[n++] = i * j * k;

				if (!isover(k, 2UL))
					break;
			}

			if (!isover(j, 3UL))
				break;
		}

		if (!isover(i, 5UL))
			break;
	}

	sort(ugly.begin(), ugly.begin() + n);
	cout << "The 1500'th ugly number is " << ugly[1500 - 1] << ". " << endl;

	return 0;
}
