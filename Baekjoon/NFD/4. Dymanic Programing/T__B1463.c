#include <stdio.h>
#pragma warning(disable:4996)

int min(int a, int b) {
	return a < b ? a : b;}



int main()
{
	int arr[100001] = { 0,0,1,1,2,3 };
	int n;
	scanf(" %d", &n);
	if (n <= 5)
		printf("%d", arr[n]);
	else
	{
		for (int i =6; i<=n;i++)
		{
			//min(arr[n/3], arr[n/2], arr[n-1]) + 1
			arr[i] = arr[i - 1] + 1; // do -1, add 1
			
			if (i % 3 == 0)
			{
				arr[i] = min(arr[i / 3]+1, arr[i]);
			}
			if (i % 2 == 0)
			{
				arr[i] = min(arr[i / 2]+1, arr[i]);
			}
		}
		printf("%d", arr[n]);
	}
	
	return 0;
}