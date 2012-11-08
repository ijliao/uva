#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const double rad = 6378;
const double PI = 3.141592653589793;

struct pos {
	string name;
	double lat, lon;
};

vector < pos > map;

int getno(string s)
{
	int n = map.size();

	for (int i = 0; i < n; i++)
		if (map[i].name == s)
			return i;

	return -1;
}

inline long round(double d)
{
	return long(floor(d + 0.5));
}

long dist(string from, string to)
{
	if (from == to)
		return 0;

	int fromno, tono;

	if (((fromno = getno(from)) == -1) || ((tono = getno(to)) == -1))
		return -1;

	double p = PI / 180;
	double fromla = map[fromno].lat * p, fromlo = map[fromno].lon * p;
	double tola = map[tono].lat * p, tolo = map[tono].lon * p;
	double x = (cos(fromla) * cos(fromlo) + cos(tola) * cos(tolo)) / 2;
	double y = (cos(fromla) * sin(fromlo) + cos(tola) * sin(tolo)) / 2;
	double z = (sin(fromla) + sin(tola)) / 2;
	double res = acos(sqrt(x * x + y * y + z * z)) * rad * 2;

	if (res > PI * rad)
		res = PI * rad * 2 - res;

	return round(res);
}

int main(void)
{
	while (true) {
		string s;
		double lat, lon;

		cin >> s;
		if (s == "#")
			break;

		cin >> lat >> lon;
		pos tmp;

		tmp.name = s; tmp.lat = lat; tmp.lon = lon;
		map.push_back(tmp);
	}

	while (true) {
		string s1, s2;

		cin >> s1 >> s2;
		if ((s1 == "#") && (s2 == "#"))
			break;

		cout << s1 << " - " << s2 << endl;
		long tmp;

		if ((tmp = dist(s1, s2)) == -1)
			cout << "Unknown" << endl;
		else
			cout << tmp << " km" << endl;
	}

	return 0;
}
