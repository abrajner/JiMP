#include <stdio.h>

double SredniaWazona (int *poczatek, int *koniec)
{
	double suma=0.0, sredniaWazona=0.0;
	int i=0, sumaWag=0;
	while (poczatek+i != koniec)
	{
		suma+= *(poczatek+i)*i;
		sumaWag+=i;
		i++;
	}
	sredniaWazona = suma/sumaWag;
	return 	sredniaWazona;
}

int main (void)
{
	int tablica[10]={45,53,2,6,3,57,32,5,3345,23};
	double srednia=0;
	int *wskpoczatek = &tablica[0];
	int *wskkoniec = &tablica[10];
	srednia =SredniaWazona(wskpoczatek, wskkoniec);
	printf ("%lf\n", srednia);
	return 0;
}
