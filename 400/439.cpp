#include <iostream>
#include <queue>

using namespace std;

struct pos {
	int x, y, step;
};

struct dir {
	int x, y;
};

queue < pos > q;
pos from, to;
dir d[8] = {
	{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

bool map[8][8];

inline bool isequal(pos i, pos j)
{
	return ((i.x == j.x) && (i.y == j.y));
}

inline pos move(pos p, dir d)
{
	pos r;

	r.x = p.x + d.x;
	r.y = p.y + d.y;
	r.step = p.step + 1;

	return r;
}

inline bool isvalid(pos p)
{
	return ((p.x >= 0) && (p.x < 8) && (p.y >= 0) && (p.y < 8));
}

inline void save(pos p)
{
	if (!map[p.x][p.y]) {
		map[p.x][p.y] = true;
		q.push(p);
	}
}

int knight(void)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			map[i][j] = false;

	while (!q.empty())
		q.pop();

	save(from);

	while (!q.empty()) {
		pos now = q.front(); q.pop();

		if (isequal(now, to))
			return now.step;

		for (int i = 0; i < 8; i++) {
			pos tmp = move(now, d[i]);

			if (isvalid(tmp))
				save(tmp);
		}
	}
}

int main(void)
{
	while (true) {
		char tmp1[3], tmp2[3];

		cin >> tmp1 >> tmp2;
		if (cin.eof())
			break;

		from.x = tmp1[0] - 'a'; from.y = tmp1[1] - '1'; from.step = 0;
		to.x = tmp2[0] - 'a';   to.y = tmp2[1] - '1';   to.step = 0;
		cout << "To get from " << tmp1 << " to " << tmp2 <<
			" takes " << knight() << " knight moves." << endl;
	}

	return 0;
}
