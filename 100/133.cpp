#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int N;
unsigned long long k, m;
bool first;

bool isempty(vector < bool > &dole)
{
	for (int i = 0; i < N; i++)
		if (dole[i])
			return false;

	return true;
}

int lloop(vector < bool > &dole, int n)
{
	unsigned long long i = int(first);

	while (i != k) {
		n++;
		n %= N;
		if (dole[n])
			i++;
	}

	return n;
}

int rloop(vector < bool > &dole, int n)
{
	unsigned long long i = int(first);

	while (i != m) {
		n--;
		if (n < 0)
			n = N - 1;

		if (dole[n])
			i++;
	}

	return n;
}

void proc(vector < bool > &dole)
{
	int lptr = 0, rptr = N - 1;

	while (!isempty(dole)) {
		lptr = lloop(dole, lptr);
		rptr = rloop(dole, rptr);

		if (!first)
			cout << ",";
		else
			first = !first;

		if (lptr != rptr)
			cout << setw(3) << lptr + 1 << setw(3) << rptr + 1;
		else
			cout << setw(3) << lptr + 1;

		dole[lptr] = dole[rptr] = false;
	}

	cout << endl;
}

int main(void)
{
	while (true) {
		cin >> N >> k >> m;
		if (!N && !k && !m)
			break;

		vector < bool > dole(N);
		first = true;

		for (int i = 0; i < N; i++)
			dole[i] = true;

		proc(dole);
	}

	return 0;
}
