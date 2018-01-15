#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TworzenieTablicyA (int n, int tablicaA[n])
{
	for(int i = 0; i<n; i++)
	{
		tablicaA[i] = rand()%30;
	}
}

void TworzenieTablicyB (int n, int tablicaA[n], int *tablicaB[n])
{
	for(int i = 0; i<n; i++)
	{
		tablicaB[i] = &tablicaA[i];
	}
}

void SortowanieTablicyB (int n, int *tablicaB[n])
{
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if (*tablicaB[i]<*tablicaB[j])
			{
				int *tmp = tablicaB[j];
				tablicaB[j] = tablicaB[i];
				tablicaB[i] = tmp;
			}
		}
	}
}

int main (void)
{
	int n = 0;
	printf("Podaj dlugosc tablicy do posortowania ");
	scanf("%d", &n);
	int tablicaA[n];
	int *tablicaB[n];
	srand(time(NULL));
	TworzenieTablicyA(n, tablicaA);
	TworzenieTablicyB(n, tablicaA, tablicaB);
	SortowanieTablicyB (n, tablicaB);

	for (int i = 0; i<n; i++)
	{
		printf(" %d ", tablicaA[i]);
	}
	
	printf("\n");

	for (int i = 0; i<n; i++)
	{
		printf(" %d ", *tablicaB[i]);
	}

	printf("\n");	
}
