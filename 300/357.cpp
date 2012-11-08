#include <iostream>

using namespace std;

enum {
	PENNY = 1, NICKEL = 5, DIME = 10, QUARTER = 25, HALF = 50
};

int coins[5]={
	HALF, QUARTER, DIME, NICKEL, PENNY
};

int change(int res, int n)
{
	if (res == 0)
		return 1;

	int result = 0;

	for (int i = n; i < 5; i++)
		if (res >= coins[i])
			result += change(res - coins[i], i);

	return result;
}
 
int main(void)
{
	while (true) {
		int N;

		cin >> N;
		if (cin.eof())
			break;

		int way;
		if ((way = change(N, 0)) == 1) {
			cout << "There is only 1 way to produce " <<
				N << " cents change." << endl;
 		}
		else {
			cout << "There are " << way << " ways to produce " <<
				N << " cents change." << endl;
		}
	}

	return 0;
}
