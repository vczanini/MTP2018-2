/*P4.C */
/* Vinicius de Carvalho Zanini */
/* 11811EBI013 */

#include <stdio.h>

int New_Function(int m, int n)
{
	if(m==0) 
		return n+1;
	else if(m>0 && n==0) 
		New_Function(m-1,1);
	else if(m>0 && n>0) 
		New_Function(m-1, New_Function(m, n-1));
}

int main ()
{
	int a, b;
	printf("digite o valor m:");
	scanf("%d", &a);
	printf("digite o valor n:");
	scanf("%d", &b);
        printf(": \nm = %d, n = %d: %d", a, b, New_Function(a,b));
	return 0;
}

