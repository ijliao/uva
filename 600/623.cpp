#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 2000;

class BigNum {
public:
	int digit[MAX];
	int nDigit;

	BigNum(void) : nDigit(0)
	{
		for (int i = 0; i < MAX; i++)
			digit[i] = 0;
	}

	BigNum(int x) : nDigit(0)
	{
		while (x) {
			digit[nDigit++] = x % 10;
			x /= 10;
		}

		for (int i = nDigit; i < MAX; i++)
			digit[i] = 0;
	}
  
	BigNum& operator*=(int x)
	{
		int i;

		for (i = 0; i < nDigit; i++)
			digit[i] *= x;

		for (i = 0; i < nDigit; i++) {
			digit[i + 1] += digit[i] / 10;
			digit[i] %= 10;
		}

		for (; digit[i] > 0; i++) {
			nDigit++;
			digit[i + 1] += digit[i] / 10;
			digit[i] %= 10;
		}

		return *this;
	}

	friend ostream& operator<<(ostream& os, BigNum& num) {
		for (int i = num.nDigit - 1; i >= 0; i--)
			os << num.digit[i];

		return os;
	}
};

int main(void)
{
	while (true) {
		int n;

		cin >> n;
		if (cin.eof())
			break;

		BigNum* num = new BigNum(n);

		for (int i = n - 1; i >= 2; i--)
			(*num) *= i;

		cout << n << '!' << endl << *num << endl;
		delete num;
	}

	return 0;
}
