#include <iostream>
#include <vector>

using namespace std;

int N;

void fib(int N)
{
	vector < int > t (N + 1);

	t[0] = 0; t[1] = 1;
	for (int i = 2; i <= N; i++)
		t[i] = t[i - 1] + t[i - 2];

	cout << "The Fibonacci number for " << N << " is " << t[N] << endl;
}

int main(void)
{
	while (!cin.eof()) {
		cin >> N;
		if (cin.eof())
			break;

		fib(N);
	}

	return 0;
}
