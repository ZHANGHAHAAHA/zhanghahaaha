#include<stdio.h>
int my_strcmp(char* ch1, char* ch2)
{
	assert(ch1);
	assert(ch2);
	while (*ch1 == *ch2)
	{
		if (*ch1 == '\0' || *ch2 == '\0')
		{
			return 0;
		}
		ch1++;
		ch2++;
	}
	return *ch1 - *ch2;
}

int main()
{
	char arr[] = "bite";
	char str[] = "Zhang haohua";
	int ret = my_strcmp(arr, str);
	printf("%d\n", ret);
	return 0;
}
//char *my_strcpy(char *ch1, const char *ch2)
//{
//	char *ret = ch1;
//	while (*ch1++ = *ch2++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "bite";
//	char arr2[20] = "Zhang haohua";
//	my_strcpy(arr1, arr2);
//	printf("%s\n",arr1);
//	return 0;
//}
//char *my_strcpy(char *dest, const char *str)
//{
//	char *ret = dest;
//	while (*dest++ = *str++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[64] = "hello";
//	char arr2[] = "world";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

void* my_memcpy(void* dst, const void* src, int size)
{
	assert(dst);
	assert(src);

	char* str_dst = (char*)dst;
	char* str_src = (char*)src;

	for (int i = 0; i < size; ++i)
	{
		str_dst[i] = str_src[i];
	}

	return dst;
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5];

	my_memcpy(b, a, sizeof(int)* 5);

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	double c[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double d[5];

	my_memcpy(d, c, sizeof(double)* 5);

	for (int i = 0; i < 5; ++i)
	{
		printf("%f ", d[i]);
	}
	printf("\n");


	const int* p1 = NULL;
	int* p2 = NULL;

	p1 = p2;
	p2 = p1; // x

	// 内存后重叠，倒着拷贝即可
	char str[100] = "hello world";  // ->hello hello world
	memmove(str + 6, str, 12);
	printf("%s\n", str);

	// 内存前重叠，正着拷贝即可
	char s[100] = "      hello world"; //  hello world world
	my_memcpy(str, str + 6, 11);
	printf("%s\n", str);

	return 0;
}