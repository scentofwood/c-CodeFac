#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void input_data(int *, int *);
double average(int, int);

int main(int argc, char *argv[]) {
	int a, b;
	double avg;
	
	printf("������ �ݰ���\n");

	input_data(&a, &b);
	avg = average(a, b);
	printf("%d�� %d�� ��� : %.5f\n", a, b, avg);
	
	return 0;
}

