#include <stdio.h> 
#include <stdlib.h>

/********************************************************************
	연결 리스트의 특징 
	장점 
	1) 삽입과 삭제가 배열에 비해서 간단하다 
	단점
	1) 배열과 다르게 특정 인덱스로 즉시 접근하지 못하며
	   원소를 차례대로 검색해야 한다 
	2) 추가적인 포인터 변수가 사용되므로 메모리 공간이 낭비된다 
********************************************************************/

typedef struct {
	int data;
	struct Node *next;
} Node;

Node *head;

void addFront(Node *root, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}

void removeFront(Node *root) {
	Node *front = root->next;
	root->next = front->next;
	free(front);
}

void freeAll(Node *root) {
	Node *cur = root->next;
	while (cur != NULL) {
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
	root->next = NULL;
}

void showAll(Node *root) {
	Node *cur = root->next;
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	
	addFront(head, 2);
	addFront(head, 1);
	addFront(head, 7);
	addFront(head, 9);
	addFront(head, 8);
	showAll(head);
	printf("======================\n");
	
	removeFront(head);
	showAll(head);
	printf("======================\n");

	freeAll(head);
	showAll(head);
	printf("======================\n");
	
	system("pause");
	return; 0;
}
