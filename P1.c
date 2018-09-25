//P1.c
//vinicius de carvalho zanini
//11811EBI013


#include <stdio.h>

int main ()
{
	int ax = 0, x = 0;
	char bit [256];
	printf ("Digite o numero binario para ser  verificado: \n");
	gets (bit);
	for(bit[x];bit[x]!= '\0';x++)
	{
		if (ax == 0 && bit [x] == '0')
			ax = 0;
		else if (ax == 0 && bit [x] == '1')
			ax = 1;
		else if (ax == 1 && bit [x] == '1')
			ax = 0;
		else if (ax == 1 && bit [x] == '0')
			ax = 2;
		else if (ax == 2 && bit [x] == '0')
			ax = 1;
		else if (ax == 2 && bit [x] == '1')
			ax = 2;
	}

	printf ("Sequencia: %s \n", bit);
	if (ax == 0)
		printf ("Eh multiplo de 3");
	else
		printf ("Nao eh");

	return 0;
}
