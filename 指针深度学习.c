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
//int main()//有问题
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	int *p = arr;//这里是数组元素的首地址    &arr是整个数组的地址
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
//void print2(int(*p)[5], int x, int y)//把二维数组看成一维数组 传递参数
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
//	int arr[5];//arr是一个整型数组，数组五个元素，每个元素的类型是int
//	int *parr1[10];//parr1是一个指针数组 数组有10个元素 每个元素类型是int*
//	
//	int(*parr2)[10];//parr2是一个数组指针，该指针指向了一个数组，数组的10个元素类型是int
//	int(*parr3[10])[5];//parr3是一个指针数组，该数组有十个元素，每个指针指向一个五个元素的数组
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
//void test(int *arr)//第一行是五个元素的指针 int*类型是不可以的
//{
//
//}
//void test(int *arr[5])//第一行是五个元素的指针 int*类型是不可以的
//{
//
//}
//void test(int( *arr)[5])//正确的
//{
//
//}
//void test(int**arr[5])//二级指针是用来存放一级指针的地址的 这个是不对的
//{
//
//}
//
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5 };//可以省略行但是不能省略列，多维数组同样 不能省略第一个 后面可省略
//	test(arr);
//	return 0;
//}
//void test1(int* p)//你要int*整型指针变量我就凑给你
//{
//
//}
//void test2(char* p)
//{
//
//}
//int main()
//{
//	//代码分割问题
//	//int *p1, p2; //p1是指针 p2是整型
//		//int *p1, //*p2; p1,p2都是指针
//	int a = 10;
//	int* ptr = &a;
//	int arr[10];
//	test1(&a);//整型变量的地址
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
	int(*p)[10] = &arr;//取出数组的指针，p就是数组指针
	//指向函数的指针——存放函数的地址
	int(*pf)(int,int) = &Add;//pf加上*代表是指针 （）代表pf是个函数指针,要写出来返回值类型和参数类型与个数
	int sum = (*pf)(2, 3);
	printf("%d\n", sum);
	int sum = pf(2, 3);
	printf("%d\n", sum);//*带不带，带几个无所谓
	    sum = Add(2, 3);
	printf("%d\n", sum);
	//int(*ps)(const char*) = &my_strlen;
	/*printf("%p\n", &Add);
	printf("%p\n", Add);*/
	//函数名和&函数名都是函数的地址
	return 0;
}