#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);

	int tiling[1001] = { 0, 1, 3, 5, 11};
	for (int i = 5; i <= n; i++)
		tiling[i] = (tiling[i - 2]*2 + tiling[i - 1]) % 10007;

	printf("%d", tiling[n]);
	return 0;
}