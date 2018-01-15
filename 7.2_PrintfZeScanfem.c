#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void WypisanieTekstu (char* tekst, ...)
{
	int dlugoscTekstu = strlen(tekst);
	va_list wszystkieArgumenty;
	va_start(wszystkieArgumenty, tekst);
	int *argument;
	int i = 0;

	for (i; i< dlugoscTekstu; i++)
	{
		if (tekst[i] == '%' && tekst[i+1] == 'd')
		{
			i++;
			argument = va_arg(wszystkieArgumenty, int*);
			scanf("%d", argument);
		}
		else
		{
			printf("%c", tekst[i]);
		}
	}
	
	va_end(wszystkieArgumenty);
}

int main (void)
{
	int wartosc1;
	int wartosc2;
	int wartosc3;
	
	WypisanieTekstu("Boki trojkata - pierwszy: %ddrugi: %dtrzeci: %d", &wartosc1, &wartosc2, &wartosc3);
	return 0;
}
