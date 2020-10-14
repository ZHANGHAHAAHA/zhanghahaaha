#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int euclidean(int d, int f);
#define MAX 100
void choose1()//首界面操作选择函数
{
	int test = 1;
	while (test)
	{
		int k1 = 0;
		int k2 = 0;
		printf("请输入k1，k2的值\n");
		scanf_s("%d %d", &k1, &k2);//输入不同的参数
		if (k1 == 0 && k2 != 0)
		{

			printf("调用移位密码函数");
			printf("\n请输入操作序号(1：加密  2：解密  0：退出):\n");
			int n;
			scanf_s("%d", &n);
			if (n == 1)
			{
				yiweijiami(k1, k2);
			}
			else if (n == 2)
			{
				yiweijiemi(k1, k2);
			}
			else if (n == 0)
			{
				printf("欢迎使用！！\n");
				test = 0;
				choose1();
			}
			else
			{
				printf("输入错误!\n请重新输入！");
				choose1();
			}

		}
		else if (k1 != 0 && k2 == 0)
		{
			printf("调用乘数密码函数");
			printf("\n请输入操作序号(1：加密  2：解密  0：退出):\n");
			int n;
			scanf_s("%d", &n);
			if (n == 1)
			{
				chengshujiami(k1, k2);
			}
			else if (n == 2)
			{
				chengshujiemi(k1, k2);
			}
			else if (n == 0)
			{
				printf("欢迎使用！！\n");
				test = 0;
				choose1();
			}
			else
			{
				printf("输入错误!\n请重新输入！");
				choose1();
			}
		}
		else if (k1 != 0 && k2 != 0)
		{
			printf("调用仿射密码函数");
			printf("\n请输入操作序号(1：加密  2：解密  0：退出):\n");
			int n;
			scanf_s("%d", &n);
			if (n == 1)
			{
				fangshejiami(k1, k2);
			}
			else if (n == 2)
			{
				fangshejiemi(k1, k2);
			}
			else if (n == 0)
			{
				printf("欢迎使用！！\n");
				test = 0;
				choose1();
			}
		}
		else
		{
			printf("输入错误!\n请重新输入！");
			choose1();
		}
	}

}
int yiweijiami(int x, int y)//移位密码加密函数
{
	char C[MAX];
	char M[MAX];
	int k1 = x, i;
	int k2 = y;
	printf("请输入明文M(不可输入空白串)\n");
	scanf_s("%s", M, 20);
	for (i = 0; M[i] != '\0'; i++)
	{
		C[i] = (M[i] - 'a' + k2) % 26 + 'a';
	}
	C[i] = '\0';
	printf("加密后的密文是:\n%s\n", C);
}
int yiweijiemi(int x, int  y)//移位密码解密函数
{
	char C[MAX];
	char M[MAX];
	int k1 = x, i;
	int k2 = y;
	printf("请输入密文C(不可输入空白串)\n");
	scanf_s("%s", C, 20);
	for (i = 0; C[i] != '\0'; i++)
	{
		M[i] = (C[i] - 'a' - k2) % 26 + 'a';
	}
	M[i] = '\0';
	printf("解密后的明文是:\n%s\n", M);
}
int chengshujiami(int x, int y)//乘数加密算法
{
	char C[MAX];
	char M[MAX];
	int k1 = x, i;
	int k2 = y;
	printf("请输入明文M(不可输入空白串)\n");
	scanf_s("%s", M, 20);
	for (i = 0; M[i] != '\0'; i++)
	{
		C[i] = (M[i] - 'a' + k2)*k1 % 26 + 'a';
	}
	C[i] = '\0';
	printf("加密后的密文是:\n%s\n", C);
}
int chengshujiemi(int x, int y)//乘数解密算法
{
	char C[MAX];
	char M[MAX];
	int k1 = x, i;
	int k2 = y;
	printf("请输入密文C(不可输入空白串)\n");
	scanf_s("%s", C, 20);
	for (i = 0; C[i] != '\0'; i++)
	{
		M[i] = (C[i] - 'a')* euclidean(k1, 26) % 26 + 'a';
	}
	M[i] = '\0';
	printf("解密后的明文是:\n%s\n", M);
}
int euclidean(int d, int f)//欧几里得算法 用于乘法逆元
{
	//1
	int x[3], y[3];
	x[0] = 1; x[1] = 0; x[2] = f;
	y[0] = 0; y[1] = 1; y[2] = d;
	//2
flag:	if (y[2] == 0)
	return -1; //null
		//3
		if (y[2] == 1)
			return y[1];
		//4
		int q = x[2] / y[2];
		int T[3] = { x[0] - q*y[0], x[1] - q*y[1], x[2] - q*y[2] };
		x[0] = y[0]; x[1] = y[1]; x[2] = y[2];
		y[0] = T[0]; y[1] = T[1]; y[2] = T[2];
		goto flag;
}
int fangshejiami(int x, int y)//仿射密码加密
{
	char C[MAX];
	char M[MAX];
	int k1 = x;//5
	int i;
	int z = 0;
	int k2 = y;//8
	printf("请输入明文M(不可输入空白串)\n");
	scanf_s("%s", M, 20);
	for (i = 0; M[i] != '\0'; i++)
	{
		if (M[i] >= 'A' && M[i] <= 'Z')
		{
			C[z] = (k1*(M[i] - 'A') + k2) % 26 + 'A';
		}
		else if (M[i] >= 'a' && M[i] <= 'z')
		{
			C[z] = (k1*(M[i] - 'a') + k2) % 26 + 'a';
		}
		else
		{  //判断是否是空格
			C[z] = M[i];
		}
		z++;
	}

	C[i] = '\0';
	printf("加密后的密文是:\n%s\n", C);
}
int fangshejiemi(int x, int y)
{
	char C[MAX];
	char M[MAX];
	int k1 = x;//5
	int i;
	int z = 0;
	int k2 = 8;//8
	int K3 =  euclidean(k1, 26);
	printf("请输入密文C(不可输入空白串)\n");
	scanf_s("%s", C, 20);
	for (i = 0; C[i] != '\0'; i++)
	{
		if (C[i] >= 'A' && C[i] <= 'Z')
		{
			M[z] = (K3*((C[i] - 'A') - k2)) % 26 + 'A';
			if (K3*((C[i] - 'A') - k2) < 0)
			{
				M[z] = M[z] + 26;
			}
		}
		else if (C[i] >= 'a' && C[i] <= 'z'){
			M[z] = (K3*((C[i] - 'a') - k2)) % 26 + 'a';
			if (K3*((C[i] - 'a') - k2) < 0){  //处理负数
				M[z] = M[z] + 26;
			}
		}
		else{  //判断是否是空格
			M[z] = C[i];
		}
		z++;
	}
	M[i] = '\0';
	printf("加密后的明文是:\n%s\n", M);
}


int main()
{
	choose1();
	return 0;
}