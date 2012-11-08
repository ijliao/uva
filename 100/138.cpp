#include <iostream>
#include <iomanip>

using namespace std;

unsigned long A(int n)
{
	static unsigned long table[10] = {6, 35};

	if (table[n] == 0)
		table[n] = 6 * table[n - 1] - table[n - 2];

	return table[n];
}

unsigned long B(int n)
{
	static unsigned long table[10] = {8, 49};

	if (table[n] == 0)
		table[n] = 6 * table[n - 1] - table[n - 2] + 2;

	return table[n];
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		cout << setw(10) << A(i) << setw(10) << B(i) << endl;

	return 0;
}
