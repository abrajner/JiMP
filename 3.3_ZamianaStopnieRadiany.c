#include <stdio.h>
#include <string.h>
#include <math.h>
#define pi 3.14

void StopnieNaRadiany ()
{
	double stopnie;
	printf ("Ilość stopni: \n");
	scanf ("%lf", &stopnie);
	double radiany= stopnie *(pi/180);
	printf ("to %lf/pi radianow\n", radiany);
}

void RadianyNaStopnie (void)
{
	double radiany;	
	printf ("Ilość radianow: \n");
	scanf ("%lf", &radiany);
	double stopnie=radiany*(180/pi);
	printf ("to %lf stopni\n", stopnie);
}

int main (void)
{
	double stopnie, radiany;
	int jednostka;	
	printf ("Podaj z jakiej jednostki chcesz zamienic - wpisz pierwsza litere \n1-radiany na stopnie \n2-stopnie na radiany\n");
	scanf ("%d", jednostka);
	switch (jednostka)
	{
		case 1:
			RadianyNaStopnie()
			break;
		case 2:
			StopnieNaRadiany();
			break;
		default:
			printf ("cos wpisales zle\n");
			break;
	}
	return 0;
}
