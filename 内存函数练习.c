#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>

// ģ��ʵ��
// ����+����
int my_strlen1(const char* str)
{
	assert(str);

	int n = 0;
	while (*str != '\0')
	{
		++n;
		++str;
	}

	return n;
}

// �ݹ� ȱ�㣺����str�ر𳤣����ܵ�����ջ���
int my_strlen2(const char* str)
{
	// 0  '\0'  NULL '0'
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen2(str + 1);
}

int my_strlen3(const char* str)
{
	const char* end = str;
	//while (*end != '\0')
	/*while (*end)
	{
	++end;
	}*/

	while (*end++);

	return end - str;
}

int f(int n)
{
	if (n == 1)
		return n;

	return n + f(n - 1);
}


int main()
{
	//int i = 0;
	//printf("%d\n", i);

	char s1[] = "hello\r\n\t\0";
	char s2[] = "hello1234";
	char s3[] = "0����"
	// unicode  ���뼯
	// gbk

	printf("%d\n", my_strlen3(s3));
	printf("%d\n", sizeof(s3));
	printf("%s\n", s3);

	//printf("%d\n", f(10000));




	//getchar();
	//system("pause");

	return 0;
}

char* my_strcpy1(char* dst, const char* src)
{
	assert(dst);
	assert(src);

	char* ret = dst;
	while (*src)
	{
		*dst = *src;
		++src;
		++dst;
	}
	*dst = '\0';

	return  ret;
}

char* my_strcpy2(char* dst, const char* src)
{
	//assert(dst != NULL);
	assert(dst);
	assert(src);

	char* ret = dst;
	while (*dst++ = *src++);
	return  ret;
}

int main()
{
	char* str1 = "hello";
	char str2[] = "world222";
	char str3[6];

	my_strcpy2(str3, my_strcpy2(str2, str1));
	//my_strcpy(str3, str1);
	printf("%s\n", str2);
	printf("%s\n", str3);



	return 0;
}

// strcpy  ���ǿ���
// strcat  ׷�ӿ���

int main()
{
	char url[128];
	char* name1 = "www.cplusplus.com";
	char* name2 = "reference/cstring/strcpy";
	my_strcpy2(NULL, "http://");
	strcat(url, name1);
	strcat(url, "/");
	strcat(url, name2);
	printf("%s\n", url);

	return 0;
}

//str1 > str2 ����1
//str1 == str2 ����0
//str1 < str2 ����-1
int my_strcmp1(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);

	while (*str1 && *str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		else
		{
			++str1;
			++str2;
		}
	}

	// "abcd" > "abc"
	// "abc" < "abcd"
	// "abc" == "abc"
	if (*str1)
		return 1;
	else if (*str2)
		return -1;
	else
		return 0;
}

int my_strcmp2(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);

	int ret = 0;
	// "abc"  == "abc"
	// "abcd" > "abc"
	// "abc" < "abcd"
	// ˼����
	//while (!(ret = *str1 - *str2) && *str1 && *str2)
	//while (!(ret = *str1 - *str2) && *str2)
	while (!(ret = (unsigned char)*str1 - (unsigned char)*str2) && *str1)
	{
		++str1;
		++str2;
	}

	if (ret > 0)
		return 1;
	else if (ret < 0)
		return -1;
	else
		return 0;
}

// 1234
// 4321

// ����󷵻�0
int ReverseInt(int i)
{
	long long ret = 0;
	while (i > 0)
	{
		int num = i % 10;
		ret = ret * 10 + num;
		i /= 10;
	}

	return (int)ret == ret ? (int)ret : 0;
}

int main()
{
	char* str1 = "abcd";
	char* str2 = "abc";

	printf("%d\n", my_strcmp2("abcd", "abc"));
	printf("%d\n", my_strcmp2("abc", "abcd"));
	printf("%d\n", my_strcmp2("abcd", "abcd"));
	printf("%d\n", my_strcmp2("abcd", "aacd"));
	printf("%d\n", my_strcmp2("aaad", "aacd"));

	printf("%d\n", ReverseInt(1234));
	printf("%d\n", sizeof(long long));


	return 0;
}


char* my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);

	while (*str1 != '\0')
	{
		if (*str1 != *str2)
		{
			++str1;
		}
		else
		{
			char* str2_start = str2++;
			char* str1_start = str1++;
			while (*str1 == *str2 && *str2 != '\0')
			{
				++str1;
				++str2;
			}

			if (*str2 == '\0') // ƥ������
			{
				return str1_start;
			}
			else
			{
				str2 = str2_start;
				str1 = str1_start + 1;
			}
		}
	}

	return NULL;
}

int main()
{
	//char* url = "https://v.bitedu.vip/login";
	char* url = "https://translate.google.cn/#view=home&op=translate&sl=zh-CN&tl=en&text=%E5%9F%9F%E5%90%8D";
	//char* pos1 = strstr(url, "://");
	char* pos1 = my_strstr(url, ":");

	char protocol[128];
	strncpy(protocol, url, pos1 - url);
	protocol[pos1 - url] = '\0';
	printf("%s\n", protocol);

	char domain_name[128];

	char*  domain_name_start = url + (pos1 - url) + 3;
	char* pos2 = my_strstr(domain_name_start, "/");
	strncpy(domain_name, domain_name_start, pos2 - domain_name_start);
	domain_name[pos2 - domain_name_start] = '\0';
	printf("%s\n", domain_name);

	/*strncat(domain_name, "/list/test/1", 5);
	printf("%s\n", domain_name);

	char* url1 = "https://v.bitedu.vip/login";
	char* url2 = "https://v.bitedu.vip.com/index";

	if (strncmp(url1, url2, 21) == 0)
	{
		printf("ͬһ����վ\n");
	}
	else
	{
		printf("����ͬһ����վ\n");
	}
*/
	return 0;
}


int main()
{
	char *p = "https://tower.im/teams/c7c7881c3dd841bebb1565bb6d939333/projects/";
	const char* sep = "/";
	char arr[300];
	char *str = NULL;
	strcpy(arr, p);//�����ݿ���һ�ݣ�����arr���������
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}

	return 0;
}

int main()
{
	FILE* fout = fopen("test.txt", "r");
	if (fout == NULL)
	{
		printf("���ļ�ʧ����: %s\n", strerror(2));
	}

	return 0;
}

// strxxx�ص����� 
// 1��strlen/strcpy/strcmp/strstr ����ʹ��+ģ��ʵ��
// 2�������⺯���˽�ʹ�ü���

// ������������
// size�ǿ������ֽ���
// void* ���ܽ����ã�����++ -- ��Ϊ�������Խ����������͵�ָ��
// ����ֵ����֧����������memcpy(c, memcpy(b, a));
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

void* my_memmove(void* dst, const void* src, int size)
{
	assert(src);
	assert(dst);

	char* str_dst = (char*)dst;
	const char* str_src = (const char*)src;
	// 1�����ص��������ǲ��ص��ұߵĿ��������ſ���
	// 2��ǰ�ص��������ǲ��ص���ߵĿ��������ſ���
	if (str_src < str_dst)
	{
		for (int end = size - 1; end >= 0; --end)
		{
			//*(str_dst+end) = *(str_src + end);
			str_dst[end] = str_src[end];
		}
	}
	else
	{
		for (int start = 0; start < size; ++start)
		{
			str_dst[start] = str_src[start];
		}
	}

	return dst;
}


int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5];

	my_memcpy(b, a, sizeof(int) * 5);

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	double c[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double d[5];

	my_memcpy(d, c, sizeof(double) * 5);

	for (int i = 0; i < 5; ++i)
	{
		printf("%f ", d[i]);
	}
	printf("\n");


	const int* p1 = NULL;
	int* p2 = NULL;

	p1 = p2;
	p2 = p1; // x
//	// �ڴ���ص������ſ�������
	char str1[100] = "hello world";  // ->hello hello world
	memcpy(str1 + 6, str1, 12);
	printf("%s\n", str1);
//
//	// �ڴ�ǰ�ص������ſ�������
	char str2[100] = "      hello world"; //  hello world world
	memcpy(str2, str2 + 6, 11);
	printf("%s\n", str2);

	return 0;
}

int main()
{
	int a[10];
	double b[10];

	memset(a, 0, sizeof(int) * 10);

	// ע���������ܰ�����ÿ��ֵ��ʼ�����ó�1
	memset(a, 1, sizeof(int) * 10); 

	memset(b, 0, sizeof(double) * 10);

	return 0;
}

 �ṹ�嶨����������ַ�ʽ֮һ
struct Stu
{
	char name[20];//����
	int age;//����
	char sex[5];//�Ա�
	char id[20];//ѧ��
}s2,s3; //�ֺŲ��ܶ�

int main()
{
	struct Stu s1;

	return 0;
}

typedef struct Stu
{
	char name[20];//����
	int age;//����
	char sex[5];//�Ա�
	char id[20];//ѧ��
}STUDENT; //�ֺŲ��ܶ�

int main()
{
	struct Stu s1;
	STUDENT s2;

	return 0;
}

struct ListNode
{
	int data;
	struct ListNode* next;
};

struct Node
{
	int data;
	struct Node* next;
};

struct Point
{
	int x;
	int y;
}p1;

typedef struct Point P;

struct Stu        //��������
{
	char name[15];//����
	int age;      //����
};

struct Node
{
	int data;
	struct Point p;
	struct Node* next;
};

int main()
{
	// ���ֳ�ʼ���ķ�ʽ
	struct Point p2;
	p2.x = 1;
	p2.y = 2;

	P p3 = {3,4};

	struct Stu s1;
	//s1.name = "peter";
	strcpy(s1.name, "peter");
	s1.age = 18;

	struct Stu s2 = { "peter", 18 };
	struct Stu s3 = { {'p','e','t','e','r'}, 18 };

	struct Node n1;
	n1.data = 1;
	n1.next = NULL;
	n1.p.x = 1;
	n1.p.y = 2;

	struct Node n2 = { 1, { 1, 2 }, NULL };

	return 0;
}

struct S1
{
	char c1;
	int i;
	char c2;
};

//struct S3
//{
//	char c1;
//	int i;
//};

struct S3
{
	double d;
	char c;
	int i;
};
// 16 

struct S4
{
	char c1;
	struct S3 s3; // 16
	double d;
};
// 32


#pragma pack(2)

struct S6
{
	char c1;
	int i;
	char c2;
};

#pragma pack()

struct S7
{
	char c1;
	int i;
	char c2;
};

struct S
{
	int data[10000];
	int num;
};

//�ṹ�崫�� -- ����ṹ��Ƚϴ󣬾�����ָ�루��ַ��
void print1(struct S* pss)
{
	//printf("%d\n", ss.num);
	pss->num = 1;
}

int main()
{
	struct S s = { { 1, 2, 3, 4 }, 1000 };
	int begin1 = clock();
	for (int i = 0; i < 100000; ++i)
	{
		print1(&s);
	}
	int end1 = clock();
	printf("%d\n", end1 - begin1);


	return 0;
}