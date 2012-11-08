#include <iostream>
#include <algorithm>

using namespace std;

int N;
char table[] = {
	'a', 'b', 'c', 'd', 'e', 'f'
};

void output(void)
{
	cout << "writeln(";

	copy(table, table + N - 1, ostream_iterator < char > (cout, ","));
	cout << table[N - 1];

	cout << ")" << endl;
}

void tab(int n) {
	for (int i = 0; i < n - 1; i++)
		cout << "  ";
}

void loop(int n)
{
	if (n == N + 1) {
		tab(n);
		output();
	}
	else {
		tab(n);
		cout << "if " << table[n - 2] << " < " <<
			table[n - 1] << " then" << endl;
		loop(n + 1);

		for (int i = n - 2; i >= 0; i--) {
			swap(table[i + 1], table[i]);
			tab(n);
			cout << "else ";
			if (i) {
				cout << "if " << table[i - 1] << " < " <<
					table[i] << " then" << endl;
			}
			else
				cout << endl;

			loop(n + 1);
		}

		for (int i = 0; i <= n - 2; i++)
			swap(table[i], table[i + 1]);
	}
}

int main(void)
{
	cin >> N;

	cout << "program sort(input,output);" << endl;
	cout << "var" << endl;

	copy(table, table + N - 1, ostream_iterator < char > (cout, ","));
	cout << table[N - 1];

	cout << " : integer;" << endl;
	cout << "begin" << endl;

	cout << "  readln(";

	copy(table, table + N - 1, ostream_iterator < char > (cout, ","));
	cout << table[N - 1];

	cout << ");" << endl;

	loop(2);
	cout << "end." << endl;

	return 0;
}
