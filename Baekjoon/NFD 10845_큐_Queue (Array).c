#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int queue[100000];
	int queue_size = 0;
	int queue_index = 0;

	char cmd[1000000];
	int cmd_nb = 0;

	scanf("%d", &cmd_nb);
	for (int i = 0; i < cmd_nb; i++)
	{
		scanf(" %[^\n]", cmd);
		if (!strcmp(cmd, "pop")) //pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		{
			if (queue_size) //큐에 정수가 있을떄
			{
				queue_size--;
				printf("%d\n", queue[queue_size]);
			}
			else //큐에 정수가 없을때
			{
				printf("-1\n");
			}
		}
		else if (!strcmp(cmd, "size")) //size: 큐에 들어있는 정수의 개수를 출력한다.
			printf("%d\n", queue_size);
		else if (!strcmp(cmd, "empty")) //empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
		{
			if (queue_size)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (!strcmp(cmd, "front")) //front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		{
			if (queue_size)
				printf("%d\n", queue[0]);
			else
				printf("-1\n");
		}
		else if (!strcmp(cmd, "back")) //back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		{
			if (queue_size)
				printf("%d\n", queue[queue_size - 1]);
			else
				printf("-1\n");
		}
		else //push X: 정수 X를 큐에 넣는 연산이다.
		{
			char push[5];
			int data;
			sscanf(cmd, "%s %d", push, &data);
			queue[queue_size] = data;
			queue_size++;
		}
	}

	return 0;
}