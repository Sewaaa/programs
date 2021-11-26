#include <stdio.h>

int main()
{
	int i;
	
	for(i=0;i<=200;i++)
	{
		if(is_primo(i))
		{
			printf("%d\n",i);
		}
	}
}

is_primo(int i)
{
	int candidate;
					/*Controllo per 1 e 0*/
	if(i<2)
	{
		return 0;
	}
					/*Controllo se è 2 direttamente*/
	if(i==2)
	{
		return 1;
	}
					/*Controllo parità*/
	if(i%2==0)
	{
		return 0;
	}
	for(candidate=3;candidate*candidate<i;candidate++)
	{
		if(i%candidate==0)
		{
			return 0;
		}
	}
	return 1;
}
