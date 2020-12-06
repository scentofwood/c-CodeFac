#include <stdio.h> 
#include <stdlib.h>

/********************************************************************
	���� ����Ʈ�� Ư¡ 
	���� 
	1) ���԰� ������ �迭�� ���ؼ� �����ϴ� 
	����
	1) �迭�� �ٸ��� Ư�� �ε����� ��� �������� ���ϸ�
	   ���Ҹ� ���ʴ�� �˻��ؾ� �Ѵ� 
	2) �߰����� ������ ������ ���ǹǷ� �޸� ������ ����ȴ� 
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
