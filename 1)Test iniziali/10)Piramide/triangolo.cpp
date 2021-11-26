#include<stdio.h>

void triangolo(int n);

int main(void)
{
	int lato;
	triangolo(lato);
}

void triangolo(int n)
{
	printf("inserisci il numero\n");
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<(n-i);j++)
		{
			printf(" ");
		}
		for(k=0;k<(2*i-1);k++)
		{
			printf("*");
		}
	printf("\n");
	}	
}
