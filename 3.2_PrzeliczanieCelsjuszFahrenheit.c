#include <stdio.h>

void CelsjuszeNaFahrenheity(double stopnie)
{
	double stopnieF=(stopnie*1.8)+32;
	printf("%lf stopni Celsjusza to %lf stopnie Fahrenheita\n", stopnie, stopnieF);
}

void FahrenheityNaCelsjusze(double stopnie)
{
	double stopnieC=(stopnie-32)/1.8;
	printf("%lf stopni Fahrenheita to %lf stopnie Celsjusza\n", stopnie, stopnieC);
}

int main (void)
{
	int jednostkaStopni;
	double stopnie;
	printf ("Podaj jakiej zamiany chcesz dokonac - wpisz odpowiednia cyfre \nCelsjusze na Fahrenheity - 1 \nFahrenheity na Celsjusze - 2\n\n");
	scanf ("%d", &jednostkaStopni);
	printf("Podaj ilosc stopni\n");
	scanf ("%lf", &stopnie);
	switch (jednostkaStopni)
	{
		case 1:
			CelsjuszeNaFahrenheity(stopnie);
			break;
		case 2:
			FahrenheityNaCelsjusze(stopnie);
			break;
		default:
			printf ("cos wpisales zle\n");
			break;
	}
	return 0;

}
