#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct NODE node;
typedef struct QUEUE queue;

struct NODE
{
	int data;
	node *next;
	node *prev;
};

struct QUEUE
{
	node *front;
	node *back;
	int size;
};

node *CreateNode(int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

queue *CreateQueue()
{
	queue* newQueue = (queue*)malloc(sizeof(queue));
	newQueue->front = NULL;
	newQueue->back = NULL;
	newQueue->size = 0;
	return newQueue;
}

void Push(int data, queue *myq)
{
	node *newNode = CreateNode(data);
	
	if (myq->front == NULL && myq->back == NULL) //ť�� �� ���
		myq->front = myq->back = newNode;
	else //ť�� ������ �ִ� ���
	{
		myq->back->next = newNode;
		newNode->prev = myq->back;
		myq->back = newNode;
	}
	myq->size++;
}

node* Pop(queue *myq)
{
	node *temp = myq->front;
	myq->front = temp->next;
	myq->size--;
	return temp;
}

int main()
{
	char cmd[1000000];
	int cmd_nb = 0;

	scanf("%d", &cmd_nb);

	queue *myq = CreateQueue();
	for (int i = 0; i < cmd_nb; i++)
	{
		scanf(" %[^\n]", cmd);
		if (!strcmp(cmd, "pop")) //pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		{
			if (myq->size)
			{
				node *temp = Pop(myq);
				int data = temp->data;
				printf("%d\n", data);
				free(temp);
			}
			else
				printf("-1\n");
		}
		else if (!strcmp(cmd, "size"))
			printf("%d\n", myq->size);
		else if (!strcmp(cmd, "empty"))
		{
			if (myq->size)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (!strcmp(cmd, "front"))
		{
			if (myq->size)
				printf("%d\n", myq->front->data);
			else
				printf("-1\n");
		}
		else if (!strcmp(cmd, "back"))
		{
			if (myq->size)
				printf("%d\n", myq->back->data);
			else
				printf("-1\n");
		}
		else
		{
			char push[1000000];
			int data;
			sscanf(cmd, "%s %d", push, &data);
			Push(data, myq);
		}
	}

	return 0;
}