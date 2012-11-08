#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

struct cargo {
	char sc[4];
	char sn[16];
	char des[16];
	char ext[26];
	double price;
};

char* cut(char* s)
{
	static char* head;

	if (s != NULL)
		head = s;

	char* tmp = head;

	while (*tmp != '\0') {
		if (*tmp != ',')
			tmp++;
		else {
			*tmp++ = '\0';
			break;
		}
	}

	char* r = head; head = tmp;
	return r;
}

void parse(char* s, vector < cargo > &res)
{
	cargo tmp;
	char* p;

	p = cut(s); strcpy(tmp.sc, p);
	p = cut(NULL); strcpy(tmp.sn, p);
	p = cut(NULL); strcpy(tmp.des, p);
	p = cut(NULL); strcpy(tmp.ext, p);
	p = cut(NULL);
	tmp.price = (strlen(p) == 0) ? 0 : (strtod(p, (char**)NULL) / 100);

	res.push_back(tmp);
}

void output(vector < cargo > &res)
{
	cout << "Item Id,Item Desc,Item Price" << endl;

	int n = res.size();
	for (int i = 0; i < n; i++) {
		cargo now = res[i];

		if (strlen(now.des) > 10)
			continue;

		char id[15] = "000", desc[50];

		strcpy(id + 3 - strlen(now.sc), now.sc);
		strcpy(id + 3, now.des);

		if (strlen(now.sn) == 0) {
			int j;
			for (j = 0; j < i; j++)
				if (strcmp(res[j].sc, now.sc) == 0)
					break;

			if (strlen(res[j].sn) == 0)
				continue;

			strcpy(now.sn, res[j].sn);
		}

		strcpy(desc, now.sn);
		if (strlen(now.ext) != 0) {
			strcpy(desc + strlen(desc), "-");
			strcpy(desc + strlen(desc), now.ext);
		}

		desc[30] = '\0';

		cout << id << ',' << desc << ',';
		cout.setf(ios::showpoint | ios::fixed);
		cout << setprecision(2) << now.price << endl;
	}
}

int main(void)
{
	char s[70];
	int N;

	cin.getline(s, sizeof s);
	N = atoi(s);

	cout << endl;
	cin.getline(s, sizeof s);
	for (int i = 0; i < N; i++) {
		vector < cargo > res;

		while (true) {
			cin.getline(s, sizeof s);
			if (cin.eof() || !strlen(s))
				break;

			parse(s, res);
		}

		output(res);
		cout << endl;
	}

	return 0;
}
