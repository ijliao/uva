#include <iostream>
#include <string>

using namespace std;

string		S;

bool isSlump(int start, int end)
{
	// first char is 'D' or 'E'
	if ((S[start] != 'D') && (S[start] != 'E'))
		return false;

	// 1 or more 'F' or
	// 1 or more 'F' followed by Slump or 'G'

	// check 'F'

	int		i;
	for (i = start + 1; i <= end; i++)
		if (S[i] != 'F')
			break;

	if (i > end)							// only 'F's
		return true;
	else if (isSlump(i, end))				// 'F' followed by Slump
		return true;
	else if ((i == end) && (S[i] == 'G'))	// 'F' followed by 'G'
		return true;
	else
		return false;
}

bool isSlimp(int start, int end)
{
	// first char is 'A'
	if (S[start] != 'A')
		return false;

	// if length = 2 then 2nd char is 'H'
	if ((end - start + 1) == 2)
		return (S[end] == 'H') ? true : false;

	// 'A' followed by 'B' followed by Slimp followed by 'C' or
	// 'A' followed by Slump followed by 'C'

	// check end 'C' first
	if (S[end] != 'C')
		return false;
	else {
		if ((S[start + 1] == 'B') && isSlimp(start + 2, end - 1))
			return true;
		else if (isSlump(start + 1, end - 1))
			return true;
		else
			return false;
	}
}

bool isSlurpy(void)
{
	int		leng = S.length();

	for (int idx = 1; idx < leng - 2; idx++)
		if (isSlimp(0, idx))
			if (isSlump(idx + 1, leng - 1))
				return true;

	return false;
}

int main(void)
{
	int		N;

	cin >> N;
	cout << "SLURPYS OUTPUT" << endl;

	for (int i = 0; i < N; i++) {
		cin >> S;
		cout << string(isSlurpy() ? "YES" : "NO") << endl;
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}
