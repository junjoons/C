#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int exenb; //¹®Á¦»ó t
	int n;

	scanf("%d", &exenb);

	for (int i = 0; i < exenb; i++)
	{
		int dp[2][100000];

		scanf("%d", &n);

		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < n; k++)
				scanf("%d", &dp[j][k]);
		}
		for (int k = 0; k < 2; k++)
		{
			for (int j = 0; j < n; j++)
			{
				if (k == 0)
				{
					if (j == 0)
					{
						if (dp[k][j] > dp[k + 1][j] && dp[k][j] > dp[k][j + 1])
							dp[k + 1][j] = dp[k][j + 1] = 0;
						else
							dp[k][j] = 0;
					}
					else if (j == n - 1)
					{
						if (dp[k][j] > dp[k + 1][j] && dp[k][j] > dp[k][j - 1])
							dp[k + 1][j] = dp[k][j - 1] = 0;
						else
							dp[k][j] = 0;
					}
					else
					{
						if (dp[k][j] > dp[k][j - 1] && dp[k][j] > dp[k][j + 1] && dp[k][j] > dp[k + 1][j])
							dp[k][j + 1] = dp[k][j - 1] = dp[k + 1][j] = 0;
						else
							dp[k][j] = 0;
					}
				}
				else if (k == 1)
				{
					if (j == 0)
					{
						if (dp[k][j] > dp[k - 1][j] && dp[k][j] > dp[k][j + 1])
							dp[k - 1][j] = dp[k][j + 1] = 0;
						else
							dp[k][j] = 0;
					}
					else if (j == n - 1)
					{
						if (dp[k][j] > dp[k - 1][j] && dp[k][j] > dp[k][j - 1])
							dp[k - 1][j] = dp[k][j - 1] = 0;
						else
							dp[k][j] = 0;
					}
					else
					{
						if (dp[k][j] > dp[k][j - 1] && dp[k][j] > dp[k][j + 1] && dp[k][j] > dp[k - 1][j])
							dp[k][j + 1] = dp[k][j - 1] = dp[k - 1][j] = 0;
						else
							dp[k][j] = 0;
					}
				}
			}
		}
		int sum = 0;
		for (int k = 0; k < 2; k++)
		{
			for (int j = 0; j < n; j++)
			{
				sum = sum + dp[k][j];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}