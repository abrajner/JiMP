#include <stdio.h>
#include <stdlib.h>

void WyswietlPosortowanaTablice(int rozmiar, int tablica[rozmiar])
{
	for(int i = 0; i<rozmiar; i++)
	{
		printf(" %d ", tablica[i]);
	}
}

void SortowanieTablicy(int rozmiar, int tablica[rozmiar])
{
	for(int i = 0; i < rozmiar; i++)
	{
		for(int j = 0; j < rozmiar; j++)
		{
			if (tablica[i] < tablica[j])
			{
				int tmp = tablica[j];
				tablica[j] = tablica[i];
				tablica[i] = tmp;
			}
		}
	}
}

int main (int argc, char** argv)
{
	const char* nazwaPlikuWejsciowego = argv[1];
	FILE* plikWejsciowy = fopen(nazwaPlikuWejsciowego, "r");

	int rozmiar = 100;
	int tablica[rozmiar];
	char liczba[1001];
	int element = 0, licznik = 1;
	
	if(plikWejsciowy == NULL)
	{
		printf("Podales zly plik\n");
		exit(-1);
	}

	while(fscanf(plikWejsciowy, "%s", liczba) != EOF)
	{
		tablica[element] = strtol(liczba, NULL, 10);
		element++;
		licznik++;
	}

	//tablica = realloc(tablica, sizeof(int)*licznik)
	SortowanieTablicy(licznik, tablica);

	if(argc == 2)
	{
		WyswietlPosortowanaTablice(licznik, tablica);
	}
	else if(argc == 3)
	{
		const char* nazwaPlikuWyjsciowego = argv[2];
		FILE* plikWyjsciowy = fopen(nazwaPlikuWyjsciowego, "w");
		for(int i = 0; i <= licznik; i++)
  		{
			fprintf(plikWyjsciowy, " %d ", tablica[i]);
  		}	
		fclose(plikWyjsciowy);
	}
	else
	{
		printf("Argumenty, ktore podales nie spelniaja wymagan \n");
		exit(-1);
	}

	fclose(plikWejsciowy);
	return 0;
}
