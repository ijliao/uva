#include <iostream>
#include <vector>

using namespace std;

int		B, L, F;

int solve(void)
{
	vector < int > result;
	int carry = 0;
	int tmp;

	result.push_back(L);
	do {
		tmp = result[result.size() - 1] * F + carry;
		result.push_back(tmp % B);
		carry = tmp / B;
	} while ((carry != 0) || ((tmp % B) != L));

	return result.size() - 1;
}

int main(void)
{
	while (true) {
		cin >> B >> L >> F;
		if (cin.eof())
			return 0;

		cout << solve() << endl;
	}

	return 0;
}
