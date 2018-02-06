#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "macierze.h"

int main(void)
{
	srand(time(NULL));
	printf("\nKalkulator macierzy\n\n");
	int kolumnyPierwszej = 0, kolumnyDrugiej = 0, wierszePierwszej = 0 , wierszeDrugiej = 0;
	int* adresWierszePierwszej = &wierszePierwszej, *adresKolumnyPierwszej = &kolumnyPierwszej, *adresKolumnyDrugiej = &kolumnyDrugiej, *adresWierszeDrugiej = &wierszeDrugiej;
	int pierwszyWybor = WypisanieMenuPierwszego(), drugiWybor = 0;
	if(pierwszyWybor<6)
		drugiWybor = WypisanieMenuDrugiego();
	int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], macierzDruga[wierszeDrugiej][kolumnyDrugiej];
	
	switch(pierwszyWybor)
	{
		case 1:
			printf("\nDODAWANIE\n\n");
			PobieranieRozmiaruMacierzy(adresKolumnyPierwszej, adresWierszePierwszej);
			PobieranieRozmiaruMacierzy(adresKolumnyDrugiej, adresWierszeDrugiej);

			OpcjeDlaDwochMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);

			DodawanieMacierzy(kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);
			break;
		case 2:
			printf("\nODEJMOWANIE\n\n");
			PobieranieRozmiaruMacierzy(adresKolumnyPierwszej, adresWierszePierwszej);
			PobieranieRozmiaruMacierzy(adresKolumnyDrugiej, adresWierszeDrugiej);

			OpcjeDlaDwochMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);

			OdejmowanieMacierzy(kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);
			break;
		case 3:
			printf("\nMNOZENIE\n\n");
			PobieranieRozmiaruMacierzy(adresKolumnyPierwszej, adresWierszePierwszej);
			PobieranieRozmiaruMacierzy(adresKolumnyDrugiej, adresWierszeDrugiej);

			OpcjeDlaDwochMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);

			MnozenieDwochMacierzy(kolumnyPierwszej, wierszePierwszej, kolumnyDrugiej, wierszeDrugiej, macierzPierwsza, macierzDruga);
			break;
		case 4:
			printf("\nMNOZENIE PRZEZ LICZBE\n\n");
			PobieranieRozmiaruMacierzy(adresKolumnyPierwszej, adresWierszePierwszej);
			
			OpcjeDlaJednejMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, macierzPierwsza);

			MnozenieMacierzyPrzezLiczbe(kolumnyPierwszej, wierszePierwszej, macierzPierwsza);
			break;
		case 5:
			printf("\nWYZNACZNIK MACIERZY\n\n");
			PobieranieRozmiaruMacierzy(adresKolumnyPierwszej, adresWierszePierwszej);
			
			OpcjeDlaJednejMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, macierzPierwsza);

			WyznacznikMacierzy(kolumnyPierwszej, wierszePierwszej, macierzPierwsza);
			break;
		case 6:
			printf("\nMACIERZ TRANSPONOWANA\n\n");
			PobieranieRozmiaruMacierzy(adresKolumnyPierwszej, adresWierszePierwszej);
			
			OpcjeDlaJednejMacierzy(drugiWybor, kolumnyPierwszej, wierszePierwszej, macierzPierwsza);

			MacierzTransponowana(kolumnyPierwszej, wierszePierwszej, macierzPierwsza);
			break;
		case 7:
			break;
			return 0;
		default:
			printf("Podales zly numer");
			break;
	}
	return 0;
}
