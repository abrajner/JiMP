#include <stdio.h>
#include <time.h>

int IloscDniWMiesiacu(int nrMsc, int rok)
{
	if (nrMsc==1||nrMsc==3||nrMsc==5||nrMsc==7||nrMsc==8||nrMsc==10||nrMsc==12)
		return 0;
	else if (nrMsc==2)
	{
		if (rok%4==0 && (rok%100!=0 && rok%400==0))
			return 1;
		else
			return 2;
	}
	
}

int AktualnyMiesiac()
{
	time_t czas;
	time(&czas);
	int miesiac = localtime(&czas)->tm_mon;
	int numerMiesiaca=miesiac+1;
	printf ("mamy miesiac %d\n", numerMiesiaca);
	return numerMiesiaca;
}

int AktualnyRok()
{
	time_t czas;
	time(&czas);
	int rok = localtime(&czas)->tm_year;
	printf ("%d\n", rok+1900);
	return rok+1900;
}

void WypisanieDniMiesiaca(int nrMsc, int rok)
{
	if (IloscDniWMiesiacu(nrMsc, rok)==0)
	{
		for (int i=1; i<32; i++)
		{
			printf("  %2d  ", i);
			if (i%7==0)
				printf("\n");
		}
		printf("\n");
	}
	else if (IloscDniWMiesiacu(nrMsc, rok)==2)
	{
		for (int i=1; i<29; i++)
		{
			printf("  %2d  ", i);
			if (i%7==0)
				printf("\n");
		}
		printf("\n");
	}
	else if (IloscDniWMiesiacu(nrMsc, rok)==1)
	{
		for (int i=1; i<30; i++)
		{
			printf("  %2d  ", i);
			if (i%7==0)
				printf("\n");
		}
		printf("\n");
	}		
	else
	{
		for (int i=1; i<31; i++)
		{
			printf("  %2d  ", i);
			if (i%7==0)
				printf("\n");
		}
		printf("\n");
	}
}

int main (void)
{
	int rok = AktualnyRok();
	int miesiac = AktualnyMiesiac();
	WypisanieDniMiesiaca(miesiac, rok);
}
