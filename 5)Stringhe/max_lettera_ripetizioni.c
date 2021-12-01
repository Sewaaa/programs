/*Data una stringa stampare la lettera con più ripetizioni e il numero delle sue ripetizioni*/

#include <stdio.h>
#include <string.h>

#define max 50

void leggistringa(char a[]);
void conta_lettera(char a[],char *P1,int *P2);

int main()
{
	int n_max, *P2=&n_max;
	char a[max+1],l_max, *P1=&l_max;
	
	printf("Inserisci stringa: ");
	leggistringa(a);
	
	conta_lettera(a,P1,P2);
	
	printf("\n\nLa lettera con piu' ripetizioni e' \"%c\" con %d ripetizioni", l_max,n_max);
}

void leggistringa(char a[])
{
	fgets(a,max+1,stdin);
	if(a[strlen(a)-1]=='\n')
	{
		a[strlen(a)-1]='\0';
	}
	return;
}


void conta_lettera(char a[],char *P1,int *P2)
{
	char let,let2;
	int n,i,j;
	
	
	for(j=0;j<strlen(a);j++)
	{
		
		let=a[j];
		if(isalpha(let))                 //conta solo le lettere
		{
			if(isupper(let))			//se maiuscola
			{
				let2 = tolower(let);	//salva la sua minusc
			}
			else
			{
				let2 = toupper(let);   //salva la sua maiusc
			}
			n=0;
				
			for(i=0;i<strlen(a);i++) 	//inizio confronta con stringa
			{
				if(let==a[i]||let2==a[i])
				{
					n++;
				}
			}
			if(n>*P2)					//lettera con più ripetizioni trovata
			{
				*P2=n;					//uso puntatori
				*P1=a[j];				
			}
		}
	}
}	


