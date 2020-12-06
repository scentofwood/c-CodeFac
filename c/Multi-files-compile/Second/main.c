#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int input_data(void);
double average(void);
void print_data(double);

int cnt = 0;
static int tot = 0;

int main(int argc, char *argv[]) {
	double avg;
	
	printf("만나서 반갑소\n");
	printf("main.c 에서의 old cnt[%d] tot[%d]\n", cnt, tot);

	tot = input_data();
	avg = average();
	print_data(avg);
	printf("main.c 에서의 new cnt[%d] tot[%d]\n", cnt, tot);
	
	return 0;
}

void print_data(double avg)
{
	printf("입력한 양수의 갯수 : %d\n", cnt);
	printf("전체 합과 평균 : %d, %.5f\n", tot, avg);
}
