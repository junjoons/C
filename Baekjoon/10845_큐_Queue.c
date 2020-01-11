#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct NODE node;
typedef struct QUEUE queue;

struct NODE {
	int data;
	node* next;
	node* prev;
};

struct QUEUE {
	node* front;
	node* back;
	int size;
};

queue* SetQueue()
{
	queue *myq = (queue*)malloc(sizeof(queue));
	myq->front = myq->back = NULL;
	myq->size = 0;
	return myq;
}

void Pop(queue *myq)
{
	if (myq->size > 0)
	{
		node* curr = myq->front;
		myq->front = curr->next;
		printf("%d\n", curr->data);
		free(curr);
		myq->size--;
	}
	else
		printf("-1\n");
}

void Size(queue *myq)
{
	printf("%d\n", myq->size);
}

void Empty(queue *myq)
{
	if (myq->size > 0)
		printf("0\n");
	else
		printf("1\n");
}

void Front(queue *myq)
{
	if (myq->size > 0)
		printf("%d\n", myq->front->data);
	else
		printf("-1\n");
}

void Back(queue *myq)
{
	if (myq->size > 0)
		printf("%d\n", myq->back->data);
	else
		printf("-1\n");
}

void Push(queue *myq, int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = newNode->prev = NULL;
	
	if (myq->front == NULL || myq->back == NULL)
		myq->front = myq->back = newNode;
	else
	{
		myq->back->next = newNode;
		newNode->prev - myq->back;
		myq->back = newNode;
	}
	myq->size++;
}

int main()
{
	queue *myq = SetQueue();
	char cmd[20];
	int cmd_nb = 0;

	scanf("%d", &cmd_nb);
	for (int i = 0; i < cmd_nb; i++)
	{
		scanf(" %[^\n]", cmd);
		if (!strcmp(cmd, "pop"))
			Pop(myq);
		else if (!strcmp(cmd, "size"))
			Size(myq);
		else if (!strcmp(cmd, "empty"))
			Empty(myq);
		else if (!strcmp(cmd, "front"))
			Front(myq);
		else if (!strcmp(cmd, "back"))
			Back(myq);
		else 
		{
			char push[5];
			int data = 0;
			sscanf(cmd, "%s %d", push, &data);
			Push(myq, data);
		}
	}
	return 0;
}