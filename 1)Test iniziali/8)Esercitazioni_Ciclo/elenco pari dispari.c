#include <stdio.h>

int main()
{
	int i=1;
	char pari[4]="pari" , dispari[7]="dispari";
	while(i<=1000)
	{
		if((i%2)==0)
		{
			printf("\n%d %s\n", i,pari);	
		}
		else
		{
			printf("\n%d %s\n", i,dispari);	
		}
		i++;	
	}
}
