#include <stdio.h> 
#include <stdlib.h>
#define INF 9999999

/********************************************************************
	���� 
	- PUSH : ���ÿ� �����͸� �ִ´� 
	- POP  : ���ÿ��� �����͸� ������ 
	- top   : ������ �ֻ�� (������ ���Ա�) 
	
	data|next -> data|next -> data|next -> NULL
	top          �Ϲݳ��     �Ϲݳ�� 
	
********************************************************************/

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void push(Stack *stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

int pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�\n");
		return -INF;
	}
	Node* node = stack->top;
//	int data = stack->top->data; �̷��� �ص� �ȴ� 
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void show(Stack *stack) {
	Node* cur = stack->top;
	printf("--- ������ �ֻ�� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ������ ���ϴ� ---\n");
}

int main() {
	Stack s;
	s.top = NULL;
	
	push(&s, 7);
	push(&s, 5);
	push(&s, 4);
	show(&s);
	printf("\n======================\n\n");
	
	pop(&s);
	show(&s);
	printf("\n======================\n\n");

	push(&s, 6);
	push(&s, 8);
	show(&s);
	printf("\n======================\n\n");
	
	system("pause");
	return 0;
}
