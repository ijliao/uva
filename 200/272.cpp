#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string tmp;
	bool even = false;

	while (true) {
		getline(cin, tmp);
		if (cin.eof())
			break;

		int n = tmp.length();

		for (int i = 0; i < n; i++)
			if (tmp[i] == '"') {
				if (!even)
					cout << "``";
				else
					cout << "\'\'";

				even = !even;
			}
			else
				cout << tmp[i];

		cout << endl;
	}

	return 0;
}
