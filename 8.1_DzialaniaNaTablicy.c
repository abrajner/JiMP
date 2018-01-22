#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int WypelnienieTablicy(int rozmiarTablicy, int* tablica)
{
	for(int i = 0; i<rozmiarTablicy; i++)
	{
		if (scanf("%d", &tablica[i]) == EOF)
		{
			if (i == 0)
				exit(0);
			return rozmiarTablicy = i;
		}
	}
}

int LiczenieSumy(int rozmiarTablicy, int* tablica)
{
	int suma = 0;
	for(int i = 0; i<rozmiarTablicy; i++)
	{
		suma = suma + (tablica[i]);
	}
	return suma;
}

double LiczenieSredniej(int suma, int rozmiarTablicy)
{
	double srednia = (double)suma/rozmiarTablicy;
	return srednia;
}

void SortowanieTablicy (int rozmiarTablicy, int *tablica)
{
	for(int i = 0; i<rozmiarTablicy; i++)
	{
		for(int j = 0; j<rozmiarTablicy; j++)
		{
			if (tablica[i]<tablica[j])
			{
				int tmp = tablica[j];
				tablica[j] = tablica[i];
				tablica[i] = tmp;
			}
		}
	}
}

double LiczenieMediany(int rozmiarTablicy, int* tablica)
{
	float mediana = 0;
	int n = rozmiarTablicy/2;
	SortowanieTablicy(rozmiarTablicy, tablica);
	if (rozmiarTablicy%2 == 0)
	{
		mediana = ((double)tablica[n]+(double)tablica[n+1])/2;
	}
	else
	{
		mediana = tablica[n];
	}
	return mediana;
}

int LiczenieDominanty(int rozmiarTablicy, int* tablica)
{
	int tablicaWystapien[rozmiarTablicy], tablica2[rozmiarTablicy], k = 0;
	SortowanieTablicy(rozmiarTablicy, tablica);
	for(int i = 0; i<rozmiarTablicy; i++)
	{
		for(int j = 0; j<rozmiarTablicy; j++)
		{
			if(tablica[i]!=tablica2[j])
			{
				tablica2[i] = tablica[i];
				tablicaWystapien[i] = 1;
			}
			else if(tablica[i]==tablica2[j])
			{
				tablicaWystapien[j] += 1;
			}
		}
	}

	for(int i = 0; i<rozmiarTablicy; i++)
	{
		for(int j = 0; j<rozmiarTablicy; j++)
		{
			if(tablicaWystapien[i]<tablicaWystapien[j])
			k = j;
		}
	}
	
	return tablica2[k];
}

int SprawdzenieLiczbPoPrzecinku(double liczbaDoSprawdzenia)
{
	if ((int)liczbaDoSprawdzenia < liczbaDoSprawdzenia && (int)liczbaDoSprawdzenia > (liczbaDoSprawdzenia - 1))
	{
		return false;
	}
	else
		return true;
}

int main(void)
{
	int rozmiarTablicy, suma = 0, dominanta;
	double mediana, srednia = 1;
	int *tablica;
	printf("Podaj rozmiar tablicy ");
	scanf("%d", &rozmiarTablicy);
	tablica = malloc(sizeof(int)*rozmiarTablicy);

	if (NULL == tablica || rozmiarTablicy < 1)
	{
		printf("Nie mozna zaalokowac tablicy\n");
		return 1;
	}

	printf("Wpisz wartosci, po każdej nacisnij enter \n");
	rozmiarTablicy = WypelnienieTablicy(rozmiarTablicy, tablica);

	suma = LiczenieSumy(rozmiarTablicy, tablica);
	srednia = LiczenieSredniej(suma, rozmiarTablicy);
	mediana = LiczenieMediany(rozmiarTablicy, tablica);
	dominanta = LiczenieDominanty(rozmiarTablicy, tablica);

	printf("Suma %d %o %x\n", suma, suma, suma);
	printf("Dominanta %d %o %x\n", dominanta, dominanta, dominanta);
	if(SprawdzenieLiczbPoPrzecinku(srednia))
	{
		srednia = ((int)srednia);
		printf("Srednia %d %o %x\n", (int)srednia, (int)srednia, (int)srednia);
	}	
	else
		printf("Srednia %.1f\n", srednia);
	if(SprawdzenieLiczbPoPrzecinku(mediana))
	{
		mediana = ((int)mediana);
		printf("Mediana %d %o %x\n", (int)mediana, (int)mediana, (int)mediana);
	}
	else
		printf("Mediana %.1f\n", mediana);
	return 0;
}
