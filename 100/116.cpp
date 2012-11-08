#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int row, col;

inline long _min(long a, long b, long c)
{
	return min(min(a, b), c);
}

void travel(vector < vector < long > > &matrix, vector < vector < int > > &from)
{
	for (int i = col - 2; i >= 0; i--) {
		for (int j = row - 1; j >= 0; j--) {
			int a = matrix[(j + row - 1) % row][i + 1],
			    b = matrix[j][i + 1],
			    c = matrix[(j + 1) % row][i + 1];

			int m = _min(a, b, c);
			matrix[j][i] += m;

			int temp = LONG_MAX;

			if (m == a)
				temp = (j + row - 1) % row;

			if ((m == b) && (j < temp))
				temp = j;

			if ((m == c) && (((j + 1) % row) < temp))
				temp = (j + 1) % row;

			from[j][i] = temp;
		}
	}
}

long back(vector < vector < long > > &matrix, vector < vector < int > > &from)
{
	int minindex = 0;
	long minimum = matrix[0][0];

	for (int i = 1; i < row; i++) {
		if (matrix[i][0] < minimum) {
			minimum = matrix[i][0];
			minindex = i;      
		}
	}

	cout << minindex + 1;

	for (int i = 0; i < col - 1; i++) {
		cout << ' ';
		cout << from[minindex][i] + 1;
		minindex = from[minindex][i]; 
	}

	cout << endl;

	return minimum;
}

int main(void)
{
	while (true) {
		cin >> row >> col;
		if (cin.eof())
			break;

		vector < vector < long > > matrix(row, vector < long > (col));
		vector < vector < int > > from(row, vector < int > (col));

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> matrix[i][j];

		travel(matrix, from);
		cout << back(matrix, from) << endl;
	}

	return 0;
}
