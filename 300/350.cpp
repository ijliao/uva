#include <iostream>
#include <vector>

using namespace std;

int Z, I, M, L;

int check(void)
{
	vector < int > arr;
	arr.push_back((L * Z + I) % M);

	int pos = 0;

	for (int i = 1; ; i <<= 1) {
		int now = pos;

		for (int j = 1; j <= i; j++) {
			bool isok = false;

			arr.push_back((arr[pos++] * Z + I) % M);

			while ((now >= 0) && (arr[pos] == arr[now])) {
				pos--;
				now--;
				isok = true;
			}

			if (isok)
				return pos + 1;
		}
	}  

	return -1;
}

int main(void)
{
	int counter = 1;

	while (true) {
		cin >> Z >> I >> M >> L;
		if (!Z && !I && !M && !L)
			break;

		cout << "Case " << counter++ << ": " << check() << endl;
	}

	return 0;
}
