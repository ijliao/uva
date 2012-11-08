#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>

using namespace std;

double x, y;

void move(char* s)
{
	char* p = s;

	while (isdigit(*p))
		p++;

	char dir[3];
	strcpy(dir, p);
	*p = '\0';

	double len = double(atoi(s));
	if (strlen(dir) == 2)
		len = sqrt(len * len / 2);

	for (int i = 0; i < 2; i++) {
		switch (dir[i]) {
			case '\0': break;
			case 'N' : y += len; break;
			case 'S' : y -= len; break;
			case 'E' : x += len; break;
			case 'W' : x -= len; break;
		}
	}
}

void route(char* tmp)
{
	char* p;

	p = strtok(tmp, ",.");
	move(p);

	while (true) {
		p = strtok(NULL, ",.");
		if (p == NULL)
			break;

		move(p);
	}
}

void out(int count)
{
	cout.setf(ios::showpoint | ios::fixed);      
	cout << "Map #" << count << endl;
	cout << "The treasure is located at (" << setprecision(3) << x << ',' << setprecision(3) <<  y << ")." << endl;
	cout << "The distance to the treasure is " << setprecision(3) << sqrt(x * x + y * y) << "." << endl << endl;
}

int main(void)
{
	int count = 1;

	while (true) {
		char s[201];

		cin.getline(s, sizeof s);
		if (strcmp(s, "END") == 0)
			break;

		x = y = 0;
		route(s);
		out(count++);
	}

	return 0;
}
