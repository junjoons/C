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
		if (!strcmp(cmd, "pop_front")) //���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
			Pop_front(myl);
		else if (!strcmp(cmd, "pop_back")) //���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
			Pop_back(myl);
		else if (!strcmp(cmd, "size")) //���� ����ִ� ������ ������ ����Ѵ�.
			Size(myl);
		else if (!strcmp(cmd, "empty")) //���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
			Empty(myl);
		else if (!strcmp(cmd, "front")) //���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
			Front(myl);
		else if (!strcmp(cmd, "back")) //���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
			Back(myl);
		else {
			char	push[12];
			int data;
			sscanf(cmd, "%s %d", push, &data);
			if (!strcmp(push, "push_front")) //���� X�� ���� �տ� �ִ´�.
				Push_front(myl, data);
			else //���� X�� ���� �ڿ� �ִ´�.
				Push_back(myl, data);
		}
	}

	return 0;
}