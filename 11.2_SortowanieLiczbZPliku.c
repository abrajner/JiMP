#include <stdio.h>
#include <stdlib.h>

void WyswietlPosortowanaTablice(int rozmiar, int iloscWystapienLiczby[rozmiar])
{
	for(int i = 0; i < rozmiar; i++)
	{
		if (iloscWystapienLiczby[i] != 0)
			for(int j = 1; j <= iloscWystapienLiczby[i]; j++)
				printf(" %d ", i);
	}
}

void SortowanieTablicy(int element, int iloscWystapienLiczby[1001])
{
	for(int i = 0; i < 1002; i++)
	{
		if(element == i)
			iloscWystapienLiczby[i] += 1; 
	}
}

int main (int argc, char** argv)
{
	const char* nazwaPlikuWejsciowego = argv[1];
	FILE* plikWejsciowy = fopen(nazwaPlikuWejsciowego, "r");
	int iloscWystapienLiczby[1001] = {0};
	int rozmiar = 10;
	int* tablica = malloc(sizeof(int)*rozmiar);
	char liczba[4];
	int element = 0, licznik = 1;
	
	if(plikWejsciowy == NULL)
	{
		printf("Podales zly plik\n");
		exit(-1);
	}

	while(fscanf(plikWejsciowy, "%s", liczba) != EOF)
	{
		tablica[element] = strtol(liczba, NULL, 10);
		SortowanieTablicy(tablica[element], iloscWystapienLiczby);
		element++;
		licznik++;
		tablica = realloc(tablica, sizeof(int)*licznik);
	}

	if(argc == 2)
	{
		WyswietlPosortowanaTablice(1001, iloscWystapienLiczby);
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
