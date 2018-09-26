/*P1*/
/*vinicius de carvalho zanini*/
/*11811EBI013*/
#include<stdio.h>
int main()
{
	int seq=0, x=0;
	char bit[256];
	printf("digite o numero verificado: ");
	scanf("%s", bit);
	while(bit[x] != '\0')
	{
		if(seq== 0 && bit[x] == '0')
		seq = 0;
		else if(seq ==0 && bit[x] == '1')
		seq = 1;
		else if(seq == 1 && bit[x] == '1')
		seq = 0;
		else if(seq == 1 && bit[x] =='0')
		seq = 2;
		else if(seq == 2 && bit[x] == '0')
		seq = 1;
		else if(seq == 2 && bit[x] == '1')
		seq = 2;
		x++;
	}
	printf("temos como sequencia %s \n ", bit);
	if(seq==0)
	printf("multiplo de 3.");
	else
	printf("Nao multiplo de 3.");
	return 0;
}
