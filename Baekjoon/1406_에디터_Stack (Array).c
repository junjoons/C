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

		if (!strcmp(cmd, "L")) //커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
		{
			if (left_index)
			{
				left_index--;
				char data = left[left_index];
				right[right_index] = data;
				right_index++;
			}
		}
		else if (!strcmp(cmd, "D")) //커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
		{
			if (right_index)
			{
				char data = right[--right_index];
				left[left_index++] = data;
			}
		}
		else if (!strcmp(cmd, "B")) //커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
		{
			if (left_index)
				left_index--;
		}
		else //P $:	$라는 문자를 커서 왼쪽에 추가함
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