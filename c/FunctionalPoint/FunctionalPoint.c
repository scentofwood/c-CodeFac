#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void myFunction() {
	printf("It is my function\n");
}

void yourFunction() {
	printf("It is your function\n");
}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int (*process(char* a))(int, int) {
	printf("%s\n", a);
	return add;
}

int (*fp_rt())(int, int) {
	return sub;
}

int main(void)
{
	printf("%d %d %d %d\n", 
			myFunction, yourFunction, add, sub);
	
	printf("+++++++++++++++++\n");
	
	void (*fp1) ();
	fp1 = myFunction;
	fp1();
	fp1 = yourFunction;
	fp1();
	
	printf("+++++++++++++++++\n");
	
	int (*fp2) (int, int);
	fp2 = add;
	printf("%d\n", fp2(10, 3));
	fp2 = sub;
	printf("%d\n", fp2(10, 3));
	
	printf("+++++++++++++++++\n");
	printf("%d\n", process("10과 20을 더해보겠습니다.")(10, 20));
	printf("%d\n", fp_rt()(5, 2));

	system("pause");
	
	return 0;
}


