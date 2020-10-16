#include<stdio.h>
//冒泡排序

int maopao(int *a,int n) //简单冒泡排序
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - j - 1; i++)
		{
			if (a[i + 1] < a[i])
			{
				int tmp = a[i];
				 a[i] = a[i + 1];
				 a[i + 1] = tmp;
			}
		}
	}
	
}
int main()
{
	int a[9] = { 9, 5, 6, 7, 2, 4, 8, 3, 1 };
	maopao(a, 9);
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
/* ***********************************************  */
int maopao(int* a,int n) //改变循环终止条件便于理解
{
	for (int end = n - 1; end > 0;end--)
    {
		for (int i = 0; i < end; i++)
		{
			if (a[i + 1] < a[i])
			{
				int tem = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tem;
			}
		}
	}
}


int main()
{
	int a[10] = { 1, 5, 9, 7, 8, 6, 4, 3, 2 };
	maopao(a,10);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
/* ***************************************** */
int greater(int x1, int x2)//运用回调函数进行函数调用 提高代码的复用性
{
	return x1 > x2 ? 1 : 0;
}
int less(int x1,int x2)
{
	return x1 < x2 ? 1 : 0;
}
int maopao(int *a, int n,int (*p_compear)(int,int))
{
	for (int end = n-1; end > 0; end--)
	{
		for (int i = 0; i < end; i++)
		{
			if (p_compear (a[i + 1] ,a[i]))
			{
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
	
}
int main()
{
	int a[9] = { 5, 6, 4, 9, 2, 3, 1, 8, 7 };
	maopao(a,9,less);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", a[i]);
	}

	/*maopao(a, 9, greater);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", a[i]);
	}*/
	return 0;
}