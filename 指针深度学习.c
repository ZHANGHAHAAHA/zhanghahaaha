#include <stdio.h>
/*int main()
{
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[] = { 2, 3, 4, 5 };
	int arr3[] = { 3, 4, 5, 6 };

	int* arr4[] = { arr1, arr2, arr3 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("%d",arr4[i][j]);
		}
		printf("\n");
	}
	return 0;
	

}*/
//int main()//������
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	int *p = arr;//����������Ԫ�ص��׵�ַ    &arr����������ĵ�ַ
//	int i = 0;
//	for(i = 0; i < 5; i++);
//	{
//		printf("%d ",*(p+i));
//	}
//	return 0;
//}

/*void print1(int arr[3][5],int x,int y)
{
	for ()
}*/
//void print2(int(*p)[5], int x, int y)//�Ѷ�ά���鿴��һά���� ���ݲ���
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for(j = 0; j < 5; j++)
//		{
//			printf("%d ", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//	
//}

//int main()
//{
//	int arr[3][5] = { { 1, 2, 3, 4 }, { 2, 3, 4, 5 }, { 3, 4, 5, 6 } };
//	//print1(arr, 3, 5);
//	print2(arr,3,5);
//
//	return 0;
//}
//int main()
//{
//	int arr[5];//arr��һ���������飬�������Ԫ�أ�ÿ��Ԫ�ص�������int
//	int *parr1[10];//parr1��һ��ָ������ ������10��Ԫ�� ÿ��Ԫ��������int*
//	
//	int(*parr2)[10];//parr2��һ������ָ�룬��ָ��ָ����һ�����飬�����10��Ԫ��������int
//	int(*parr3[10])[5];//parr3��һ��ָ�����飬��������ʮ��Ԫ�أ�ÿ��ָ��ָ��һ�����Ԫ�ص�����
//	return 0;
//
//}
//void test(int arr[10])
//{
//
//}
//void test(int *arr)
//{
//
//}
//void test2(int *arr[20])
//{
//
//}
//void test2(int **arr)
//{
//
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int *arr2[] = { 0 };
//	test(arr);
//	test(arr2);
//	return 0;
//}
//void test(int arr[3][5])
//{
//
//}
//void test(int *arr)//��һ�������Ԫ�ص�ָ�� int*�����ǲ����Ե�
//{
//
//}
//void test(int *arr[5])//��һ�������Ԫ�ص�ָ�� int*�����ǲ����Ե�
//{
//
//}
//void test(int( *arr)[5])//��ȷ��
//{
//
//}
//void test(int**arr[5])//����ָ�����������һ��ָ��ĵ�ַ�� ����ǲ��Ե�
//{
//
//}
//
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5 };//����ʡ���е��ǲ���ʡ���У���ά����ͬ�� ����ʡ�Ե�һ�� �����ʡ��
//	test(arr);
//	return 0;
//}
//void test1(int* p)//��Ҫint*����ָ������Ҿʹո���
//{
//
//}
//void test2(char* p)
//{
//
//}
//int main()
//{
//	//����ָ�����
//	//int *p1, p2; //p1��ָ�� p2������
//		//int *p1, //*p2; p1,p2����ָ��
//	int a = 10;
//	int* ptr = &a;
//	int arr[10];
//	test1(&a);//���ͱ����ĵ�ַ
//	test1(ptr);
//	test1(arr);
//}
//void test(int** p)
//{
//
//}
//int main()
//{
//	int* p1;
//	int **ptr;
//	test(ptr);
//	test(&p1);
//	test();
//	return 0;
//}
int Add(int x, int y)
{
	return x + y;
}
int my_strlen(const char* str)
{

}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6 };
	int(*p)[10] = &arr;//ȡ�������ָ�룬p��������ָ��
	//ָ������ָ�롪����ź����ĵ�ַ
	int(*pf)(int,int) = &Add;//pf����*������ָ�� ��������pf�Ǹ�����ָ��,Ҫд��������ֵ���ͺͲ������������
	int sum = (*pf)(2, 3);
	printf("%d\n", sum);
	int sum = pf(2, 3);
	printf("%d\n", sum);//*������������������ν
	    sum = Add(2, 3);
	printf("%d\n", sum);
	//int(*ps)(const char*) = &my_strlen;
	/*printf("%p\n", &Add);
	printf("%p\n", Add);*/
	//��������&���������Ǻ����ĵ�ַ
	return 0;
}