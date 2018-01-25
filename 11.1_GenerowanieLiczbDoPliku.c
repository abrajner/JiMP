#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void GenerowanieTablicyZLiczbami(int wielkoscTablicy, char tablica[wielkoscTablicy])
{
	for(int i = 0; i<=wielkoscTablicy; i++)
  	{
    		tablica[i] = rand()%1000;
  	}
}

int main(int argc, char **argv)
{
	int rozmiarTablicy = *argv[2];
	const char* nazwaPliku = argv[1];
	FILE * plik = fopen(nazwaPliku, "w");

	if(argc < 3)
	{
		printf("Nie wpisales wszystkich argumentow\n");
		exit (-1);
	}

	srand(time(NULL));
	char tablica[rozmiarTablicy];
	GenerowanieTablicyZLiczbami(rozmiarTablicy, tablica);

	fprintf(plik, "%s", tablica);
	fclose(plik);
	return 0;
}
