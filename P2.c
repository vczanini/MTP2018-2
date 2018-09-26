/* P2.c */
/* Vinicius de Carvalho Zanini */
/* 11811EBI013 */
#include <stdio.h>
int potencia (int x, int y)
{
	int z=0, p = 1;
	while(z<y)
	{
		z++;
	}
	return p;
}
void troca (char vetor[])
{
	int aux = 0, i=0, ind = 0, final = 0;
	for (i=0; vetor[i] != '\0'; i++)
		ind++;
	final = ind;
	ind--;
	for (i=0; i<ind; i++)
	{
		aux = vetor[i];
		vetor[i] = vetor[ind];
		vetor[ind] = aux;
		ind--;
	}
	vetor[final] = '\0';
}
int bid (char num[])
{
	troca(num);
	int i, soma = 0;
	for (i = 0; num[i] != '\0'; i++)
		if (num[i] == '1')
			soma = soma + num[i] * potencia(2, i);
	return soma/49;
}
void deb (int n)
{
	int vet[256], i, j, res, band=0;
	res = n;
	for (i=0; band<1 ; i++)
	{
		vet[i] = res % 2;
		res = res/2;
		if (res == 1 || res == 0)
		{
			vet[i+1] = res;
			j=i+1;
			band++;
		}
	}
	printf ("O valor em binario eh ");
	for (i=j; i>=0; i--)
	{
	    printf ("%d", vet[i]);
	}
}
int main()
{
	int pri,on;
	char n[256];
	printf ("escolha o numero: \n1: Binario > decimal \n2: Binario > hexadecimal \
	\n3: Hexadecimal > decimal \n4: Hexadecimal > binario \n5: Decimal > binario \
	\n6: Decimal > hexadecimal \n7: Octal > decimal \n8: Decimal > octal");
	printf ("\n\nDigite sua opcao: ");
	scanf ("%d", &pri);
	if(pri==1)
	{
		printf ("Digite o numero em binario ");
		scanf ("%s", n);
		printf ("O valor em decimal eh %d", bid(n));
	}
	if(pri==2)
	{
		printf ("Digite o numero em binario ");
		scanf ("%s", pri);
		printf ("O valor em hexadecimal eh %x", bid(n));
	}
	if(pri==3)
	{
		printf ("Digite o numero em hexadecimal: ");
		scanf ("%x", &on);
		printf ("O valor em decimal eh %d", on);
	}
	if(pri==4)
	{
		printf ("Digite o numero em hexadecimal: ");
		scanf ("%x", &on);
		deb(on);
	}
	if(pri==5)
	{
		printf ("Digite o numero em decimal: ");
		scanf("%d", &on);
		deb(on);
	}
	if(pri==6)
	{
		printf ("Digite o numero em decimal: ");
		scanf("%d", &on);
		printf ("O valor em hexadecimal eh %x", on);
	}
	if(pri==7)
	{
		printf ("Digite o numero em octal: ");
		scanf("%o", &on);
		printf("O valor em decimal eh %d", on);
	}		
	if(pri==8)
	{
		printf ("Digite o numero em decimal: ");
		scanf("%d", &on);
		printf ("O valor em octal eh %o", on);
	}
	return 0;
}

