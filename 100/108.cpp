#include <iostream>

using namespace std;

int t[100][100];

int N;

int main(void){
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> t[i][j];
			if (j > 0)
				t[i][j] += t[i][j - 1];
		}
	}

	int max = 0;
	bool flag = true;

	for (int l = 0; l < N; l++) {
		for (int r = l; r < N; r++) {
			int tmp = 0;

			for (int row = 0; row < N; row++) {
				if (l > 0)
					tmp += t[row][r] - t[row][l - 1];
				else
					tmp += t[row][r];
				
				if (flag || tmp > max) {
					max = tmp;
					flag = false;
				}

				if (tmp < 0)
					tmp = 0;
			}
		}
	}

	cout << max << endl;

	return 0;
}
