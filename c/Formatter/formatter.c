#include <stdio.h>
#include "formatter.h"

#ifndef FORMATTER_H
#define FORMATTER_H
char *intToBinary(int i);           // 부호 있는 32비트 정수를, 2진수 문자열로 변환
char *uintToBinary(unsigned int i); // 부호 없는 32비트 정수를, 2진수 문자열로 변환
int binaryToInt(char *s);           // 2진수 문자열을, 부호 있는 32비트 정수로 변환
unsigned int binaryToUint(char *s); // 2진수 문자열을, 부호 없는 32비트 정수로 변환
#endif

/*
void main(void) {
  puts("\n\nDecimal to Binary (int) :\n");

  printf("%s\n",  intToBinary(0x0));
  printf("%s\n",  intToBinary(0xFF));
  printf("%s\n",  intToBinary(0xFFFF));
  printf("%s\n",  intToBinary(-2147483647 - 1)); // int 최소값 = -2147483648
  printf("%s\n",  intToBinary(2147483647));      // int 최대값
  printf("%s\n",  intToBinary(639127054));       // 임의의 값


  puts("\n\nDecimal to Binary (unsigned int) :\n");

  printf("%s\n", uintToBinary(0x0));
  printf("%s\n", uintToBinary(0xF));
  printf("%s\n", uintToBinary(0xFF));
  printf("%s\n", uintToBinary(0xFFFF));
  printf("%s\n", uintToBinary(0xFFFFFFFF)); // unsigned int 최대값


  puts("\n\nBinary to Decimal (int):");

  printf("%d\n", binaryToInt("0"));
  printf("%d\n", binaryToInt("1111"));
  printf("%d\n", binaryToInt("11111111"));
  printf("%d\n", binaryToInt("1111111111111111"));
  printf("%d\n", binaryToInt("00000000000000001111111111111111"));
  printf("%d\n", binaryToInt("01111111111111111111111111111111"));


  puts("\n\nBinary to Decimal (unsigned int):");

  printf("%u\n", binaryToUint("0"));
  printf("%u\n", binaryToUint("1111"));
  printf("%u\n", binaryToUint("11111111"));
  printf("%u\n", binaryToUint("1111111111111111"));
  printf("%u\n", binaryToUint("00000000000000001111111111111111"));
  printf("%u\n", binaryToUint("11111111111111111111111111111111"));
  printf("%u\n", binaryToUint("00100110000110000100111000001110"));

}
*/


char *intToBinary(int i) {
  static char s[32 + 1] = { '0', };
  int count = 32;

  do { s[--count] = '0' + (char) (i & 1);
       i = i >> 1;
  } while (count);

  return s;
}


char *uintToBinary(unsigned int i) {
  static char s[32 + 1] = { '0', };
  int count = 32;

  do { s[--count] = '0' + (char) (i & 1);
       i = i >> 1;
  } while (count);

  return s;
}



int binaryToInt(char *s) {
  int i = 0;
  int count = 0;

  while (s[count])
    i = (i << 1) | (s[count++] - '0');

  return i;
}


unsigned int binaryToUint(char *s) {
  unsigned int i = 0;
  int count = 0;

  while (s[count])
    i = (i << 1) | (s[count++] - '0');

  return i;
}
