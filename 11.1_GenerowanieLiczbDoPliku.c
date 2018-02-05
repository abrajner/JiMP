#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void GenerowanieTablicyZLiczbami(int wielkoscTablicy, FILE* plik)
{
	for(int i = 0; i < wielkoscTablicy; i++)
  	{
		fprintf(plik, " %d ", rand()%1000);
  	}
}

int main(int argc, char **argv)
{	
	srand(time(NULL));
	FILE * plik = NULL;
	int rozmiarTablicy = 0;
	const char* nazwaPliku = NULL;

	if(argc < 3)
	{
		printf("Nie wpisales wszystkich argumentow\n");
		return -1;
	}
	else 
	{
		rozmiarTablicy = *argv[2];
		nazwaPliku = argv[1];
		plik = fopen(nazwaPliku, "w");
	}
	
	if(rozmiarTablicy < 0)
	{
		printf("Rozmiar tablicy nie moze byc mniejszy od 0!\n");
		return -1;
	}
	else if (NULL == plik)
		return -1;
	else
		GenerowanieTablicyZLiczbami(rozmiarTablicy, plik);

	fclose(plik);
	return 0;
}
