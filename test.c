#include <stdio.h>
#include<stdlib.h>
int euclidean(int d, int f);
#define MAX 100
#define YIWEI 3
#define	YIWEI2 3

void yiweijiami()//��λ������ܺ���
{
	char C[MAX];
	char M[MAX];
	int K = YIWEI, i;
	printf("����������M(��������հ״�)\n");
	//gets_s(M + 1, 20);
	scanf_s("%s", M,20);
	for (i = 0; M[i] != '\0'; i++)
	{
		C[i] = (M[i] - 'a' + K) % 26 + 'a';
	}
	C[i] = '\0';
	printf("���ܺ��������:\n%s\n", C);
}
void yiweijiemi()//��λ������ܺ���
{
	char C[MAX];
	char M[MAX];
	int K = YIWEI, i;
	//����
	printf("����������C(��������հ״�)\n");
	//gets_s(C + 1, 20);
	scanf_s("%s", C,20);
	for (i = 0; C[i] != '\0'; i++)
	{
		M[i] = (C[i] - 'a' - K) % 26 + 'a';
	}
	M[i] = '\0';
	printf("���ܺ��������:\n%s\n", M);
}
void chengshujiami()//���������㷨
{
	char C[MAX];
	char M[MAX];
	int K = YIWEI, i;
	//����
	printf("����������M(��������հ״�)\n");
	scanf_s("%s", M, 20);
	for (i = 0; M[i] != '\0'; i++)
	{
		C[i] = (M[i] - 'a')*K % 26 + 'a';
		//C[i] = (M[i] - 'a' + K) % 26 + 'a';
		//return (a - 'a') * secret % MOD_NUM + 'a';
	}
	C[i] = '\0';
	printf("���ܺ��������:\n%s\n", C);
	//printf("��������");
}
void chengshujiemi()//���������㷨
{
	char C[MAX];
	char M[MAX];
	int K = YIWEI, i;
	//����
	printf("����������C(��������հ״�)\n");
	scanf_s("%s", C, 20);
	for (i = 0; C[i] != '\0'; i++)
	{
		M[i] = (C[i] - 'a')* euclidean(K, 26) % 26 + 'a';
			//return (ciphertext - 'a') * euclidean(secret, MOD_NUM) % MOD_NUM + 'a';
		//M[i] = (C[i] - 'a' - K) % 26 + 'a';
	}
	M[i] = '\0';
	printf("���ܺ��������:\n%s\n", M);
	//printf("��������");
}
int euclidean(int d, int f)//ŷ������㷨 ���ڳ˷���Ԫ
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
void fangshejiami()//�����������
{
	char C[MAX];
	char M[MAX];
	int K = 5;
	int i;
	int z = 0;
	int K2 = 8;
	//int K = YIWEI, i;
	//int K2 = YIWEI2;
	//����
	printf("����������M(��������հ״�)\n");
	scanf_s("%s", M, 20);
	for (i = 0; M[i] != '\0'; i++)
	{
		if (M[i] >= 'A' && M[i] <= 'Z')
		{
			C[z] = (K*(M[i] - 'A') + K2) % 26 + 'A';
		}
		else if (M[i] >= 'a' && M[i] <= 'z')
		{
			C[z] = (K*(M[i] - 'a') + K2) % 26 + 'a';
		}
		else
		{  //�ж��Ƿ��ǿո�
			C[z] = M[i];
		}
		z++;
	}
		//C[i] = (M[i] - 'a' + K) % 26 + 'a';
		
	C[i] = '\0';
	printf("���ܺ��������:\n%s\n", C);
	//printf("��������");
	//printf("�������");
}
void fangshejiemi()
{
	char C[MAX];
	char M[MAX];
	int K = 5;
	int i;
	int z = 0;
	int K2 = 8;
	int K3 = 21;
	//int K = YIWEI, i;
	//int K2 = YIWEI2;
	//����
	printf("����������C(��������հ״�)\n");
	scanf_s("%s", C, 20);
	for (i = 0; C[i] != '\0'; i++)
	{
		if (C[i] >= 'A' && C[i] <= 'Z')
		{
			M[z] = (K3*((C[i] - 'A') - K2)) % 26 + 'A';
			if (K3*((C[i] - 'A') - K2) < 0)
			{
				M[z] = M[z] + 26;
			}
		}
		else if (C[i] >= 'a' && C[i] <= 'z'){
			M[z] = (K3*((C[i] - 'a') - K2)) % 26 + 'a';
			if (K3*((C[i] - 'a') - K2) < 0){  //������
				M[z] = M[z] + 26;
			}
		}
		else{  //�ж��Ƿ��ǿո�
			M[z] = C[i];
		}
		z++;
	}
	
	//C[i] = (M[i] - 'a' + K) % 26 + 'a';

	M[i] = '\0';
	printf("���ܺ��������:\n%s\n", M);
	//printf("��������");
	//printf("�������");
	//printf("�������");
}
void choose1()//��ҳѡ�����
{
	int test1 = 1;
	while (test1)
	{
		printf("\n������ѡ��1����λ���� 2���������� 3���������� 0���˳���\n");
		int n;
		scanf_s("%d",&n);
		if (n == 1)
		{
			int test = 1;
			while (test)//���ڲ˵���ѡ��
			{
				printf("\n������ѡ��(1������  2������  0���˳�):\n");
				int n;
				scanf_s("%d",&n);
				if (n == 1)
				{
					yiweijiami();
				}
				else if (n == 2)
				{
					yiweijiemi();
				}
				else if (n == 0)
				{
					printf("��ӭʹ�ã���\n");
					test = 0;
					choose1();
				}
				else
				{
					printf("�������!\n���������룡");
					choose1();
				}
			}
		}
		else if (n == 2)
		{
			int test = 1;
			while (test)//���ڲ˵���ѡ��
			{
				printf("\n������ѡ��(1������  2������  0���˳�):\n");
				int n;
				scanf_s("%d", &n);
				if (n == 1)
				{
					chengshujiami();
				}
				else if (n == 2)
				{
					chengshujiemi();
				}
				else if (n == 0)
				{
					printf("��ӭʹ�ã���\n");
					test = 0;
					return;
				}
				else
				{
					printf("�������!\n���������룡");
					choose1();
				}
			}
		}
		else if (n == 3)
		{
			int test = 1;
			while (test)//���ڲ˵���ѡ��
			{
				printf("\n������ѡ��(1������  2������  0���˳�):\n");
				int n;
				scanf_s("%d", &n);
				if (n == 1)
				{
					fangshejiami();
				}
				else if (n == 2)
				{
					fangshejiemi();
				}
				else if (n == 0)
				{
					printf("��ӭʹ�ã���\n");
					test = 0;
					return;
				}
				else
				{
					printf("�������!\n���������룡");
					choose1();
				}
			}
		}
		else if (n == 0)
		{
			printf("��ӭʹ�ã���\n");
			test1 = 0;
			return;
		}
		else
		{
			printf("�������!\n���������룡");
			choose1();
		}
	}
	
}
int main()
{
	
	choose1();
	//����
	return 0;
}