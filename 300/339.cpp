#include <iostream>

int M, N;
int table[20][50];

inline bool isregion(int x, int y)
{
	if ((x > 0) && (table[x - 1][y] == table[x][y]))
		return true;

	if ((y > 0) && (table[x][y - 1] == table[x][y]))
		return true;

	if (table[x][y + 1] == table[x][y])
		return true;

	if (table[x + 1][y] == table[x][y])
		return true;

	return false;
}

inline bool isvalid(int x, int y)
{
	return ((x <= M) && (x > 0) &&
		(y <= N) && (y > 0) &&
		(table[x - 1][y - 1] >= 0) &&
		(isregion(x - 1, y - 1)));
}

void mark(int x, int y)
{
	int t = table[x][y];

	table[x][y] = -1;

	if ((x < 0) || (y < 0))
		return;

	if ((x > 0) && (table[x - 1][y] == t))
		mark(x - 1, y);

	if ((y > 0) && (table[x][y - 1] == t))
		mark(x, y - 1);

	if (table[x][y + 1] == t)
		mark(x, y + 1);

	if (table[x + 1][y] == t)
		mark(x + 1, y);
}

void remcol(int y)
{
	int index = 0;

	for (int i = 0; i < M; i++)
		if (table[i][y] >= 0)
			table[index++][y] = table[i][y];

	for (int i = index; i < M; i++)
		table[i][y] = -1;
}

void remrow(void)
{
	int index = 0;

	for (int j = 0; j < N; j++) {
		if (table[0][j] >= 0) {
			for (int i = 0; i < M; i++)
				table[i][index] = table[i][j];

			index++;
		}
	}

	N = index;  
}

void fit(void)
{  
	for (int j = 0; j < N; j++)
		remcol(j);

	remrow();
}

void output(int n)
{
	cout << "Grid " << n << "." << endl;

	int i, j;

	for (i = M - 1; i >= 0; i--) {
		for (j = N - 1; j >= 0; j--)
			if (table[i][j] >= 0)
				break;

		if (j >= 0)
			break;
	}

	if ((i < 0) || (j < 0))
		cout << "    Game Won" << endl;
	else {
		for (int x = M - 1; x > i; x--)
			cout << endl;

		for (int x = i; x >= 0; x--) {
			cout << "    ";
			for (int y = 0; y < N; y++) {
				if (y)
					cout << " ";  

				if (table[x][y] >= 0)
					cout << table[x][y];
				else
					cout << " ";
			}

			cout << endl;
		}
	}
}

int main(void)
{
	int count = 0;

	while (true) {
		cin >> M >> N;
		if (!M && !N)
			break;

		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 50; j++)
				table[i][j] = -1;

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				cin >> table[i][j];

		while (true) {
			int x, y;

			cin >> x >> y;
			if (!x && !y)
				break;

			if (isvalid(x, y))
				mark(x - 1, y - 1);

			fit();
		}

		output(++count);
		cout << endl;
	}

	return 0;
}
