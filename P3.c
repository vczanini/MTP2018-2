/*P3.c */
/* Vinicius de Carvalho Zanini */
/* 11811EBI013 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char numeroini[276], numerofi[276];
	int numero, a = 0, b = 0;
    printf("digite o numero: ");
	scanf("%s", numeroini);
	for (a=0; numeroini[a] != '\0'; a++)
	{
		if(numeroini[a]>= 48 && numeroini[a]<= 57)
		{
			numerofi[b] = numeroini[a];
			b++;
		}
	}
	numero = atoi(numerofi);
	printf("%d", numero);
	return 0;
}
