#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair < int, int > BOUND;

struct MAP {
	string name;
	int base;
	int size;
	int dim;
	BOUND *bound;
	int *C;
};

void findC(vector < MAP > &table)
{
	for (int j = 0; j < table.size(); j++) {
		int n = table[j].dim;

		table[j].C[n] = table[j].size;
		for (int i = n - 1; i > 0; i--)
			table[j].C[i] = table[j].C[i + 1] * (table[j].bound[i].second - table[j].bound[i].first + 1);

		int tmp = 0;
		for (int i = 1; i <= n; i++)
			tmp += table[j].C[i] * table[j].bound[i - 1].first;

		table[j].C[0] = table[j].base - tmp;
	}
}

void output(string s, vector < int > &vec, vector < MAP > &table, int n)
{
	cout << s << '[' << vec[0];
	for (int i = 1; i < vec.size(); i++)
		cout << ", " << vec[i];

	cout << "] = ";

	int addr = table[n].C[0];

	for (int i = 1; i <= vec.size(); i++)
		addr += vec[i - 1] * table[n].C[i];

	cout << addr << endl;
}

int main(void)
{
	int N, R;

	cin >> N >> R;

	vector < MAP > table(N);

	for (int i = 0; i < N; i++) {
		cin >> table[i].name >> table[i].base >> table[i].size >> table[i].dim;
		table[i].bound = new BOUND[table[i].dim];
		table[i].C = new int[table[i].dim + 1];
		for (int j = 0; j < table[i].dim; j++) {
			cin >> table[i].bound[j].first;
			cin >> table[i].bound[j].second;
		}
	}

	findC(table);

	for (int i = 0; i < R; i++) {
		string tmp;

		cin >> tmp;
		int j;
		for (j = 0; j < table.size(); j++)
			if (tmp == table[j].name)
				break;

		vector < int > vec(table[j].dim);
		for (int k = 0; k < vec.size(); k++)
			cin >> vec[k];

		output(tmp, vec, table, j);
	}
}

