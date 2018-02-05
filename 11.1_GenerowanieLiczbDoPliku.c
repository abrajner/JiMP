#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void GenerowanieTablicyZLiczbami(int wielkoscTablicy, unsigned tablica[wielkoscTablicy], FILE* plik)
{
	for(int i = 0; i<=wielkoscTablicy; i++)
  	{
		tablica[i] = rand()%1000;
		fprintf(plik, " %d ", tablica[i]);
  	}
}

int main(int argc, char **argv)
{
	int rozmiarTablicy = *argv[2];
	const char* nazwaPliku = argv[1];
	FILE * plik = fopen(nazwaPliku, "w");
	unsigned tablica[rozmiarTablicy];	

	if(argc < 3)
	{
		printf("Nie wpisales wszystkich argumentow\n");
		exit (-1);
	}

	srand(time(NULL));

	if (NULL == plik)
		return -1;
	else
		GenerowanieTablicyZLiczbami(rozmiarTablicy, tablica, plik);

	fclose(plik);
	return 0;
}
