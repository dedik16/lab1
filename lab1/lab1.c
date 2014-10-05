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

	if (((b1>=2) && (b1<=16)) && ((b2>=2) && (b2<=16)))//проверка систем исчеслени€
	{
		for(i=0;sc[i]!=0;i++)//цикл по каждому символу введенного числа
		{
			flag = 0;
			for(j=0;j<b1;j++)//проводим сравнивание только с цифрами системы исчислени€ b1
			{
				if (sc[i]==simb[j]) 
				{
					flag=1;
					raz[i]=j;
				}//если нашли соответсвие, то it's all right
			}
			if ((!flag) && (sc[i]!='.'))//если не нашли и это не точка, то проверку не прошли
			{
				printf("bad input\n");
				getchar();
				return 0;
			}
		}
		if (i>13)//проверка на 13 символов
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
	//≈сли прошли все услови€ то переводим в другую систему
	//ѕереводим в 10-ую систему = с
	j=0;
	for(i=0;((sc[i]!='.')&&(sc[i]!=0));i++) j++;

	for(i=0;i<j;i++)
	{
		c = c + raz[j-1-i]*pow(b1,i);
	}

	//переводим и 10-й в b2
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