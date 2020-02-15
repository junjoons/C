#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	long long int dp[91][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1}, };
	int n;
	scanf("%d", &n);
		
	for (int i = 4; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dp[i][j] = dp[i - 2][j] + dp[i - 1][j];
		}
	}
	long long int data = dp[n][0] + dp[n][1];
	printf("%lld", data);
	return 0;
}