#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int				N, L, C;
vector < int >	minTopic;

void schedule(void)
{
	vector < int >		minClass(N + 1, 0), minDis(N + 1, 0);
	int					disSat;

	for (int i = 1; i <= N; i++) {
		int		lecTime = 0;
		int		j;

		minClass[i] = 1;
		for (j = 1; j <= i; j++) {
			if (lecTime + minTopic[j] > L) {
				minClass[i]++;
				lecTime = minTopic[j];
			}
			else
				lecTime += minTopic[j];
		}

		lecTime = 0;
		for (j = i ; j > 0; j--) {
			if (minClass[j] == minClass[i] - 1)
				break;

			lecTime += minTopic[j];
		}

		if (lecTime < L - 10)
			minDis[i] = minDis[j] + (L - lecTime - 10) * (L - lecTime - 10);
		else if (lecTime == L)
			minDis[i] = minDis[j];
		else
			minDis[i] = minDis[j] - C;

		for (int k = j - 1; minClass[k] == minClass[i] - 1; k--) {
			lecTime += minTopic[k + 1];
			if (lecTime > L)
				break;

			if (lecTime < L - 10)
				disSat = minDis[k] + (L - lecTime - 10) * (L - lecTime - 10);
			else if (lecTime == L)
				disSat = minDis[k];
			else
				disSat = minDis[k] - C;

			minDis[i] = min(disSat, minDis[i]);
		}
	}

	cout << "Minimum number of lectures: " << minClass[N] << endl;
	cout << "Total dissatisfaction index: " << minDis[N] << endl;
}

int main(void)
{
	int		count = 1;

	int		total;

	cin >> total;

	for (int n = 0; n < total; n++) {
		while (true) {
			cin >> N;
			if (N == 0)
				break;

			cin >> L >> C;

			minTopic.clear();
			minTopic.push_back(0);
			for (int i = 0; i < N; i++) {
				int		tmp;
				cin >> tmp;
				minTopic.push_back(tmp);
			}

			if (count != 1)
				cout << endl;

			cout << "Case " << count++ << ':' << endl;
			schedule();
		}

		cout << endl;
	}

	return 0;
}
