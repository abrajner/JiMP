#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void GenerowanieMacierzy (int kolumny, int wiersze, int macierz[wiersze][kolumny])
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0;j < kolumny; j++)
		{
			macierz[i][j] = rand()%100;
		}
	}
}

void WypisanieMacierzy (int kolumny, int wiersze, int macierz[wiersze][kolumny])
{
	for (int k = 0; k < wiersze; k++)
	{
		for (int l = 0;l < kolumny; l++)
		{
			printf("%4d", macierz[k][l]);
		}
		printf("\n");
	}
} 

int WypisanieMenuPierwszego()
{
	int pierwszyWybor = 0;
	printf("Jakie dzialanie chcesz wykonac? (wybierz cyfre)\n"
		"1. Dodawanie macierzy\n"
		"2. Odejmowanie macierzy\n"
		"3. Mnozenie dwoch macierzy\n"
		"4. Mnozenie macierzy przez liczbe\n"
		"5. Wyznacznik macierzy do 3x3\n"
		"6. Macierz transponowana\n"
		"7. Wyjdz z programu\n");
	
	scanf("%d", &pierwszyWybor);
	return pierwszyWybor;
}

int WypisanieMenuDrugiego()
{
	int drugiWybor = 0;
	printf("\nChcesz sam wypelnic macierz czy wylosowac liczby?\n"
		"1. Sam wypelnic liczbami\n"
		"2. wylosowac wartosci\n");
	
	scanf("%d", &drugiWybor);
	return drugiWybor;
}

void PobieranieRozmiaruMacierzy(int* kolumny, int* wiersze)
{
	printf("Podaj ilosc wierszy macierzy ");
	scanf("%d", wiersze);
	printf("Podaj ilosc kolumn macierzy ");
	scanf("%d", kolumny);
}

void WpisywanieMacierzyPrzezUzytkownika(int kolumny, int wiersze, int macierz[wiersze][kolumny])
{
	for(int i = 0; i < wiersze; i++)
	{
		for(int j = 0; j < kolumny; j++)
		{
			printf(" a%d%d ", i+1, j+1);
		}
		printf("\n");
	}
	printf("Wpisz po kolei wartosci w macierzy (a11, a12, ..., a1n, a21, a22, ..., a2n, ..., an1, an2, ann) po kazdej nacisnij enter\n\n");
	for(int i = 0; i < wiersze; i++)
	{
		for(int j = 0; j < kolumny; j++)
		{
			scanf("%d", &macierz[i][j]);
		}
	}
	printf("Oto twoja macierz: \n\n");
	WypisanieMacierzy(kolumny, wiersze, macierz);
}

void OpcjeDlaDwochMacierzy(int drugiWybor, int kolumnyPierwszej, int wierszePierwszej, int kolumnyDrugiej, int wierszeDrugiej, int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], int macierzDruga[wierszeDrugiej][kolumnyDrugiej])
{
	switch(drugiWybor)
	{
		case 1:
			printf("Wpisz wartosci pierwszej macierzy \n");
			WpisywanieMacierzyPrzezUzytkownika(kolumnyPierwszej, wierszePierwszej, macierzPierwsza);
			printf("Wpisz wartosci drugiej macierzy \n");
			WpisywanieMacierzyPrzezUzytkownika(kolumnyDrugiej, wierszeDrugiej, macierzDruga);
			break;
		case 2:
			printf("Macierz pierwsza: \n\n");
			GenerowanieMacierzy(kolumnyPierwszej, wierszePierwszej, macierzPierwsza);
			WypisanieMacierzy(kolumnyPierwszej, wierszePierwszej, macierzPierwsza);
			printf("\nMacierz druga: \n\n");
			GenerowanieMacierzy(kolumnyDrugiej, wierszeDrugiej, macierzDruga);
			WypisanieMacierzy(kolumnyDrugiej, wierszeDrugiej, macierzDruga);
			break;
		default:
			printf("Nie ma takiego wyboru!\n");
			break;
	}
}

void OpcjeDlaJednejMacierzy(int drugiWybor, int kolumny, int wiersze, int macierz[wiersze][kolumny])
{
	switch(drugiWybor)
	{
		case 1:
			printf("Wpisz wartosci pierwszej macierzy \n");
			WpisywanieMacierzyPrzezUzytkownika(kolumny, wiersze, macierz);
			break;
		case 2:
			printf("Macierz pierwsza: \n\n");
			GenerowanieMacierzy(kolumny, wiersze, macierz);
			WypisanieMacierzy(kolumny, wiersze, macierz);
			break;
		default:
			printf("Nie ma takiego wyboru!\n");
			break;
	}
}

int DodawanieMacierzy(int kolumnyPierwszej, int wierszePierwszej, int kolumnyDrugiej, int wierszeDrugiej, int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], int macierzDruga[wierszeDrugiej][kolumnyDrugiej])
{
	printf("Suma macierzy pierwszej i drugiej jest rowna:\n");

	if(kolumnyPierwszej == kolumnyDrugiej && wierszePierwszej == wierszeDrugiej)
	{
		int macierzPoDodaniu[wierszePierwszej][kolumnyPierwszej];
		for(int i = 0; i < wierszePierwszej; i++)
		{
			for(int j = 0; j < kolumnyPierwszej; j++)
			{
				macierzPoDodaniu[i][j] = macierzPierwsza[i][j] + macierzDruga[i][j];
			}
		}	
		WypisanieMacierzy(kolumnyPierwszej, wierszePierwszej, macierzPoDodaniu);
	}
	else
	{
		printf("Nie da sie dodac macierzy o innych wymiarach\n\n");
		return -1;
	}
}

int OdejmowanieMacierzy(int kolumnyPierwszej, int wierszePierwszej, int kolumnyDrugiej, int wierszeDrugiej, int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], int macierzDruga[wierszeDrugiej][kolumnyDrugiej])
{
	printf("Roznica macierzy pierwszej i drugie jest rowna:\n");

	if(kolumnyPierwszej == kolumnyDrugiej && wierszePierwszej == wierszeDrugiej)
	{
		int macierzPoOdjeciu[wierszePierwszej][kolumnyPierwszej];
		for(int i = 0; i < wierszePierwszej; i++)
		{
			for(int j = 0; j < kolumnyPierwszej; j++)
			{
				macierzPoOdjeciu[i][j] = macierzPierwsza[i][j] - macierzDruga[i][j];
			}
		}
		WypisanieMacierzy(kolumnyPierwszej, wierszePierwszej, macierzPoOdjeciu);
	}
	else
	{
		printf("Nie da sie dodac macierzy o innych wymiarach\n\n");
		return -1;
	}
}

int WyznacznikMacierzy(int kolumny, int wiersze, int macierz[wiersze][kolumny])
{
	int wyznacznik;
	if(kolumny == wiersze)
	{
		if(kolumny == 2)
		{
			wyznacznik = macierz[0][1]*macierz[1][0] - macierz[0][0]*macierz[1][1];
		}
		else if(kolumny == 3)
		{
			wyznacznik = macierz[0][0]*macierz[1][1]*macierz[2][2]+macierz[1][0]*macierz[2][1]*macierz[0][2]+macierz[2][0]*macierz[0][1]*macierz[1][2]-macierz[0][2]*macierz[1][1]*macierz[2][0]-macierz[1][2]*macierz[2][1]*macierz[0][0]-macierz[2][2]*macierz[0][1]*macierz[1][0];
		}
		else
			printf("Nie mozna obliczyc\n\n");
	}	
	else
		printf("Nie mozna obliczyc\n\n");
	printf("Wyznacznik jest rowny %d\n", wyznacznik);
}

int MacierzTransponowana(int kolumny, int wiersze, int macierz[wiersze][kolumny])
{
	printf("\nMacierz transponowana: \n\n");
	int macierzTransponowana[kolumny][wiersze];
	for(int i = 0; i < kolumny; i++)
	{
		for(int j = 0; j < wiersze; j++)
		{
			if (j == i)
				macierzTransponowana[i][j] = macierz[i][j];
			else
				macierzTransponowana[i][j] = macierz[j][i];
		}
	}

	WypisanieMacierzy(wiersze, kolumny, macierzTransponowana);
}

int MnozenieDwochMacierzy(int kolumnyPierwszej, int wierszePierwszej, int kolumnyDrugiej, int wierszeDrugiej, int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], int macierzDruga[wierszeDrugiej][kolumnyDrugiej])
{
	printf("\nIloczyn macierzy pierwszej i drugiej jest rowny: \n\n");
	int macierzPoMnozeniu[wierszePierwszej][kolumnyDrugiej];
	int iloczyn = 0;
	if(kolumnyPierwszej == wierszeDrugiej)
	{
		for(int i = 0; i < wierszePierwszej; i++)
		{
			for(int j = 0; j < kolumnyDrugiej; j++)
			{
				iloczyn = 0;
				for(int k = 0; k < kolumnyPierwszej; k++)
					iloczyn += macierzPierwsza[i][k]*macierzDruga[k][j];
				macierzPoMnozeniu[i][j] = iloczyn;
			}
		}
		WypisanieMacierzy(kolumnyDrugiej, wierszePierwszej, macierzPoMnozeniu);
	}
	else 
	{
		printf("Nie da sie pomnozyc tych macierzy. Liczba kolumn pierwszej musi byc rowna liczbie wierszy drugiej\n");
		return -1;
	}
}

int MnozenieMacierzyPrzezLiczbe(int kolumny, int wiersze, int macierz[wiersze][kolumny])
{
	int macierzPoMnozeniu[wiersze][kolumny], liczba = 0;
	printf("Przez jaka liczbe chcesz pomnozyc macierz: ");
	scanf("%d", &liczba);
	for(int i = 0; i < wiersze; i++)
	{
		for(int j = 0; j < kolumny; j++)
		{
			macierzPoMnozeniu[i][j] = liczba*macierz[i][j];
		}
	}
	WypisanieMacierzy(kolumny, wiersze, macierzPoMnozeniu);
}

int main(void)
{
	srand(time(NULL));
	printf("\nKalkulator macierzy\n\n");
	int kolumnyPierwszej, kolumnyDrugiej, wierszePierwszej, wierszeDrugiej;
	int* adrWierszePierwszej = &wierszePierwszej, *adrKolumnyPierwszej = &kolumnyPierwszej, *adrKolumnyDrugiej = &kolumnyDrugiej, *adrWierszeDrugiej = &wierszeDrugiej;
	int pierwszyWybor = WypisanieMenuPierwszego(), drugiWybor = WypisanieMenuDrugiego();
	int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], macierzDruga[wierszeDrugiej][kolumnyDrugiej];
	
	switch(pierwszyWybor)
	{
		case 1:
			printf("\nDODAWANIE\n\n");
			PobieranieRozmiaruMacierzy(adrKolumnyPierwszej, adrWierszePierwszej);
			PobieranieRozmiaruMacierzy(adrKolumnyDrugiej, adrWierszeDrugiej);

			OpcjeDlaDwochMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);

			DodawanieMacierzy(kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);
			break;
		case 2:
			printf("\nODEJMOWANIE\n\n");
			PobieranieRozmiaruMacierzy(adrKolumnyPierwszej, adrWierszePierwszej);
			PobieranieRozmiaruMacierzy(adrKolumnyDrugiej, adrWierszeDrugiej);

			OpcjeDlaDwochMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);

			OdejmowanieMacierzy(kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);
			break;
		case 3:
			printf("\nMNOZENIE\n\n");
			PobieranieRozmiaruMacierzy(adrKolumnyPierwszej, adrWierszePierwszej);
			PobieranieRozmiaruMacierzy(adrKolumnyDrugiej, adrWierszeDrugiej);

			OpcjeDlaDwochMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);

			MnozenieDwochMacierzy(kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);
			break;
		case 4:
			printf("\nMNOZENIE PRZEZ LICZBE\n\n");
			PobieranieRozmiaruMacierzy(adrKolumnyPierwszej, adrWierszePierwszej);
			
			OpcjeDlaJednejMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, macierzPierwsza);

			MnozenieMacierzyPrzezLiczbe(kolumnyPierwszej, wierszePierwszej, macierzPierwsza);
			break;
		case 5:
			printf("\nWYZNACZNIK MACIERZY\n\n");
			PobieranieRozmiaruMacierzy(adrKolumnyPierwszej, adrWierszePierwszej);
			
			OpcjeDlaJednejMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, macierzPierwsza);

			WyznacznikMacierzy(kolumnyPierwszej, wierszePierwszej, macierzPierwsza);
			break;
		case 6:
			printf("\nMACIERZ TRANSPONOWANA\n\n");
			PobieranieRozmiaruMacierzy(adrKolumnyPierwszej, adrWierszePierwszej);
			
			OpcjeDlaJednejMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, macierzPierwsza);

			MacierzTransponowana(kolumnyPierwszej, wierszePierwszej, macierzPierwsza);
			break;
		case 7:
			return 0;
		default:
			printf("Podales zly numer");
			break;
	}
	
	return 0;
}
