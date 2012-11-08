#include <iostream>
#include <algorithm>

using namespace std;

const int SHIFT = 20000;

int main(void)
{
	int L, H, R;
	int left = INT_MAX, right = 0;
	int* height = new int[40000];
  
	while (true) {
		cin >> L >> H >> R;
		if (cin.eof())
			break;

		for (int i = L; i < R; i++)
			height[i + SHIFT - 1] = max(height[i + SHIFT - 1], H);

		right = max(right, R);
		left = min(left, L);
	}

	cout << left << ' ' << height[left + SHIFT];

	for (int i = left + SHIFT + 1; i <= right + SHIFT; i++)
		if (height[i] != height[i - 1])
			cout << ' ' << i - SHIFT + 1 << ' ' << height[i];
 
	cout << endl;

	return 0;
}
