#include<stdio.h>
int main()
{
	/*int a[4] = { 1, 2, 3, 4 };
	char b[4] = { 'a', 'b' };*/
	//a������  ����������Ԫ�صĵ�ַ
	//&a ���������ַ  int(*p)[4]
	//sizeof �� strlen ������
	//printf("%d\n", sizeof(a));//16  int����ռ��4���ֽ� a����Ԫ�صĵ�ַ ���������Ǳ��������⴦�� ָ�����Ԫ��ռ���ڴ�Ĵ�С
	//printf("%d\n", sizeof(&a));//4  &a��������ĵ�ַ  ֻҪ��ָ������ ��32Ϊϵͳ�о���4���ֽ� 
	//printf("%d\n", sizeof(a + 1));// 4 a+1��Ϊ����ڶ���Ԫ�صĵ�ַ ֻҪ��ָ�����4���ֽ�
	//printf("%d\n", sizeof(*a));//��a������׵�ַ���н����� �õ�Ԫ�ص��ֽڴ�С
	//int a[] = { 1, 2, 3, 4 };
	//char b[4] = { 'a', 'b' };
	//printf("%d\n", sizeof(a));  //16
	//printf("%d\n", sizeof(a + 0)); //4 �����һ��Ԫ�صĵ�ַ ֻҪ�ǵ�ַ����4���ֽ� 
	//printf("%d\n", sizeof(*a)); //4 ��Ԫ�ؽ�����
	//printf("%d\n", sizeof(a + 1)); //4ָ��
	//printf("%d\n", sizeof(a[1])); //4 ��Ԫ�ش�С �ȼ��� *��a+1��
	//printf("%d\n", sizeof(&a)); // 4 char** ����ֻҪ��ָ�����4���ֽ�
	//printf("%d\n", sizeof(*&a)); // 16 ��a����ĵ�ַ�����þ���������Ԫ�ص��ܴ�С
	//printf("%d\n", sizeof(&a + 1));//4 ָ��
	//printf("%d\n", sizeof(&a[0])); //4 Ԫ��ȡ��ַ ����ָ��
	//printf("%d\n", sizeof(&a[0] + 1)); // 4 ָ��+1����ָ��

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; //����һ���ַ�����
	printf("%d\n", sizeof(arr));  //6 ����Ĵ�С char����һ���ַ�
	printf("%d\n", sizeof(arr + 0));//��Ԫ�صĵ�ַ+1 ����ָ��
	printf("%d\n", sizeof(*arr)); //1 ��������Ԫ�ؽ����þ���������Ԫ�ش�С
	printf("%d\n", sizeof(arr[1]));//1 *��arr+1��������Ԫ�صĴ�С
	printf("%d\n", sizeof(&arr));//4 ָ������ 
	printf("%d\n", sizeof(&arr + 1)); //4 ָ������
	printf("%d\n\n\n", sizeof(&arr[0] + 1)); //4 ָ������

	//// strlen(const char* p)
	//printf("%d\n", strlen(arr)); // ���ֵ
	//printf("%d\n", strlen(arr + 0)); // ͬ��
	////printf("%d\n", strlen(*arr)); // ���뱨��򾯸�
	////printf("%d\n", strlen(arr[1])); // ���뱨��򾯸�
	////printf("%d\n", strlen(&arr)); // ���뱨��򾯸�
	////printf("%d\n", strlen(&arr + 1)); // ���뱨��򾯸�
	//printf("%d\n", strlen(&arr[0] + 1)); // �������ֵ-1


	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr)); // 7
	//printf("%d\n", sizeof(arr + 0)); // 4
	//printf("%d\n", sizeof(*arr)); // 1
	//printf("%d\n", sizeof(arr[1])); // 1
	//printf("%d\n", sizeof(&arr)); // 4
	//printf("%d\n", sizeof(&arr + 1)); // 4
	//printf("%d\n\n", sizeof(&arr[0] + 1)); // 4

	//printf("%d\n", strlen(arr)); // 6
	//printf("%d\n", strlen(arr + 0)); // 6
	///*printf("%d\n", strlen(*arr)); // ���뱨��򾯸�
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));
	//printf("%d\n", strlen(&arr + 1));*/
	//printf("%d\n\n", strlen(&arr[0] + 1)); // 5

	//char *p = "abcdef";
	//printf("%d\n", sizeof(p)); // 4
	//printf("%d\n", sizeof(p + 1)); // 4
	//printf("%d\n", sizeof(*p)); // 1
	//printf("%d\n", sizeof(p[0])); // 1
	//printf("%d\n", sizeof(&p)); // 4
	//printf("%d\n", sizeof(&p + 1)); // 4
	//printf("%d\n", sizeof(&p[0] + 1)); // 4

	//printf("%d\n", strlen(p)); // 6
	//printf("%d\n", strlen(p + 1)); // 5
	///*printf("%d\n", strlen(*p)); // ���뱨��򾯸�
	//printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p + 1));*/
	//printf("%d\n", strlen(&p[0] + 1)); // 5

	//��ά����
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));   // 48  a������int(*p)[4]
	printf("%d\n", sizeof(a[0][0])); // 4
	printf("%d\n", sizeof(a[0])); // 16  a[0]�ǵ�0�е������� a[0]�����ͣ�int*
	printf("%d\n", sizeof(a[0] + 1)); // 4
	printf("%d\n", sizeof(*(a[0] + 1))); // 4
	printf("%d\n", sizeof(a + 1)); // 4
	printf("%d\n", sizeof(*(a + 1))); // 16
	printf("%d\n", sizeof(&a[0] + 1)); // 4
	printf("%d\n", sizeof(*(&a[0] + 1))); // 4
	printf("%d\n", sizeof(*a)); // 16
	printf("%d\n", sizeof(a[3])); // 16

	return 0;
}
	return 0;
}