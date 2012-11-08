#include <iostream>

using namespace std;

long H, U, D, F;

void solv(void)
{
	F = U * F; H *= 100; U *= 100; D *= 100;
	long i = 0, cur = 0;

	while (true) {
		i++;
		cur += U;
		if (cur > H) {
			cout << "success on day " << i << endl;
			break;
		}

		cur -= D;
		if (cur < 0) {
			cout << "failure on day " << i << endl;
			return;
		}

		U -= F;
		if (U < 0)
			U = 0;
	}
}

int main(void)
{
	while (true) {
		cin >> H >> U >> D >> F;
		if (H == 0)
			break;

		solv();
	}

	return 0;
}
