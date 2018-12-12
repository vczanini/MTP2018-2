/*P6.c*/
/*Vinicius de Carvalho Zanini*/
/*11811EBI013*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto
{
	double p1;
	double p2;
};

struct ponto *crie (int i)
{
	struct ponto *pt = (struct ponto*) malloc(i*sizeof(struct ponto));
	int j;
	printf ("\nvoce criou os pontos: ");
	for (j=0; j<i; j++)
	{
		(*pt).p1 = cos(j*2.0*M_PI/(i-1));
		(*pt).p2 = sin(j*2.0*M_PI/(i-1));
		printf ("(%.3lf, %.3lf) \n", (*pt).p1, (*pt).p2);
	}
	return pt;
}

int main ()
{
	struct ponto *pt;
	int i;
	printf ("quer criar quantos pontos?: ");
	scanf ("%d", &i);
	getchar();
	pt = crie(i);
	free(pt);
	return 0;
}
