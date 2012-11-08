#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int N;
vector < string > table;

void proc(vector < string > &table)
{
	sort(table.begin(), table.end());

	int len = 0;
	for (int i = 0; i < N; i++)
		len = max((int)len, (int)table[i].length());

	int width = len + 2, ncol = (60 - len) / (len + 2) + 1;
	int nrow = (N / ncol) + !!(N % ncol);

	table.resize(nrow * ncol);

	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < ncol; j++)
			printf("%-*s", width, table[j * nrow + i].c_str());

		cout << endl;
	}
}

int main(void)
{
	char sep[61];
	memset(sep, '-', 60); sep[60] = '\0';

	while (!cin.eof()) {
		cin >> N;

		if (cin.eof())
			break;

		vector < string > table (N);
		for (int i = 0; i < N; i++)
			cin >> table[i];

		cout << sep << endl;

		proc(table);
	}

	return 0;
}
