��Ŀ���ƣ�
���Ͼ���
��Ŀ���ݣ�
��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
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
		printf("%d��λ����[%d][%d]", ans, i, j);
	}

	return 0;

}


��Ŀ���ƣ�
�ַ�����ת���
��Ŀ���ݣ�
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����



���磺����s1 = AABCD��s2 = BCDAA������1

����s1 = abcd��s2 = ACBD������0.



AABCD����һ���ַ��õ�ABCDA

AABCD���������ַ��õ�BCDAA

AABCD����һ���ַ��õ�DAABC
void Rotate(char *str, int k)
{
	int len = strlen(str);
	k %= len;
	while (k--)//k--ʹ���귵��k     --kʹ���귵��k-1��ֵ
	{
		int i = 1;
		char tmp = str[0];//ʵ��˼���� ����Ҫ��ת��λ��������ŵ�tmp�� Ȼ�󸲸�ǰ����ַ�
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