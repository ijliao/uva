#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double				px1, py1, px2, py2;
vector < int >		score;

inline double inter(void)
{
	return -px1 * (px2 - px1) - py1 * (py2 - py1);
}

inline double distance(void)
{
	return px1 * px1 + py1 * py1;
}

int go(void)
{
	double		in = inter();
	double		dist = distance();

	if ((in >= 0.0) && (dist < 81.0))
		return 5;
	else if ((in >= 0.0) && (dist < 121.0))
		return 2;
	else if ((px2 * px2 + py2 * py2) < 201.0)
		return 1;
	else
		return 0;
}

void output(void)
{
	cout << "Turn Score" << endl;

	for (int i = 1; i <= score.size(); i++)
		cout << setw(3) << i << setw(4) << score[i - 1] << endl;
}

int main(void)
{
	while (true) {
		int		tmp = 0;

		for (int i = 0; i < 4; i++) {
			cin >> px1 >> py1 >> px2 >> py2;

			if (cin.eof()) {
				output();
				return 0;
			}

			tmp += go();
		}

		score.push_back(tmp);
	}

	return 0;
}
