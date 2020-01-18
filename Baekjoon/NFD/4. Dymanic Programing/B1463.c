#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int n = 0;
	scanf("%d", &n);
	int dp[100001] = { 0, 0, 1, 1, 2, 3 };
	if (n <= 5)
		printf("%d", dp[n]);
	else
	{
		for (int i = 6; i <= n; i++)
		{
			dp[i] = dp[i - 1] + 1;
			if (i % 2 == 0)
				dp[i] = dp[i / 2] + 1;
			if (i % 3 == 1)
				dp[i] = dp[i / 3] + 1;
		}
		printf("%d", dp[n]);
	}
	

	return 0;
}