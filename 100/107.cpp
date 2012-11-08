#include <iostream>
#include <vector>

using namespace std;

typedef pair < int, int > PAIR;

vector < PAIR > tbl;
long H, N;

inline int gcd(int m, int n)
{
        return (!n) ? m : gcd(n, m % n);
}

long pow(long x, int y)
{
	long tmp = 1;

	while (y > 0) {
		if (y & 0x01UL)
			tmp *= x;

		x *= x;
		y >>= 1;
	}

	return tmp;
}

void output(long height, long n)
{
	long nowork = 0, stkhei = 0, now = 1;

	while (true) {
		if (height == 1)
			break;

		nowork += now;
		stkhei += now * height;
		height /= n;
		now *= (n - 1);
	}

	stkhei += now * height;

	cout << nowork << ' ' << stkhei << endl;
}

void cat(void)
{
	long h = H;

	int i, count = 0, curr = -1;
	for (i = 0; ((h & 0x01UL) == 0) && (h > 1); h >>= 1, i++)
		;

	if (i) {
		count++;
		tbl.push_back(PAIR(2, i));
	}

	curr = (curr == -1) ? i : gcd(curr, i);

	for (int k = 3; k <= h; k += 2) {
		for (i = 0; ((h % k) == 0) && (h > 1); h /= k, i++)
			;

		if (i) {
			count++;
			tbl.push_back(PAIR(k, i));
		}

		curr = (curr == -1) ? i : gcd(curr, i);
	}

	for (i = curr; i > 0; i--) {
		int tmp = 1;

		if ((curr % i) == 0) {
			for (int j = 0; j < count; j++)
				tmp *= pow(tbl[j].first, tbl[j].second / i);

			if (pow(tmp - 1, i) == N) {
				output(H, tmp);
				return;
			}
		}
	}
}

int main(void){
	while (true) {
		cin >> H >> N;
		if (!H && !N)
			break;

		tbl.clear();
		cat();
	}

	return 0;
}
