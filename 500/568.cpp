#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int		n;

	while (true) {
		cin >> n;

		if (cin.eof())
			break;

		long		last = 1; 

		for (int i = 1; i <= n; i++) { 
			long	tmp = i; 

			while (tmp % 5 == 0) { 
				tmp /= 5; 
				last >>= 1;
			} 

			last = (last % 100000) * tmp; 
		} 

		cout << setw(5) << n << " -> " << (last % 10) << endl;
	}

	return 0;
}
