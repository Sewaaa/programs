#include <stdio.h>
#include <stdLib.h>
void date(int ann,int mes,int giorn)
{                                                                  /*Inserimento dati e controllo dei vari casi*/
  if(ann>0 && ann<3000)
  {
  	if(mes>0 && mes<13)
  	{
  	  if(giorn>0 && giorn<32)
  	  {
	    if(mes==2)
	    {
	      if(ann%4==0)               /*controllo anno bisestile*/
	      {
	        if(giorn>0 && giorn<30)
	        {
	      	  printf("\nLA DATA INSERITA E'CORRETTA\n");
		    }
		  }
		  else
		  {
		  	if(giorn>0 && giorn<29)
	        {
	      	  printf("\nLA DATA INSERITA E'CORRETTA\n");
		    }
		    else
		    {
		      printf("\nLA DATA INSERITA E'ERRATA\n");
			}
		  }
		}
		else          /*mesi con 30 giorni*/
		{
		  if(mes==4 || mes==6 || mes==9 || mes==11)
		  {
		  	if(giorn>0 && giorn<31)
		  	{
		  	  printf("\nLA DATA INSERITA E'CORRETTA\n");
			}
			else
			{
			  printf("\nLA DATA INSERITA NON E'CORRETTA\n");
			}
		  }
		  else
		  {
		  	if(giorn>0  &&  giorn<32)
		  	{
		  	  printf("\nLA DATA INSERITA E'CORRETTA\n");
			}
			else
			{
			  printf("\nLA DATA INSERITA NON E'CORRETTA\n");
			}
		  }
		}
	  }
	  else
	  {
	  	printf("\nLA DATA INSERITA E'ERRATA\n");
	  }
	}
	else
	{
	  printf("\nLA DATA INSERITA E'ERRATA\n");
	}
  }
  else
  {
  	printf("\nLA DATA INSERITA E'ERRATA\n");
  }
    return ;
}
