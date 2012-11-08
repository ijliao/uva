#include <iostream>
#include <vector>

using namespace std;

char bin[100][6];
char color[] = {
	'r', 'o', 'y', 'g', 'b'
};

char thing[] = {
	'P', 'G', 'A', 'S', 'N'
};

int get_idx(char* pTab, char c)
{
	for (int i = 0; i < 5; i++)
		if (pTab[i] == c)
			return i;

	return -1;
}

int main(void)
{
	while (true) {
		int bin_n = 0;

		while (true) {
			char buf[128];

			cin.getline(buf, sizeof buf);
			if (buf[0] == 'e')
				break;

			if (buf[0] == '#')
				return 0;

			bin[bin_n][get_idx(color, buf[0])] = buf[2];
			bin[bin_n][get_idx(color, buf[4])] = buf[6];
			bin[bin_n][get_idx(color, buf[8])] = buf[10];
			bin[bin_n][get_idx(color, buf[12])] = buf[14];
			bin[bin_n][get_idx(color, buf[16])] = buf[18];

			bin_n++;
		}

		vector < int > score(bin_n, 0);

		for (int i = 0 ; i < 5 ; i++) {
			vector < int > tmp(5, 0);

			for (int j = 0 ; j < bin_n ; j++)
				tmp[get_idx(thing, bin[j][i])]++;

			for (int j = 0 ; j < bin_n ; j++)
				score[j] += tmp[get_idx(thing, bin[j][i])];
		}

		int max_bin = -1;
		int max_score = 0;

		for (int i = 0 ; i < bin_n ; i++) {
			if (score[i] > max_score) {
				max_bin = i;
				max_score = score[i];
			}
		}

		cout << max_bin + 1 << endl;
	}

	return 0;
}
