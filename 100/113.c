/* @JUDGE_ID: 1813KN 113 C */

#include <stdio.h>
#include <math.h>

int main()
{
	double n = 0, m = 0;

	while (scanf("%lf%lf", &n, &m) == 2)
		printf("%.0lf\n", pow(m, 1/n));

	return 0;
}
