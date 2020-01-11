#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct NODE node;
typedef struct LIST list;

struct NODE {
	node* next;
	node* prev;
	int data;
};

struct LIST {
	int size;
	node* front;
	node* back;
};

list* SetList()
{
	list* newList = (list*)malloc(sizeof(list));
	newList->front = newList->back = NULL;
	newList->size = 0;
	return newList;
}

void Pop_front(list *myl)
{
	if (myl->size > 0)
	{
		node *curr = myl->front;
		myl->front = curr->next;
		printf("%d\n", curr->data);
		free(curr);
		myl->size--;
	}
	else
		printf("-1\n");
}

void Pop_back(list* myl)
{
	if (myl->size > 0)
	{
		node *curr = myl->back;
		myl->back = curr->prev;
		printf("%d\n", curr->data);
		free(curr);
		myl->size--;
	}
	else
		printf("-1\n");
}

void Size(list* myl)
{
	printf("%d\n", myl->size);
}

void Empty(list* myl)
{
	if (myl->size > 0)
		printf("0\n");
	else
		printf("1\n");
}

void Front(list *myl)
{
	if (myl->size > 0)
		printf("%d\n", myl->front->data);
	else
		printf("-1\n");
}

void Back(list *myl)
{
	if (myl->size > 0)
		printf("%d\n", myl->back->data);
	else
		printf("-1\n");
}

void Push_front(list *myl, int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = newNode->prev = NULL;

	if (myl->size == 0)
		myl->front = myl->back = newNode;
	else
	{
		myl->front->prev = newNode;
		newNode->next = myl->front;
		myl->front = newNode;
	}
	myl->size++;
}

void Push_back(list *myl, int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = newNode->prev = NULL;

	if (myl->size == 0)
		myl->front = myl->back = newNode;
	else
	{
		myl->back->next = newNode;
		newNode->prev = myl->back;
		myl->back = newNode;
	}
	myl->size++;
}

int main()
{
	char cmd[20];
	int cmd_nb = 0;
	list* myl = SetList();

	scanf("%d", &cmd_nb);
 	for (int i = 0; i < cmd_nb; i++)
	{
		scanf(" %[^\n]", cmd);
		if (!strcmp(cmd, "pop_front")) //덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			Pop_front(myl);
		else if (!strcmp(cmd, "pop_back")) //덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			Pop_back(myl);
		else if (!strcmp(cmd, "size")) //덱에 들어있는 정수의 개수를 출력한다.
			Size(myl);
		else if (!strcmp(cmd, "empty")) //덱이 비어있으면 1을, 아니면 0을 출력한다.
			Empty(myl);
		else if (!strcmp(cmd, "front")) //덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			Front(myl);
		else if (!strcmp(cmd, "back")) //덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			Back(myl);
		else {
			char	push[12];
			int data;
			sscanf(cmd, "%s %d", push, &data);
			if (!strcmp(push, "push_front")) //정수 X를 덱의 앞에 넣는다.
				Push_front(myl, data);
			else //정수 X를 덱의 뒤에 넣는다.
				Push_back(myl, data);
		}
	}

	return 0;
}