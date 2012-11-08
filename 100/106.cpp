#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int N;

inline int gcd(int m, int n)
{
	return (!n) ? m : gcd(n, m % n);
}

inline bool isok(int x, int y, int z)
{
	return ((gcd(x, y) == 1) && (gcd(y, z) == 1) && (gcd(x, z) == 1));
}

void frem(void)
{
	vector < bool > p(N);

	fill(p.begin(), p.end(), true);

	int counter = 0;

	for (int z = N; z > 0; z--) {
		for(int y = z - 1; y > 0; y--) {
			int x = int(sqrt(double(z * z - y * y)));

			if (x * x + y * y == z * z) {
				p[x - 1] = p[y - 1] = p[z - 1] = false;
	
				if (isok(x,y,z))
					counter++;
			}
		}
	}

	cout << counter / 2 << ' ' << count(p.begin(), p.end(), true) << endl;
}

int main(void)
{
	while (true) {
		cin >> N;
		if (cin.eof())
			break;

		frem();
	}

	return 0;
}
