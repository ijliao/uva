#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

double P, U, I;
int res;

void parse(string str, unsigned long pos)
{
	const char* s = str.c_str();
	double* target;

	switch (s[pos - 1]) {
		case 'P' : case 'p' : target = &P; res -= 1; break;
		case 'U' : case 'u' : target = &U; res -= 2; break;
		case 'I' : case 'i' : target = &I; res -= 3; break;
	}

	unsigned long end;
	for (end = pos + 1; ; end++)
		if (!isdigit(s[end]) && (s[end] != '.'))
			break;

	char* tmp = new char[1000];
	strncpy(tmp, s + pos + 1, end - pos - 1);

	*target = strtod(tmp, (char**)NULL);

	switch (s[end]) {
		case 'm' : *target *= 0.001; break;
		case 'k' : *target *= 1000; break;
		case 'M' : *target *= 1000000; break;
	}
}

void proc(string s, unsigned long counter)
{
	res = 6;

	unsigned long n = s.length();
	for (unsigned long i = 0; i < n; i++)
		if (s[i] == '=')
			parse(s, i);

	cout << "Problem #" << counter << endl;

	cout.setf(ios::showpoint | ios::fixed);

	switch (res) {
		case 1 :
			cout << "P=" << setprecision(2) << U * I << "W";
			break;
		case 2 :
			cout << "U=" << setprecision(2) << P / I << "V";
			break;
		case 3 :
			cout << "I=" << setprecision(2) << P / U << "A";
			break;
	}

	cout << endl << endl;
}

int main(void)
{
	string s;

	getline(cin, s);
	unsigned long N = strtoul(s.c_str(), (char**)NULL, 10);

	unsigned long counter = 1;
	for (unsigned long i = 0; i < N; i++) {
		getline(cin, s);
		proc(s, counter++);
	}

	return 0;
}
