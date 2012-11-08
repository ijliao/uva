#include <stdio.h>

int N;
int ans1[20], ans2[20];

void get(int t[])
{
	int i;

	for (i = 0; i < N; i++)
		scanf("%d", &t[i]);
}

void lcs(void)
{
	char table[21][21];
	int i, j;

	for (i = 0; i < 21; i++)
		for (j = 0; j < 21; j++)
			table[i][j] = 0;

 	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++) {
			if (ans1[i - 1] == ans2[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else if (table[i][j - 1] > table[i - 1][j])
				table[i][j] = table[i][j - 1];
			else
				table[i][j] = table[i - 1][j];
		}

	printf("%d\n", table[N][N]);
}

int main(void)
{
	scanf("%d", &N);

	get(ans1);

	while (1) {
		get(ans2);
		if (feof(stdin))
			break;

		lcs();
	}

	return 0;
}
