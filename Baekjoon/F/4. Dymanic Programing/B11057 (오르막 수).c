#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int dp[1001][10] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {0,}, };
	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		for (int j = 10; j > 0; j--)
		{
			if (j == 10)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % 10007;
		}

	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = (sum + dp[n][i]) % 10007;
	}

	printf("%d", sum);

	return 0;
}