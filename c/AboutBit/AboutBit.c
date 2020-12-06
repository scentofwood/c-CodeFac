#include <stdio.h>
#include <string.h>

int getAbit(unsigned short x, int n);
char *ushortToBinary(unsigned short i);
unsigned short makeBitOn(unsigned short x, int n);
unsigned short *makeBitmap(unsigned short *x, int n);

int main(void)
{
	unsigned short num = 24761;
//	unsigned short num = 65535;
	printf("%s\n", ushortToBinary(num)); // 2진수로 출력
	// 출력 결과: 0110000010111001

	// 0번 비트 (맨 우측 비트) 읽기
	printf("%d\n", getAbit(num, 0));
	// 1

	// 1번 비트 (맨 우측에서 2번째 비트) 읽기
	printf("%d\n", getAbit(num, 1));
	// 0

	// num을 1비트씩 읽어, 2진수로 출력하기
	printf("\n[ ");
	int i = 0;
	for (i = 15; i >= 0; i--) 
	{
		printf("%d", getAbit(num, i));
	}
	printf(" ]\n");
	// [ 0110000010111001 ]

	unsigned short k = 5;
	printf("%s\n", ushortToBinary(k));
	k = makeBitOn(k, 4);
	printf("%s\n", ushortToBinary(k));

	printf("mmmmmmmmmmmmmmmm\n");
	unsigned short m[4];
	memset(m, 0x00, sizeof(m));
	m[0] = 27;
	m[1] = 34;
	m[2] = 66;
	m[3] = 8;
	printf("%s\n", ushortToBinary(m[0]));
	printf("%s\n", ushortToBinary(m[1]));
	printf("%s\n", ushortToBinary(m[2]));
	printf("%s\n", ushortToBinary(m[3]));

	printf("tttttttttttttttt\n");
	unsigned short t[4];
	memset(t, 0x00, sizeof(t));
	memcpy(t, makeBitmap(m, 19), sizeof(t));
	printf("%s\n", ushortToBinary(t[0]));
	printf("%s\n", ushortToBinary(t[1]));
	printf("%s\n", ushortToBinary(t[2]));
	printf("%s\n", ushortToBinary(t[3]));


	return 0;
}

// 지정한 정수에서, 몇번째 비트만 읽어서 반환하는 함수
int getAbit(unsigned short x, int n)
{
	// getbit()
	return (x & (1 << n)) >> n;
}

// 16비트 정수를 2진수 문자열로 변환 함수
char *ushortToBinary(unsigned short i)
{
	static char s[16 + 1] = { '0', };
	int count = 16;

	do 
	{
		s[--count] = '0' + (char) (i & 1);
		i = i >> 1;
	} while (count);

	return s;
}

unsigned short makeBitOn(unsigned short x, int n)
{
	unsigned short num = 0;

	num = 1 << (16 - n);
	num = num | x;
	
	return num;
}

unsigned short *makeBitmap(unsigned short *x, int n)
{
	static unsigned short bitmap[4];
	memset(bitmap, 0x00, sizeof(bitmap));
	memcpy(bitmap, x, sizeof(bitmap));

	if (n <= 16)
	{
		bitmap[0] = makeBitOn(x[0], n);
	}
	else if (n <= 32)
	{
		bitmap[1] = makeBitOn(x[1], n - 16);
	}
	else if (n <= 48)
	{
		bitmap[2] = makeBitOn(x[2], n - 32);
	}
	else
	{
		bitmap[3] = makeBitOn(x[3], n - 48);
	}

	return bitmap;
}
