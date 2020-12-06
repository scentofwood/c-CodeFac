#include <stdio.h>
#include <string.h>

int justify(char *src, char *trg, int trg_size)
{
	int src_len, trg_len;

	src_len = strlen(src);
	if (src_len >= trg_size)
	{
		trg_len = trg_size;
		strncpy(trg, src, trg_len);
	}
	else
	{
		trg_len = src_len;
		strncpy(trg, src, trg_len);
		memset(trg+trg_len, 0x20, trg_size-trg_len);
	}
	return trg_len;
}

int main()
{
    char c_1[20+1], c_2[10+1];
	int  len, n;
    memset(c_1, 0x00, sizeof(c_1));
    memset(c_2, 0x00, sizeof(c_2));

    strcpy(c_1, "abcdefghijklmnopqrst");

	n = 10;
	len = justify(c_1, c_2, n);
	/***************************************************************************/
	printf("\n\n[%02d:%s] -> [%02d:%s]\n\n", strlen(c_1), c_1, strlen(c_2), c_2);
	/***************************************************************************/
	return 0;
}
