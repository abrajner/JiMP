#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void LosujTablice (int rozmiar, int tablica[rozmiar])
{
	for (int i=0; i<rozmiar; i++)
	{
		tablica[i]=rand()%100;
	}
}

void WyswietlTablice (int rozmiar, int tablica[rozmiar])
{
	for (int i=0; i<rozmiar; i++)
	{
		printf(" %d ", tablica[i]);
	}
	printf("\n");
}

int LiczenieSredniej (int rozmiar, int tablica[rozmiar])
{
	int suma=0;
	for (int i=0; i<rozmiar; i++)
	{
		suma+=tablica[i];
	}
	return suma/10;
}

void SortowanieTablicy (int rozmiar, int tablica[rozmiar])
{
	for (int i=0; i<rozmiar; i++)
	{
		for (int j=0; j<rozmiar; j++)
		{
			if (tablica[i]<tablica[j])
			{
				int temp=tablica[i];
				tablica[i]=tablica[j];
				tablica[j]=temp;
			}
		}
	}
}

int Mediana (int rozmiar, int tablica[rozmiar])
{
	SortowanieTablicy (rozmiar, tablica);
	return (tablica[4]+tablica[5])/2;
}

int MinimalnaWartosc (int rozmiar, int tablica[rozmiar])
{
	SortowanieTablicy (rozmiar, tablica);
	return tablica [0];
}

int MaksymalnaWartosc (int rozmiar, int tablica[rozmiar])
{
	SortowanieTablicy (rozmiar, tablica);
	return tablica [rozmiar-1];
}

void Sprawdzenie (int rozmiar, int tablica[rozmiar])
{
	int temp=0;
	for (int i=0; i<rozmiar; i++)
	{
		temp+=(tablica[i]>0);
	}
	if (temp==0)
	{
		printf("Nie wylosowales tablicy\n");
	}
}

int main (void)
{
	srand(time(NULL));
	int wybor, tablica[10]={0,0,0,0,0,0,0,0,0,0}, srednia, wartoscMaksymalna, wartoscMinimalna, mediana;
	int rozmiar = 10;
	while (wybor!= 6)
	{
		printf("Co chcesz zrobic? \n1-Wylosowac tablice \n2-Wyswietlic tablice \n3-Obliczyc srednia wartosc elementow tablicy\n4-Obliczyc mediane\n5-Obliczyc wartosc minimalna i maksymalna\n6-Zakonczyc dzialanie programu\n");
		scanf ("%d", &wybor);
		switch (wybor)
		{
			case 1:
				LosujTablice(rozmiar, tablica);
				break;
			case 2:
				Sprawdzenie(rozmiar,tablica);
				WyswietlTablice(rozmiar,tablica);
				break;
			case 3:
				Sprawdzenie(rozmiar,tablica);
				srednia=LiczenieSredniej(rozmiar,tablica);
				printf("%d\n", srednia);
				break;
			case 4:
				Sprawdzenie(rozmiar,tablica);
				mediana=Mediana(rozmiar,tablica);
				printf("%d\n", mediana);
				break;
			case 5:
				Sprawdzenie(rozmiar,tablica);
				wartoscMinimalna=MinimalnaWartosc (rozmiar,tablica);
				wartoscMaksymalna=MaksymalnaWartosc (rozmiar,tablica);
				printf("maksimum = %d, minimum = %d\n", wartoscMaksymalna, wartoscMinimalna);
				break;				
		}	
	}
	return 0;
}
