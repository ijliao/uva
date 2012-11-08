#include <iostream>

using namespace std;

const int MAX = 50;

enum {
	RIGHT = 1, DOWN = 2, LEFT = 4, UP = 8
};

class point {
public:
	int value;
	int cost;
	int acceptedbump;

	Pointinfo(void) { value = cost = acceptedbump = 0; }
};

point surf[MAX][MAX];
int m, n;

int main(void)
{
	int allpoint = 0, cost;

	cin >> m >> n >> cost;

	for (int i = 0; i < n; i++) {
		surf[0][i].cost = cost;
		surf[0][i].acceptedbump |= LEFT;
		surf[m - 1][i].cost = cost;
		surf[m - 1][i].acceptedbump |= RIGHT;
	}

	for (int i = 0; i < m; i++) {
		surf[i][0].cost = cost;
		surf[i][0].acceptedbump |= DOWN;
		surf[i][n - 1].cost = cost;
		surf[i][n - 1].acceptedbump |= UP;
	}

	int p;
	cin >> p;

	for (int i = 0; i < p; i++) {
		int x, y;

		cin >> x >> y;
		cin >> surf[x - 1][y - 1].value >> surf[x - 1][y - 1].cost;
		surf[x - 1][y - 1].acceptedbump |= RIGHT | LEFT | UP | DOWN;
	}

	while (true) {
		int x, y, dir, life, point = 0;

		cin >> x >> y >> dir >> life;
		if (cin.eof())
			break;

		switch (dir) {
			case 0 : dir = RIGHT; break;
			case 1 : dir = UP; break;
			case 2 : dir = LEFT; break;
			case 3 : dir = DOWN; break;
		}

		while (life > 0) {
			life--;

			switch (dir) {
				case RIGHT : x++; break;
				case UP : y++; break;
				case LEFT : x--; break;
				case DOWN : y--; break;
			}

			if (dir & surf[x - 1][y - 1].acceptedbump) {
				life -= surf[x - 1][y - 1].cost;

				if (life > 0) {
					point += surf[x - 1][y - 1].value;

					switch (dir) {
						case RIGHT : x--; break;
						case UP : y--; break;
						case LEFT : x++; break;
						case DOWN : y++; break;
					}

					dir <<= 1;
					if (dir == 16)
						dir = RIGHT;
				}
			}
		}

		cout << point << endl;
		allpoint += point;
	}

	cout << allpoint << endl;

	return 0;
}
