#ifndef FORMATTER_H
#define FORMATTER_H

char *intToBinary(int i);           // ��ȣ �ִ� 32��Ʈ ������, 2���� ���ڿ��� ��ȯ
char *uintToBinary(unsigned int i); // ��ȣ ���� 32��Ʈ ������, 2���� ���ڿ��� ��ȯ

int binaryToInt(char *s);           // 2���� ���ڿ���, ��ȣ �ִ� 32��Ʈ ������ ��ȯ
unsigned int binaryToUint(char *s); // 2���� ���ڿ���, ��ȣ ���� 32��Ʈ ������ ��ȯ

#endif
