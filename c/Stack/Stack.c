#include <stdio.h> 
#include <stdlib.h>
#define INF 9999999

/********************************************************************
	스택 
	- PUSH : 스택에 데이터를 넣는다 
	- POP  : 스택에서 데이터를 빼낸다 
	- top   : 스택의 최상단 (스택의 출입구) 
	
	data|next -> data|next -> data|next -> NULL
	top          일반노드     일반노드 
	
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
		printf("스택 언더플로우가 발생했습니다\n");
		return -INF;
	}
	Node* node = stack->top;
//	int data = stack->top->data; 이렇게 해도 된다 
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void show(Stack *stack) {
	Node* cur = stack->top;
	printf("--- 스택의 최상단 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 스택의 최하단 ---\n");
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
