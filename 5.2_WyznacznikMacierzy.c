#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerowanieMacierzy (int wiersze, int kolumny, int macierz[kolumny][wiersze])
{
	for (int i=0; i<kolumny; i++)
	{
		for (int j=0;j<wiersze; j++)
		{
			macierz[i][j]=rand()%6;
 			
		}
	}
}

void WypisanieMacierzy (int wiersze, int kolumny, int macierz[kolumny][wiersze])
{
	for (int k=0; k<kolumny; k++)
	{
		for (int l=0;l<wiersze; l++)
		{
			printf(" %d ", macierz[k][l]);
		}
		printf("\n");
	}
} 

int LiczenieWyznacznika(int wiersze, int kolumny, int macierz [kolumny][wiersze])
{
	return macierz[0][0]*macierz[1][1]*macierz[2][2]+macierz[1][0]*macierz[2][1]*macierz[0][2]+macierz[2][0]*macierz[0][1]*macierz[1][2]-macierz[0][2]*macierz[1][1]*macierz[2][0]-macierz[1][2]*macierz[2][1]*macierz[0][0]-macierz[2][2]*macierz[0][1]*macierz[1][0];
}

int main(void)
{	
	srand(time(NULL));
	int wiersze, kolumny, macierz[kolumny][wiersze];
	printf("podaj liczbe wierszy macierzy \n");
	scanf ("%d", &wiersze);
	printf("podaj liczbe kolumn macierzy \n");
	scanf ("%d", &kolumny);
	GenerowanieMacierzy(wiersze, kolumny, macierz);
	WypisanieMacierzy(wiersze, kolumny, macierz);
	if (kolumny==3&wiersze==3)
	{
		int wyznacznik = LiczenieWyznacznika(wiersze, kolumny, macierz);	
		printf("wyznacznik = %d\n", wyznacznik);
	}
	else
		printf("nie mozna obliczyc wyznacznika\n");
	return 0;
}
