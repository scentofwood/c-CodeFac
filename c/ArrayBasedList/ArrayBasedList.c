#include <stdio.h>
#define INF 10000

/********************************************************************
	배열기반 리스트의 특징 
	장점 
	1) 배열로 만들었으므로 특정한 위치의 원소에 즉시 접근할 수 있다 
	단점
	1) 데이터가 들어갈 공간을 미리 메모리에 할당해야 한다
	2) 원하는 위치로의 삽입과 삭제가 비효율적이다 
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
		printf("%d번재 %d\n", i + 1, arr[i]);
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
		printf("지울대상이 없음 [%d]\n", n);
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
	printf("지울대상번호 : ");
	scanf("%d", &n);
	printf("\n");

	removeAt(n);
	show();
	
	system("pause");
	
	return 0;
}
