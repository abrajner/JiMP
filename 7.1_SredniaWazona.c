#include <stdio.h>

double SredniaWazona (const int *poczatek, const int *koniec)
{
	double suma=0.0;
	int i=0, sumaWag=0;
	while (poczatek+i != koniec)
	{
		suma+= *(poczatek+i)*i;
		sumaWag+=i;
		i++;
	}
	double sredniaWazona = suma/sumaWag;
	return 	sredniaWazona;
}

int main (void)
{
	const int tablica[]={45,53,2,6,3,57,32,5,3345,23};
	const int *wskpoczatek = &tablica[0];
	const int *wskkoniec = &tablica[10];

	double srednia = SredniaWazona(wskpoczatek, wskkoniec);
	printf ("%lf\n", srednia);
	return 0;
}
