#include <stdio.h>
#pragma warning (disable:4996)

int main()
{
	int dp[101][10] = { {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, { 1, 2, 2, 2, 2, 2, 2, 2, 2, 1 }, {0, }, };
	int n;
	int index = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	int sum = 0;

	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n - 1][i]) % 1000000000;

	printf("%d", sum);

	return 0;
}