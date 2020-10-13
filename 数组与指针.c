#include<stdio.h>
int main()
{
	/*int a[4] = { 1, 2, 3, 4 };
	char b[4] = { 'a', 'b' };*/
	//a数组名  代表数组首元素的地址
	//&a 代表数组地址  int(*p)[4]
	//sizeof 与 strlen 的区别
	//printf("%d\n", sizeof(a));//16  int类型占用4个字节 a是首元素的地址 但是这里是编译器特殊处理 指代真个元素占用内存的大小
	//printf("%d\n", sizeof(&a));//4  &a代表数组的地址  只要是指针类型 在32为系统中就是4个字节 
	//printf("%d\n", sizeof(a + 1));// 4 a+1即为数组第二个元素的地址 只要是指针就是4个字节
	//printf("%d\n", sizeof(*a));//对a数组的首地址进行解引用 得到元素的字节大小
	//int a[] = { 1, 2, 3, 4 };
	//char b[4] = { 'a', 'b' };
	//printf("%d\n", sizeof(a));  //16
	//printf("%d\n", sizeof(a + 0)); //4 数组第一个元素的地址 只要是地址就是4个字节 
	//printf("%d\n", sizeof(*a)); //4 首元素解引用
	//printf("%d\n", sizeof(a + 1)); //4指针
	//printf("%d\n", sizeof(a[1])); //4 首元素大小 等价于 *（a+1）
	//printf("%d\n", sizeof(&a)); // 4 char** 类型只要是指针就是4个字节
	//printf("%d\n", sizeof(*&a)); // 16 对a数组的地址解引用就是求数组元素的总大小
	//printf("%d\n", sizeof(&a + 1));//4 指针
	//printf("%d\n", sizeof(&a[0])); //4 元素取地址 就是指针
	//printf("%d\n", sizeof(&a[0] + 1)); // 4 指针+1还是指针

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; //这是一个字符数组
	printf("%d\n", sizeof(arr));  //6 数组的大小 char类型一个字符
	printf("%d\n", sizeof(arr + 0));//首元素的地址+1 还是指针
	printf("%d\n", sizeof(*arr)); //1 对数组首元素解引用就是求数组元素大小
	printf("%d\n", sizeof(arr[1]));//1 *（arr+1）数组首元素的大小
	printf("%d\n", sizeof(&arr));//4 指针类型 
	printf("%d\n", sizeof(&arr + 1)); //4 指针类型
	printf("%d\n\n\n", sizeof(&arr[0] + 1)); //4 指针类型

	//// strlen(const char* p)
	//printf("%d\n", strlen(arr)); // 随机值
	//printf("%d\n", strlen(arr + 0)); // 同上
	////printf("%d\n", strlen(*arr)); // 编译报错或警告
	////printf("%d\n", strlen(arr[1])); // 编译报错或警告
	////printf("%d\n", strlen(&arr)); // 编译报错或警告
	////printf("%d\n", strlen(&arr + 1)); // 编译报错或警告
	//printf("%d\n", strlen(&arr[0] + 1)); // 上面随机值-1


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
	///*printf("%d\n", strlen(*arr)); // 编译报错或警告
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
	///*printf("%d\n", strlen(*p)); // 编译报错或警告
	//printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p + 1));*/
	//printf("%d\n", strlen(&p[0] + 1)); // 5

	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));   // 48  a的类型int(*p)[4]
	printf("%d\n", sizeof(a[0][0])); // 4
	printf("%d\n", sizeof(a[0])); // 16  a[0]是第0行的数组名 a[0]的类型：int*
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