#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"


int  main()
{
	int i=0, j=0, flag=0;
	int b1=0,b2=0,nc=0;
	long c=0;
	char sc[255],so[255];
	char simb[16]="0123456789ABCDEF";
	int raz[14];

	printf("Vvedite 2 sistemi schislenia i chislo v pervoy sisteme\n");
	scanf("%d %d", &b1, &b2);
	scanf("%s", &sc);

	if (((b1>=2) && (b1<=16)) && ((b2>=2) && (b2<=16)))//�������� ������ ����������
	{
		for(i=0;sc[i]!=0;i++)//���� �� ������� ������� ���������� �����
		{
			flag = 0;
			for(j=0;j<b1;j++)//�������� ����������� ������ � ������� ������� ���������� b1
			{
				if (sc[i]==simb[j]) 
				{
					flag=1;
					raz[i]=j;
				}//���� ����� �����������, �� it's all right
			}
			if ((!flag) && (sc[i]!='.'))//���� �� ����� � ��� �� �����, �� �������� �� ������
			{
				printf("bad input\n");
				getchar();
				return 0;
			}
		}
		if (i>13)//�������� �� 13 ��������
			{
				printf("bad input\n");
				getchar();
				return 0;
			}
	}
	else
	{
		printf("bad input\n");
		getchar();
		return 0;
	}
	//���� ������ ��� ������� �� ��������� � ������ �������
	//��������� � 10-�� ������� = �
	j=0;
	for(i=0;((sc[i]!='.')&&(sc[i]!=0));i++) j++;

	for(i=0;i<j;i++)
	{
		c = c + raz[j-1-i]*pow(b1,i);
	}

	//��������� � 10-� � b2
	i=0;
	while (c>=b2)
	{
		nc = c % b2;
		so[i] = simb[nc];
		i++;
		c = (c-nc)/b2;
	}
	nc = c;
	so[i] = simb[nc];
	for(j=0;j<=i;j++)
		printf("%c", so[i-j]);
	 
	printf("\n");
	getchar();
	return 0;          
}

// n = 234.2679   , nc= n%d , dr= n-nc , 
// *b2 , if 