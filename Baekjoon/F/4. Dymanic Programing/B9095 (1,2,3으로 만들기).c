#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int exe_nb;
	int n;
	int dp[12] = { 0, 1, 2, 4, 7 };

	scanf("%d", &exe_nb);

	for (int i = 0; i < exe_nb; i++)
	{
		scanf("%d", &n);
		if (n <= 4)
			printf("%d\n", dp[n]);
		else {
			for (int j = 5; j <= n; j++)
				dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
			printf("%d\n", dp[n]);
		}
	}
	return 0;
}