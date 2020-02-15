#include <stdio.h>
#pragma warning (disable:4996)

int main()
{
	int n = 0;
	scanf("%d", &n);

	int tiling[1000] = { 1, 2, 3, 5, 8, 0 };
	for (int i = 2; i < n; i++)
		tiling[i] = (tiling[i - 2] + tiling[i - 1]) % 10007;

	printf("%d", tiling[n-1]);
	return 0;
}