#include <stdio.h>
#include <string.h>

void justify(char *src, char *trg, int *len)
{
	int src_len, trg_len;

	src_len = strlen(src);
	if (src_len >= *len)
	{
		trg_len = *len;
		strncpy(trg, src, trg_len);
	}
	else
	{
		trg_len = src_len;
		strncpy(trg, src, trg_len);
		memset(trg+trg_len, 0x20, *len-trg_len);
	}
	*len = trg_len;
}

int main()
{
    char c_1[20+1], c_2[10+1];
	int  len;
    memset(c_1, 0x00, sizeof(c_1));
    memset(c_2, 0x00, sizeof(c_2));

    strcpy(c_1, "abcdefghijklmnopqrst");

	len = 10;
	justify(c_1, c_2, &len);
	/***************************************************************************/
	printf("\n\n[%02d:%s] -> [%02d:%s]\n\n", strlen(c_1), c_1, strlen(c_2), c_2);
	/***************************************************************************/
	return 0;
}
