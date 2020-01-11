#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int main()
{
	char left[1000000];
	int left_index = 0;

	char right[1000000];
	int right_index = 0;

	char cmd[10];
	int cmd_nb = 0;

	char init[1000000];

	scanf("%s", init);
	for (int i = 0; i < 1000000; i++)
	{
		if (init[i] == '\0')
			break;
		left[left_index++] = init[i];
	}

	scanf("%d", &cmd_nb);

	for (int i = 0; i < cmd_nb; i++)
	{
		scanf(" %[^\n]", cmd);

		if (!strcmp(cmd, "L")) //Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
		{
			if (left_index)
			{
				left_index--;
				char data = left[left_index];
				right[right_index] = data;
				right_index++;
			}
		}
		else if (!strcmp(cmd, "D")) //Ŀ���� ���������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
		{
			if (right_index)
			{
				char data = right[--right_index];
				left[left_index++] = data;
			}
		}
		else if (!strcmp(cmd, "B")) //Ŀ�� ���ʿ� �ִ� ���ڸ� ������ (Ŀ���� ������ �� ���̸� ���õ�)
		{
			if (left_index)
				left_index--;
		}
		else //P $:	$��� ���ڸ� Ŀ�� ���ʿ� �߰���
		{
			char P;
			char data;
			sscanf(cmd, "%c %c", &P, &data);
			left[left_index++] = data;
		}
	}

	for (int i = 0; i < left_index; i++)
		printf("%c", left[i]);
	for (int i = right_index - 1; i >= 0; i--)
		printf("%c", right[i]);

	return 0;
}