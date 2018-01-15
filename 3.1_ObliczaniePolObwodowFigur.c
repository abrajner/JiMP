#include <stdio.h>
#include <string.h>
#include <math.h>
#define pi 3.14

void WypisanieWynikow (double pole, double obwod)
{
	printf("Pole = %lf\n", pole);
	printf("Obwod = %lf\n", obwod);
}

double PobieranieNieujemnychBokow(const char *wiadomoscDoUzytkownika)
{
	double dlugoscBoku=0;
	printf("%s\n", wiadomoscDoUzytkownika);
	scanf("%lf", &dlugoscBoku);
	while (dlugoscBoku<=0)
	{
		printf ("Podales zla dlugosc boku, wartosc musi byc wieksza, wpisz jeszcze raz \n");
		scanf ("%lf", &dlugoscBoku);
	}
	return dlugoscBoku;
}

void PoleObwodKwadratu ()
{
	double dlugosc = PobieranieNieujemnychBokow("Podaj dlugosc boku kwadratu");
	double pole=dlugosc*dlugosc;
	double obwod= dlugosc*4;
	WypisanieWynikow (pole, obwod);
}

void PoleObwodTrojkata ()
{
	double dlugosc = PobieranieNieujemnychBokow("Podaj dlugosc boku trojkata");
	double wysokosc = PobieranieNieujemnychBokow("Podaj wysokosc trojkata");
	double pole = dlugosc*wysokosc*(0.5);
	double obwod = dlugosc*3;
	WypisanieWynikow (pole, obwod);
}

void PoleObwodProstokata ()
{
	double dlugosc = PobieranieNieujemnychBokow("Podaj dlugosc prostokata");
	double szerokosc = PobieranieNieujemnychBokow("Podaj szerokosc prostokata");
	double pole=dlugosc*szerokosc;
	double obwod=2*dlugosc+2*szerokosc;
	WypisanieWynikow (pole, obwod);
}

void PoleObwodKola ()
{
	double promienKola = PobieranieNieujemnychBokow("Podaj promien kola");
	double pole = promienKola*promienKola*pi;
	double obwod = 2*pi*promienKola;
	WypisanieWynikow (pole, obwod);
}

int main (void)
{
	double dlugosc, szerokosc, wysokosc, PromienKola;
	int wyborFigury;
	printf ("Pole i obwod jakiej figury chcesz obliczyc? wpisz odpowiednia cyfre \nkwadrat - 1\ntrojkat rownoboczny - 2\nprostokat - 3\nkolo - 4\n\n");
	scanf ("%d", &wyborFigury);

	switch (wyborFigury)
	{
		case 1:
			PoleObwodKwadratu();
			break;
		case 2:
			PoleObwodTrojkata();
			break;
		case 3:
			PoleObwodProstokata();
			break;
		case 4:
			PoleObwodKola();
			break;
		default: 
			printf ("nie mozna obliczyc pola dla tej figury, cos wpisales zle\n");
			break;
	}

	return 0;
}
