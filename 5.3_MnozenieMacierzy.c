#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerowanieMacierzy (int macierz[2][2])
{
	for (int i=0; i<2; i++)
	{
		for (int j=0;j<2; j++)
		{
			macierz[i][j]=rand()%200 -100;
 			
		}
	}
}

void WypisanieMacierzy (int macierz[2][2])
{
	for (int k=0; k<2; k++)
	{
		for (int l=0;l<2; l++)
		{
			printf(" %d ", macierz[k][l]);
		}
	printf("\n");
	}
	printf("\n");
} 

int ZamianaNaTrojwymiarowa (int macierz[2][2][2], int macierz1[2][2], int macierz2[2][2])
{
	for (int j=0; j<2; j++)
	{
		for (int k=0; k<2; k++)
		{
			macierz[0][j][k]=macierz1[j][k];
		}
	}
	for (int j=0; j<2; j++)
	{
		for (int k=0; k<2; k++)
		{
			macierz[1][j][k]=macierz2[j][k];
		}
	}
	return macierz [2][2][2];		
}


int TablicaTrojwymiarowaNaDwieDwuwymiarowe (int macierz [2][2][2], int macierz1[2][2], int macierz2[2][2])
{
	for (int j=0; j<2; j++)
	{
		for (int k=0; k<2; k++)
		{
			macierz1[j][k]=macierz[0][j][k];
		}
	}
	for (int j=0; j<2; j++)
	{
		for (int k=0; k<2; k++)
		{
			macierz2[j][k]=macierz[1][j][k];
		}
	}
}

void MnozenieDwochMacierzy (int macierz[2][2][2])
{
	int macierz1[2][2], macierz2[2][2], macierzPomnozona[2][2];
	TablicaTrojwymiarowaNaDwieDwuwymiarowe (macierz, macierz1, macierz2);
	macierzPomnozona[0][0]=macierz1[0][0]*macierz2[0][0]+macierz1[0][1]*macierz2[1][0];
	macierzPomnozona[0][1]=macierz1[0][0]*macierz2[0][1]+macierz1[0][1]*macierz2[1][1];
	macierzPomnozona[1][0]=macierz1[1][0]*macierz2[0][0]+macierz1[1][1]*macierz2[1][0];
	macierzPomnozona[1][1]=macierz1[1][0]*macierz2[0][1]+macierz1[1][1]*macierz2[1][1];
	WypisanieMacierzy(macierzPomnozona);
	
}

int main (void)
{
	int macierz1[2][2], macierz2[2][2], macierz[2][2][2], macierzPomnozona[2][2];
	srand(time(NULL));
	GenerowanieMacierzy (macierz1);
	GenerowanieMacierzy (macierz2);
	WypisanieMacierzy (macierz1);
	WypisanieMacierzy (macierz2);
	ZamianaNaTrojwymiarowa(macierz, macierz1, macierz2);
	MnozenieDwochMacierzy(macierz);
	return 0;
}
