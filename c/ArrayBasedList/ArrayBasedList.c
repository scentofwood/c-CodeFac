#include <stdio.h>
#define INF 10000

/********************************************************************
	�迭��� ����Ʈ�� Ư¡ 
	���� 
	1) �迭�� ��������Ƿ� Ư���� ��ġ�� ���ҿ� ��� ������ �� �ִ� 
	����
	1) �����Ͱ� �� ������ �̸� �޸𸮿� �Ҵ��ؾ� �Ѵ�
	2) ���ϴ� ��ġ���� ���԰� ������ ��ȿ�����̴� 
********************************************************************/

int arr[INF];
int count = 0;

void addBack(int data) {
	arr[count] = data;
	count++;
}

void addFirst(int data) {
	int i;
	for (i = count; i >= 1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = data;
	count++;
}

void show() {
	int i;
	for (i = 0; i < count; i++) {
		printf("%d���� %d\n", i + 1, arr[i]);
	}
}

void removeAt(int n) {
	if ((n >= 1) && (n <= count)) {
		int i;
		for (i = n; i <= count; i++) {
			arr[i - 1] = arr[i];
		}
		arr[count] = 0;
		count--;
	} else {
		printf("�������� ���� [%d]\n", n);
	}
}

int main(void) {
	
	addFirst(4);
	addFirst(5);
	addFirst(1);
	addBack(7);
	addBack(6);
	addBack(8);
	addFirst(2);

	show();
	printf("=============\n");
	
	int n = 0;
	printf("�������ȣ : ");
	scanf("%d", &n);
	printf("\n");

	removeAt(n);
	show();
	
	system("pause");
	
	return 0;
}
