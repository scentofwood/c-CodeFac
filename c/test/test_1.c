/****************************************************************************
 �����Ϲ�� : formatter.h �� include �Ͽ� �������Ѵ�. 
 �� gcc.exe -c test_1.c -o test_1.o  -I"C:\A_PGM\c-CodeFac\Formatter"  
 �� gcc.exe C:\A_PGM\c-CodeFac\Formatter/formatter.o test_1.o -o test_1.exe  
****************************************************************************/


#include <stdio.h>
#include "formatter.h"

#define COOL (1)
#define BIG  (1 << 1)
#define SPEC (1 << 2)

void bending(int item, unsigned int option)
{
	printf("\n"); 
	printf("option & COOL [%s]\n", uintToBinary(option & COOL));
	printf("option & BIG  [%s]\n", uintToBinary(option & BIG));
	printf("option & SPEC [%s]\n", uintToBinary(option & SPEC));
	printf("\n"); 

	if (option & COOL) printf("������ ");
	else               printf("�߰ſ� ");
	
	if (option & BIG)  printf("ū ");
	else               printf("���� ");

	if (option & SPEC) printf("Ư���ֹ� ");
	else               printf("�Ϲ��ֹ� ");

	switch(item)
	{
		case 1:
			printf("�ݶ� ���� \n");
			break;
		case 2:
			printf("���̴� ���� \n");
			break;
		default:
			printf("�߸��Է�\n");
			break;
	}
}


int main (void)
{
	int input;
	unsigned int item;  // 4 bytes

	printf("1.�ݶ� 2.���̴� \n");
	printf("��ǰ��ȣ �Է� : ");
	scanf("%d", &input);

	printf("\n");
	printf("COOL [%s]", uintToBinary(COOL)); printf("[%s]\n", uintToBinary(~COOL));
	printf("BIG  [%s]", uintToBinary(BIG));  printf("[%s]\n", uintToBinary(~BIG));
	printf("SPEC [%s]", uintToBinary(SPEC)); printf("[%s]\n", uintToBinary(~SPEC));

	item = COOL | BIG | SPEC;
	bending(input, item);

	item = item & ~SPEC;
	bending(input, item);


	return 0;
}
