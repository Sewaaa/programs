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
	
	if(i<2)
	{
		return 0;
	}
	
	for(candidate=2;candidate*candidate<i;candidate++)
	{
		if(i%candidate==0)
		{
			return 0;
		}
	}
	return 1;
}
