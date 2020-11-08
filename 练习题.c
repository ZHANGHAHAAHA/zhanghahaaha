#include<stdio.h>
#include<stdlib.h>
#include <string.h>
/*************1********** 求两个数的最小公倍数 */
//int sum(int A, int B)
//{
//	int i = 1;
//	while (A*i%B != 0)
//	{
//		++i;
//	}
//	return A*i;
//}
//int main()
//{
//	int A, B;
//	printf("请输入两个正整数\n");
//	scanf_s("%d%d", &A, &B, 4, 4);
//	sum(A, B);
//	printf("%d\n", sum(A,B));
//	return 0;
//}

/*******1***************递归调用 斐波那契函数*/

//int fib(int n)
//{
//	int cnt = 0;
//	cnt++;
//	if (n == 0)
//	{
//		return 1;
//	}
//	else if (n==1)
//	{
//		return 2;
//	}
//	else
//	{
//		return fib(n - 1) + fib(n - 2); //实际最后是一棵树 子叶是0 
//	}
//
//}
//int main()
//{
//	printf("请输入一个整数\n");
//	int n = 0;
//	scanf_s("%d", &n, 4);
//	fib(n);
//	printf("%d", cnt);
//	return 0;
//}
/******** 3 *******************************/
//int main()
//{
//	
//	int x = 1;
//	do{
//		printf("%2d\n", x++);//x加1
//		getchar();
//	} while (x--);//x-1
//	
//	/*最后函数是死循环*/
//	return 0;
//}
/* *******************  4 **********************/
//int main()
//{
//	int i = 1;
//	int j;
//	j = i++;//   i++返回使用后的值    但是先用i  再++  所以j=1；i=2
//	printf("%d %d", j, i);
//	return 0;
//}
/***************5 ******************************/
//int main()
//{
//	int i = 10;
//	int j = 20;
//	int k = 3;
//	int m = 3;
//	k *= i + j;   // i+j=30   k = k*(i+j)   k=90
//	m += i*j;  // 先计算等号右边
//	printf("%d  %d", k,m);
//	return 0;
//}

/************** 6 ********************/
//int a = 1;
//void test()
//{
//	int a = 2;
//	a += 1;
//}
//int main()
//{
//	test();
//	printf("%d\n", a);//考察局部变量和全局变量的作用域  打印语句只能调用全局变量    因为局部变量的作用域在test（）函数内
//	return 0;
//}

/* ******** 7 ***************/
//int main()
//{
//	double x = 2;
//	double y = x + 3 / 2;
//	printf("%f", y);//3.000000 
//	return 0;
//}

/* ************** 8 **************************/
//int main()
//{
//	int x = 0;
//	int y = 0;
//	for (x = 0, y = 0; (y = 123) && (x < 4); x++)
//	{
//		printf("%d", x);//0 1 2 3     
//	}
//	return 0;
//}
/* **************  9   *********************指针的运用*/
//int main()
//{
//	int year = 1009;
//	int *p = &year;
//	//(*p)++;
//	*p+= 1;
//	printf("%d", *p);
//	return 0;
//}


// i like china. -->china. like i      字符逆置函数  先整体逆置  .anihc ekil i    然后再单个单词逆置  china. like i  调用两次逆置函数
void Reverse(char * start, char * end)
{
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		++start;
		--end;
	}
}
int main()
{
	char str[100];
	gets_s(str,100);
	int len = strlen(str);
	Reverse(str,str+len-1);
	char *start = str, *end = str;
	while (*end != '\0')
	{
		if (*end == ' ')
		{
			Reverse(start, end - 1);
			start = end + 1;
			end = start;
		}
		else
		{
			++end;
		}
	}
	Reverse(start, end - 1);
	printf("%s", str);
	return 0;
}