#include <string.h>

int main(void)
{
	int count = 0; 
	             //0123456789012345678901234567890123
	char s1[60] = "얼마나 | 많은 | 글들이 있을까?||d| ";
	char *ptr = NULL;
	ptr = strtok(s1, "|");
	while (ptr != NULL)
	{
		count++;
		printf("[%d][%s][%d]\n", count, ptr, ptr);
		ptr = strtok(NULL, "|"); 
	}
	printf("[%d] 끝 \n", count, ptr, ptr);

//	int i = 0;
//	for (i = 0; i < 60; i++)
//	{
//		if (i == 0)
//		{
//			ptr = strtok(s1, "|");
//		}
//		else
//		{
//			ptr = strtok(NULL, "|");
//		}
//		if (ptr != NULL)
//		{
//			count++;
//			printf("[%d][%s][%d]\n", count, ptr, ptr);
//		}
//		else
//		{
//			printf("[%d][%s][%d] 끝\n", count, ptr, ptr);
//			break;
//		}
//	}
	return 0;
}
