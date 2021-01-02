#include <stdio.h> 
#include <stdlib.h>

/********************************************************************
	양방향 연결 리스트의 특징 
	1) 각노드가 앞노드와 뒤노드의 정보를 저장하고 있다 
	2) 리스트의 앞에서부터 혹은 뒤에서부터 모두 접근할 수 있다 
********************************************************************/

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *head, *tail;

void insert(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node* cur;
	cur = head->next;
	while (cur->data < data && cur != tail) {
		cur = cur->next;
	}
	Node* prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;	
}

void removeFront() {
	Node* node = head->next;
	head->next = node->next;
	Node* next = node->next;
	next->prev = head;
	free(node);
}

void show() {
	Node* cur = head->next;
	while (cur != tail) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	
	insert(2);
	insert(1);
	insert(3);
	insert(9);
	insert(7);
	show();
	printf("======================\n");
	
	removeFront();
	show();
	printf("======================\n");
	
	system("pause");
	return 0;
}
