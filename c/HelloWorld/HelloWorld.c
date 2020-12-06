#include <stdio.h>
#define Q printf("##test include##\n")
#define IS_VALUE_NULL(x) !x || x[0] == NULL

void main(void) {
	printf("Hello world.\n");
	printf("My name is AlphaGo.\n");
	
	funcA();
	Q;
}

int funcA() {
	int i[5];
	i[0] = 3;
	printf("TEST\n");
/*
	if (i[0] == NULL) {
		printf("NULL\n");
	} else {
		printf("NOT_NULL\n");
	}
*/
	printf("result IS_ARG [%d]\n", IS_VALUE_NULL(i));
	if (IS_VALUE_NULL(i) == 1) {
		printf("YES NULL \n");
	} else {
		printf("NO NOT NULL \n");
	}
	
	printf("need to be checked [%d][%d]\n", -3, !!-3);

}
