#include <stdio.h>

extern int cnt;
int tot = 0;

int input_data(void)
{
	int pos;
	while(1)
	{
		printf("��� �Է� : ");
		scanf("%d", &pos);
		if (pos < 0) break;
		printf("input.c ������ cnt [%d] -> ", cnt);
		cnt++;
		printf("[%d]\n ", cnt);
		tot += pos;
	}
	return tot;
}
