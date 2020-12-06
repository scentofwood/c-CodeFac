/****************************************************************************
 컴파일방법 : formatter.h 를 include 하여 컴파일한다. 
 ① gcc.exe -c test_1.c -o test_1.o  -I"C:\A_PGM\c-CodeFac\Formatter"  
 ② gcc.exe C:\A_PGM\c-CodeFac\Formatter/formatter.o test_1.o -o test_1.exe  
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

	if (option & COOL) printf("차가운 ");
	else               printf("뜨거운 ");
	
	if (option & BIG)  printf("큰 ");
	else               printf("작은 ");

	if (option & SPEC) printf("특수주문 ");
	else               printf("일반주문 ");

	switch(item)
	{
		case 1:
			printf("콜라 나옴 \n");
			break;
		case 2:
			printf("사이다 나옴 \n");
			break;
		default:
			printf("잘못입력\n");
			break;
	}
}


int main (void)
{
	int input;
	unsigned int item;  // 4 bytes

	printf("1.콜라 2.사이다 \n");
	printf("상품번호 입력 : ");
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
