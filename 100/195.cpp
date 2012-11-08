#include <iostream>
#include <string>
#include <algorithm>

int main(void)
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;

		cin >> s;
		sort(s.begin(), s.end());

		cout << s << endl;
		while (next_permutation(s.begin(), s.end()))
			cout << s << endl;
	}

	return 0;
}
