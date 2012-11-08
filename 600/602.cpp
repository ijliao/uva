#include <iostream>
#include <string>

using namespace std;

int dayinmon[] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

string monname[] = {
	"", "January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

string week[] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

inline bool isleap(int year)
{
	if ((year <= 1752) && ((year % 4) == 0))
		return true;
	else if (year <= 1752)
		return false;
	else if ((year % 400) == 0)
		return true;
	else if ((year % 100) == 0)
		return false;
	else if ((year % 4) == 0)
		return true;
	else
		return false;
}

inline int dayin(int day, int month, int year)
{
	if ((day >= 3) && (day <= 13) && (month == 9) && (year == 1752))
		return -1;
	else if (month > 12)
		return -1;
	else if (month == 2)
		return 28 + isleap(year);
	else
		return dayinmon[month];
}

int solve(int day, int month, int year)
{
	int result = 6;
 
	for (int i = 1; i < year; i++) {
		result = (result + 1 + isleap(i)) % 7;
		if (i == 1752)
			result += 3;
	}

	for (int i = 1; i < month; i++) {
		result = (result + dayin(1, i, year)) % 7;
		if ((i == 9) && (year == 1752))
			result += 3;
	}
  
	for (int i = 1; i < day; i++) {
		result++;
		if ((month == 9) && (year == 1752) && (i == 2))
			i += 11;
	}

	result %= 7;

	return result;
}

int main(void)
{
	while (true) {
		int d, m, y;

		cin >> m >> d >> y;
		if (!m && !d && !y)
			break;

		if (d > dayin(d, m, y)) {
			cout << m << "/" << d << "/" << y
			     << " is an invalid date." << endl;
		}
		else {
			cout << monname[m]  << " "  << d << ", " << y
			     << " is a " << week[solve(d, m, y)] << endl;
		}
	}

	return 0;
}
