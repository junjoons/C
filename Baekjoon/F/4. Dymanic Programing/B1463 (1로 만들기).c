#include <stdio.h>
#pragma warning (disable:4996)

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int dp[100001] = { 0, 0, 1, 1, 2, 3 };
	int x = 0;
	scanf("%d", &x);
	if (x <= 5)
		printf("%d", dp[x]);
	else {
		for (int i = 6; i <= x; i++)
		{
			dp[i] = dp[i - 1] + 1;
			if (i % 2 == 0)
				dp[i] = min(dp[i / 2] + 1, dp[i]);
			if (i % 3 == 0)
				dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	printf("%d", dp[x]);
	}
	return 0;
}