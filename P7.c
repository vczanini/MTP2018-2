/*P7.C*/
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

	for (j=0; j<i; j++)
	{
		pt[j].p1 = cos(j*2.0*M_PI/(i-1));
		pt[j].p2 = sin(j*2.0*M_PI/(i-1));
	}

	return pt;
}

void salvar (struct ponto *pt, int i)
{
	FILE *arq;
	arq = fopen("pontos.dat", "w");
	
	
	int j, k;
	for(j = 0; j < i; j++) 
	{
        for(k = 0; k < 20; k++) 
		{
            fprintf(arq, "%d\t%d\t\t", pt[j].p1, pt[j].p2);
        }    
        fprintf(arq, "\n");
    }
    
    fclose(arq);
}


void arq01 (struct ponto *pt, int i)
{
    FILE * arq;
    arq = fopen("pontos.dat", "wb");
    fwrite (pt, i, sizeof(struct ponto), arq);
    fclose (arq);
}

struct ponto *leia (unsigned int *pr)
{
    struct ponto *pt = (struct ponto *) malloc(sizeof(struct ponto));
    
    unsigned int i = 0;
    
    FILE *arq;
    arq = fopen("pontos.dat", "rb");
    
    while(1) 
	{
        fread(pt, 1, sizeof(struct ponto), arq);
        if(feof(arq)) 
			break;
        i++;
    }
    
    rewind(arq);
    
    pt = (struct ponto *) realloc(pt, i*sizeof(struct ponto));
    fread(pt, i, sizeof(struct ponto), arq);
    
    fclose(arq);
    
    *pr = i;
    
    return pt;
}

void mostra (struct ponto *pt, struct ponto *pm)
 {
    if(pt < pm)
	{
		printf("(%.3lf , %.3lf) \n", (*pt).p1, (*pt).p2);
		mostra (pt+1, pm);
	}
}

int main ()
{
	struct ponto *pt;
	int i, a;

	do
	    {
		system ("cls");
		printf("            MENU \n\n1) Gerar arquivo com pontos. \n2) Recuperar pontos de arquivo. \
			\n3) Sair do programa.\n\n");
		scanf("%d", &a);
		switch (a)
		{
		    case 1:
			printf ("\nDigite o numero de pontos que deseja encontrar: ");
			scanf ("%d", &i);
			getchar();
			pt = crie(i);

			salvar (pt, i);
			arq01(pt, i);

			printf ("\ngravado");
			getch();
			break;
		    case 2:
			pt = leia(&i);
			mostra(pt, pt+i);
			getch ();
			break;
		    default:
			if (a != 3)
			    printf("impossivel");
			getch();
			break;
		}
	    } while(a != 3);

	free(pt);
	return 0;
}
