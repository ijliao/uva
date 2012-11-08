#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char screen[10][10];
int N;
int row, col;

void o_put(char), i_put(char);
typedef void (*pf)(char);

enum { OVER, INS };
int mode;
pf METHOD[] = { o_put, i_put };

void clear(void)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			screen[i][j] = ' ';
}

inline void begin(void) { col = 0; }
inline void erase(void) { for (int i = col; i < 10; i++) screen[row][i] = ' '; }
inline void home(void) { row = col = 0; }
inline void insert(void) { mode = INS; }
inline void over(void) { mode = OVER; }
inline void up(void) { row = max(0, row - 1); }
inline void down(void) { row = min(9, row + 1); }
inline void left(void) { col = max(0, col - 1); }
inline void right(void) { col = min(9, col + 1); }
inline void move(char x, char y) { row = x - '0'; col = y - '0'; }
inline void o_put(char x) { screen[row][col] = x; right(); }

void output(int);

void i_put(char x)
{
	for (int i = 9; i > col; i--)
		screen[row][i] = screen[row][i - 1]; 

	o_put(x);
}

void proc(string s)
{
	int n = s.length();

	for (int i = 0; i < n; i++) {
		if (s[i] != '^')
			(*METHOD[mode])(s[i]);
		else {
			switch (s[++i]) {
				case 'b' : begin(); break;
				case 'c' : clear(); break;
				case 'd' : down(); break;
				case 'e' : erase(); break;
				case 'h' : home(); break;
				case 'i' : insert(); break;
				case 'l' : left(); break;
				case 'o' : over(); break;
				case 'r' : right(); break;
				case 'u' : up(); break;
				case '^' : (*METHOD[mode])('^'); break;
				default : move(s[i], s[i + 1]); i++; break;
			}
		}
	}
}

void output(int n)
{
	cout << "Case " << n << endl;

	cout << "+----------+" << endl;

	for (int i = 0; i < 10; i++) {
		cout << "|";

		for (int j = 0; j < 10; j++)
			cout << screen[i][j];

		cout << "|" << endl;
	}

	cout << "+----------+" << endl;
	cout << endl;
}

int main(void)
{
	int counter = 1;

	while (true) {
		cin >> N;
		if (!N)
			break;

		clear(); home(); mode = OVER;

		string tmp;
		getline(cin, tmp);
		for (int i = 0; i < N; i++) {
			getline(cin, tmp);
			proc(tmp);
		}

		output(counter++);
	}

	return 0;
}
