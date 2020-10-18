题目名称：
杨氏矩阵
题目内容：
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
#include <stdio.h>
int search(int (*p)[4], int n, int m ,int x,int *pi,int *pj )
{
	int i = 0; int j = n - 1;
	while (i < m && j > 0)
	{
		if (p[i][j] < x)
		{
			++i;
		}
		else if (p[i][j]>x)
		{
			--j;
		}
		else
		{
			*pi = i;
			*pj = j;
			return 1;

		}
	}
	return 0;
}
int main()
{
	int a[4][4] = { { 1, 3, 5, 6 }, 
					{ 2, 4, 8, 9 },
					{ 3, 6, 11, 15 },
					{ 4, 8, 15, 18 } };
	int ans = 11;
	int i = -1;
	int j = -1;
	int k =search(a,4,4,ans,&i,&j);
	if (k)
	{
		printf("%d的位置在[%d][%d]", ans, i, j);
	}

	return 0;

}


题目名称：
字符串旋转结果
题目内容：
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。



例如：给定s1 = AABCD和s2 = BCDAA，返回1

给定s1 = abcd和s2 = ACBD，返回0.



AABCD左旋一个字符得到ABCDA

AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAABC
void Rotate(char *str, int k)
{
	int len = strlen(str);
	k %= len;
	while (k--)//k--使用完返回k     --k使用完返回k-1的值
	{
		int i = 1;
		char tmp = str[0];//实现思想是 把需要旋转的位数按次序放到tmp中 然后覆盖前面的字符
		for (; i < len; ++i)
		{
			str[i - 1] = str[i];
		}
		str[len - 1] = tmp;
	}
}
int main()
{
	char a[] = "abcd";
	Rotate(a, 2);
	printf("%s\n", a);
	return 0;
}