#ifndef FORMATTER_H
#define FORMATTER_H

char *intToBinary(int i);           // 부호 있는 32비트 정수를, 2진수 문자열로 변환
char *uintToBinary(unsigned int i); // 부호 없는 32비트 정수를, 2진수 문자열로 변환

int binaryToInt(char *s);           // 2진수 문자열을, 부호 있는 32비트 정수로 변환
unsigned int binaryToUint(char *s); // 2진수 문자열을, 부호 없는 32비트 정수로 변환

#endif
