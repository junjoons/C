#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct NODE node;
typedef struct STACK stack;

struct NODE
{
	char data;
	node* prev;
};

struct STACK
{
	int size;
	node* top;
};

node* CreateNode(char data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->prev = NULL;
	return newNode;
}

stack* CreateStack()
{
	stack* newStack = (stack*)malloc(sizeof(stack));
	newStack->size = 0;
	newStack->top = NULL;
	return newStack;
}

char Pop(stack* myst)
{
	node* temp = myst->top;
	myst->top = temp->prev;
	myst->size--;
	char data = temp->data;
	free(temp);
	return data;
}

void Push(stack* myst, char data)
{
	node *newNode = CreateNode(data);
	newNode->prev = myst->top;
	myst->top = newNode;
	myst->size++;
}

void PrintL(node* myNode)
{
	if (myNode == NULL)
		return;
	PrintL(myNode->prev);
	printf("%c", myNode->data);
}

int main()
{
	stack* left = CreateStack();
	stack* right = CreateStack();
	char init[100000];
	scanf("%s", init);

	for (int i = 0; i < 100000; i++)
	{
		if (init[i] == '\0')
			break;
		Push(left, init[i]);
	}

	int cmdNb = 0;
	scanf("%d", &cmdNb);

	char cmd[100];

	for (int i = 0; i < cmdNb; i++)
	{
		scanf(" %[^\n]", cmd);
		if (!strcmp(cmd, "L")) //Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
		{
			if (left->size)
				Push(right, Pop(left));
		}
		else if (!strcmp(cmd, "D")) //Ŀ���� ���������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
		{
			if (right->size)
				Push(left, Pop(right));
		}
		else if (!strcmp(cmd, "B")) //Ŀ�� ���ʿ� �ִ� ���ڸ� ������ (Ŀ���� ������ �� ���̸� ���õ�) ������ ���� Ŀ���� �� ĭ �������� �̵��� ��ó�� ��Ÿ������, ������ Ŀ���� �����ʿ� �ִ� ���ڴ� �״����
		{
			if (left->size)
				Pop(left);
		}
		else //P: $��� ���ڸ� Ŀ�� ���ʿ� �߰���
		{
			char data;
			char p;
			sscanf(cmd, "%c %c", &p, &data);
			Push(left, data);
		}
	}

	PrintL(left->top);
	node *temp = right->top;
	while (temp != NULL)
	{
		printf("%c", temp->data);
		temp = temp->prev;
	}

	return 0;
}