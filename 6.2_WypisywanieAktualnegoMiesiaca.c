#include <stdio.h>
#include <time.h>

int IloscDniWMiesiacu(int nrMsc, int rok)
{
	if (nrMsc==1||nrMsc==3||nrMsc==5||nrMsc==7||nrMsc==8||nrMsc==10||nrMsc==12)
		return 31;
	else if (nrMsc==2)
	{
		if (rok%4==0 && (rok%100!=0 && rok%400==0))
			return 29;
		else
			return 28;
	}
	else 
		return 30;
	
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
	for (int i=1; i<IloscDniWMiesiacu(nrMsc, rok)+1; i++)
	{
		printf("  %2d  ", i);
		if (i%7==0)
			printf("\n");
	}
	printf("\n");
}

int main (void)
{
	int rok = AktualnyRok();
	int miesiac = AktualnyMiesiac();
	WypisanieDniMiesiaca(miesiac, rok);
	return 0;
}
