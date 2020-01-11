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
		if (!strcmp(cmd, "pop")) //pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		{
			if (queue_size) //ť�� ������ ������
			{
				queue_size--;
				printf("%d\n", queue[queue_size]);
			}
			else //ť�� ������ ������
			{
				printf("-1\n");
			}
		}
		else if (!strcmp(cmd, "size")) //size: ť�� ����ִ� ������ ������ ����Ѵ�.
			printf("%d\n", queue_size);
		else if (!strcmp(cmd, "empty")) //empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
		{
			if (queue_size)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (!strcmp(cmd, "front")) //front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		{
			if (queue_size)
				printf("%d\n", queue[0]);
			else
				printf("-1\n");
		}
		else if (!strcmp(cmd, "back")) //back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		{
			if (queue_size)
				printf("%d\n", queue[queue_size - 1]);
			else
				printf("-1\n");
		}
		else //push X: ���� X�� ť�� �ִ� �����̴�.
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