#include <stdio.h>
#pragma warning(disable:4996)
#define max(x,y) x>y? x:y

int main() 
{
	int exenb;
	scanf("%d", &exenb);
	for (int t = 0; t < exenb; t++)
	{
		int n;
		scanf("%d ", &n);
		int dp[2][10001] = { 0, };

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{ 
				scanf("%d", &dp[i][j]);
			}
		}

		for (int i = 1; i < n; i++)
		{
			if (i == 1)
			{
				dp[0][i] = dp[1][i - 1] + dp[0][i];
			}
			else 
			{
				dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + dp[0][i];
			}

			if (i == 1)
			{
				dp[1][i] = dp[0][i - 1] + dp[1][i];
			}
			else
			{
				dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + dp[1][i];
			}
		}
		int data = max(dp[0][n], dp[1][n]);
		printf("%d", data);
	}
	return 0;
}