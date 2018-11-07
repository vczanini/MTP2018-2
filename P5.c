/*P5.c*/
/*Vinicius de Carvalho Zanini*/
/*11811EBI013*/

#include <stdio.h>

typedef
	unsigned long long int
Bytes8;

typedef
	struct LCG { Bytes8 a, c, m, rand_max, atual;}
LCG;

void semente(LCG * r, Bytes8 seed) 
{
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) 
{
	r->atual = (r->a * r->atual + r->c) % r->m;
	return r->atual;
}

double lcg_rand_01(LCG * r) 
{
	return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r) 
{
	int i;
	for(i = 0; i < tam; i++)
		vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float soma(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1) 
		return (*inicio_vetor + soma(inicio_vetor + 1, fim_vetor));
	return 0;
}

float produto(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1) 
		return (*inicio_vetor * produto(inicio_vetor + 1, fim_vetor));
	return 1;	
}

int main()
{
	LCG random;
   	semente(&random, 123456);
	int a;
	float quantidade[50];
	gera_numeros(quantidade, 50, 0.5, 1.5, &random);
	while(a!=3)
	{
		printf("aperte:\n 1 para ter a somatoria entre 50 numeros aleatorios,\n 2 para ter o produto de 50 numeros aleatorios \n 3 para sair do programa:");
		scanf ("%d", &a);
		switch (a)
		{
			case 1:
				printf ("\nA soma eh %.6f \n\n", soma (&quantidade[0], &quantidade[49]));
				break;
			case 2:
				printf ("\nO produto eh %g \n\n", produto (&quantidade[0], &quantidade[49]));
				break;	
			default:
				if (a != 3)
					printf ("\nOpcao invalida! \n\n");
		}
    }
	return 0;
}

