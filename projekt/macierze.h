#ifndef macierze_h
#define macierze_h

void GenerowanieMacierzy (int kolumny, int wiersze, int macierz[wiersze][kolumny]);
void WypisanieMacierzy (int kolumny, int wiersze, int macierz[wiersze][kolumny]);
int WypisanieMenuPierwszego();
int WypisanieMenuDrugiego();
void PobieranieRozmiaruMacierzy(int* kolumny, int* wiersze);
void WpisywanieMacierzyPrzezUzytkownika(int kolumny, int wiersze, int macierz[wiersze][kolumny]);

void OpcjeDlaDwochMacierzy(int drugiWybor, int kolumnyPierwszej, int wierszePierwszej, int kolumnyDrugiej, int wierszeDrugiej, int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], int macierzDruga[wierszeDrugiej][kolumnyDrugiej]);
void OpcjeDlaJednejMacierzy(int drugiWybor, int kolumny, int wiersze, int macierz[wiersze][kolumny]);

void DodawanieMacierzy(int kolumnyPierwszej, int wierszePierwszej, int kolumnyDrugiej, int wierszeDrugiej, int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], int macierzDruga[wierszeDrugiej][kolumnyDrugiej]);
void OdejmowanieMacierzy(int kolumnyPierwszej, int wierszePierwszej, int kolumnyDrugiej, int wierszeDrugiej, int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], int macierzDruga[wierszeDrugiej][kolumnyDrugiej]);
void WyznacznikMacierzy(int kolumny, int wiersze, int macierz[wiersze][kolumny]);
void MacierzTransponowana(int kolumny, int wiersze, int macierz[wiersze][kolumny]);
void MnozenieDwochMacierzy(int kolumnyPierwszej, int wierszePierwszej, int kolumnyDrugiej, int wierszeDrugiej, int macierzPierwsza[wierszePierwszej][kolumnyPierwszej], int macierzDruga[wierszeDrugiej][kolumnyDrugiej]);
void MnozenieMacierzyPrzezLiczbe(int kolumny, int wiersze, int macierz[wiersze][kolumny]);

#endif
