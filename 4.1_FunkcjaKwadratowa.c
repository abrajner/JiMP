#include <stdio.h>
#include <math.h>

double ObliczanieDelty (double a, double b, double c)
{
	double delta = b*b-4*a*c;
	return delta;
}

double PierwszyPierwiastek (double delta, double b, double a)
{
	double x1=((-1)*b- (sqrt(delta)) )/(2*a);
	return x1;
}

double DrugiPierwiastek (double delta, double b, double a)
{
	double x2=((-1)*b+ (sqrt(delta)))/(2*a);
	return x2;
}

double JedenPierwiastek (double b, double a)
{
	double x=((-1)*b)/(2*a);
	return x;
}

int main (void)
{
	double a, b, c, x1, x2, x;
	printf ("Podaj wspolczynniki a,b,c w rownianiu kwadratowym o postaci y = a*x^2+b*x+c\n");
	printf ("a = ");
	scanf ("%lf", &a);
	printf ("b = ");
	scanf ("%lf", &b);
	printf ("c = ");
	scanf ("%lf", &c);
	while (a==0)
	{
		printf ("jesli a=0 nie jest to juz funkcja kwadratowa, wpisz wartosc a jeszcze raz\n");
		scanf("%lf", a);
	}
	double delta=ObliczanieDelty(a,b,c);
	if (delta==0)
	{
		x=JedenPierwiastek(b,a);
		printf ("rownanie ma jedno rozwiazanie x = %lf\n", x);
	}
	else if (delta<0)
	{
		printf ("rownanie nie ma rozwiazan\n");
	}
	else 
	{
		x1=PierwszyPierwiastek(delta,b,a);
		x2=DrugiPierwiastek(delta,b,a);
		printf ("rownanie ma dwa rozwiazania x1 = %lf oraz x2 = %lf\n", x1, x2);
	}
	return 0;
	
}
