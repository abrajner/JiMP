#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void WyswietlanieZnaku(void* argument, const unsigned szerokoscLinii)
{
	char wyswietlanyZnak = *(char*)argument;
	if(isprint(wyswietlanyZnak) == 0)
	{
		printf("\n");
	}	
	else if(szerokoscLinii%2 == 1)
	{
		printf("%*c%c\n", ((szerokoscLinii-1)/2),' ', wyswietlanyZnak);
	}
	else if(szerokoscLinii%2 == 0)
		printf("%*c%c\n", (((szerokoscLinii)/2)-1),' ', wyswietlanyZnak);
}

void WyswietlanieNapisu(void* argument, const unsigned szerokoscLinii)
{
	char* wyswietlanyNapis = *(char**)argument;
	int dlugoscArgumentu = strlen(wyswietlanyNapis);

	if(szerokoscLinii<dlugoscArgumentu)	
		printf("%s\n", wyswietlanyNapis);
	else if((szerokoscLinii-dlugoscArgumentu)%2 == 1)
		printf("%*c%s\n", ((szerokoscLinii-dlugoscArgumentu-1)/2), ' ', wyswietlanyNapis);
	else
		printf("%*c%s\n", ((szerokoscLinii-dlugoscArgumentu)/2), ' ', wyswietlanyNapis);
}

void WyswietlanieLiczby(void* argument, const unsigned szerokoscLinii)
{
	int wyswietlanaLiczba = *(int*)argument;
	int dlugoscArgumentu = (int)log10(wyswietlanaLiczba);
	
	if(szerokoscLinii<dlugoscArgumentu)
		printf("%d\n", wyswietlanaLiczba);
	else if((szerokoscLinii-dlugoscArgumentu)%2 == 1)
		printf("%*c%d\n", ((szerokoscLinii-dlugoscArgumentu-1)/2), ' ', wyswietlanaLiczba);
	else
		printf("%*c%d\n", ((szerokoscLinii-dlugoscArgumentu)/2), ' ', wyswietlanaLiczba);
}

void WyswietlanieLiczbyZmiennoprzecinkowej(void* argument, const unsigned szerokoscLinii)
{
	double wyswietlanaLiczba = *(double*)argument;
	int dlugoscArgumentu = (int)log10(wyswietlanaLiczba);
	int miejscaPoPrzecinku = 2; 
	
	char* wyswietlanaLiczbaString = malloc(sizeof(char)*dlugoscArgumentu);
	snprintf(wyswietlanaLiczbaString, dlugoscArgumentu, "%f", wyswietlanaLiczba);
	
	for(int i = 1; i <= dlugoscArgumentu; i++)
	{
		if(wyswietlanaLiczbaString[i] == '.')
		{
			dlugoscArgumentu = i+3;
			if(wyswietlanaLiczbaString[i+1] == '0')
			{
				if(wyswietlanaLiczbaString[i+2] == '0')
				{
					miejscaPoPrzecinku = 0;
					dlugoscArgumentu = i+1;
				}
			}
			else
			{
				if(wyswietlanaLiczbaString[i+2] == '0')
				{
					miejscaPoPrzecinku = 1;
					dlugoscArgumentu = i+2;
				}
				break;					
			}
		}	
	}	

	if(szerokoscLinii<dlugoscArgumentu)
		printf("%.*f\n", miejscaPoPrzecinku, wyswietlanaLiczba);
	else if((szerokoscLinii-dlugoscArgumentu)%2 == 1)
		printf("%*c%.*f\n", ((szerokoscLinii-dlugoscArgumentu-1)/2-1), ' ', miejscaPoPrzecinku, wyswietlanaLiczba);
	else
		printf("%*c%.*f\n", ((szerokoscLinii-dlugoscArgumentu)/2-1), ' ', miejscaPoPrzecinku, wyswietlanaLiczba);
}

int WyswietlanieArgumentuNaSrodku(void* argument, const char* typDanych, const unsigned szerokoscLinii)
{
	if(argument == 0)
	{
		printf("\n");
		return 0;
	}
	else if(typDanych == "napis")
	{
		WyswietlanieNapisu(argument, szerokoscLinii);
	}
	else if(typDanych == "liczba")
	{
		WyswietlanieLiczby(argument, szerokoscLinii);
	}
	else if (typDanych == "znak")
	{
		WyswietlanieZnaku(argument, szerokoscLinii);
	}
	else if (typDanych == "liczba zmiennoprzecinkowa")
	{
		WyswietlanieLiczbyZmiennoprzecinkowej(argument, szerokoscLinii);
	}
}

int main(void)
{
	char znak = 'a';
	char* napis = "asdfghjhytrew";
	int liczba = 2345;
	double liczbaZP = 2344.5678;
	const unsigned dlugosc = 30;
	WyswietlanieArgumentuNaSrodku(&znak, "znak", dlugosc);
	WyswietlanieArgumentuNaSrodku(&napis, "napis", dlugosc);
	WyswietlanieArgumentuNaSrodku(&liczba, "liczba", dlugosc);
	WyswietlanieArgumentuNaSrodku(&liczbaZP, "liczba zmiennoprzecinkowa", dlugosc);
	return 0;
}
