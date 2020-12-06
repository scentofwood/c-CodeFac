#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

/********************************************************************
	ť 
	- PUSH : ���ÿ� �����͸� �ִ´� 
	- POP  : ���ÿ��� �����͸� ������ 
	
	Front                                  Rear
	data|next -> data|next -> data|next -> data|next -> NULL
	�Ϲݳ��     �Ϲݳ��     �Ϲݳ��     �Ϲݳ��
	
********************************************************************/

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *front;
	Node *rear;
	int count;
} Queue;

void push(Queue *queue, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	}
	else {
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

int pop(Queue *queue) {
	if (queue->count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node *node = queue->front;
	int data = node->data;
	queue->front = node->next;
	free(node);
	queue->count--;
	return data;
}

void show(Queue *queue) {
	Node *cur = queue->front;
	printf("--- ť�� �� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ť�� �� ---\n");
}

int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;
	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	show(&queue);
	printf("\n");
	
	pop(&queue);
	push(&queue, 6);
	show(&queue);
	printf("\n");
	
	pop(&queue);
	push(&queue, 1);
	push(&queue, 8);
	pop(&queue);
	show(&queue);
	printf("\n");
	
	system("pause");
	return 0;
}


