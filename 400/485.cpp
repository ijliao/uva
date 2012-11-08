#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector < long > v;

	cout << "1" << endl;

	v.push_back(1);

	bool flag = false;
	while (true) {
		v.push_back(1);
		int n = v.size();

		for (int i = n - 2; i >= 0; i--)
			v[i] += v[i - 1];

		cout << v[0];
		for (int i = 1; i < n; i++) {
			cout << ' ' << v[i];

			if (v[i] >= 1000000)
				flag = true;
		}

		cout << endl;

		if (flag)
			break;
	}

	return 0;
}
