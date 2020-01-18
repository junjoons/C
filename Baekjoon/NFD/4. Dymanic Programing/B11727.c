#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int n = 0;
	scanf("%d", &n);
	int tile[1000] = { 1, 3, 5, 11, 0, };
	for (int i = 4; i < n; i++)
	{
		tile[i] = (tile[i - 2] * 2 + tile[i - 1])%10007;
	}
	printf("%d", tile[n-1]);

	return 0;
}