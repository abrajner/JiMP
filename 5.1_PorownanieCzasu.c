#include <stdio.h>

int GenerowanieTablicyZGodzina (int godzina[3])
{
	printf("Wpisz po kolei godzine, minute i sekunde\n");
	printf ("godziny = ");
	scanf ("%d", &godzina[0]);
	printf ("minuty = ");
	scanf ("%d", &godzina[1]);
	printf ("sekundy = ");
	scanf ("%d", &godzina[2]);
	while (godzina[0]<0||godzina[0]>24)
	{
		printf ("Podales zla godzine, wartosc musi zawierac sie miedzy 0 i 24, wpisz jeszcze raz \n");
		scanf ("%d", &godzina[0]);
	}
	while (godzina [1]<0||godzina[1]>60)
	{
		printf ("Podales zle minuty, wartosc musi zawierac sie miedzy 0 i 60, wpisz jeszcze raz \n");
		scanf ("%d", &godzina[1]);
	}
	while (godzina [2]<0||godzina[2]>60)
	{
		printf ("Podales zle sekundy, wartosc musi zawierac sie miedzy 0 i 60, wpisz jeszcze raz \n");
		scanf ("%d", &godzina[2]);
	}
	return godzina[3];
}


int PorownanieDwoch (int godzinastart[3], int godzinastop[3])
{
	if (godzinastart[0]>godzinastop[0])
	{	
		if (godzinastart[1]>godzinastop[1])
		{
			if (godzinastart[2]>godzinastop[2])
				return 1;
			else 
				return -1;
		}
		else
			return 1;
	}
	else if (godzinastart[0]==godzinastop[0])
	{	
		if (godzinastart[1]==godzinastop[1])
		{
			if (godzinastart[2]==godzinastop[2])
				return 0;
			else if (godzinastart[2]>godzinastop[2])
				return 1;
			else 
				return -1;
		}
		else if (godzinastart[1]>godzinastop[1])
		{
			if (godzinastart[2]>godzinastop[2])
				return 1;
			else 
				return -1;
		}
		else 
			return -1;
	}
	else 
		return -1;
}

int main (void)
{
	int godzina1[3], godzina2[3];	
	GenerowanieTablicyZGodzina (godzina1);
	GenerowanieTablicyZGodzina (godzina2);
	
	int x = PorownanieDwoch(godzina1, godzina2);
	switch (x)
	{
		case 0:
			printf("godziny sa rowne \n");
			break;
		case 1:
			printf ("pierwsza wpisana godzina jest wieksza\n");
			break;
		case (-1):
			printf ("druga wpiasana godzina jest wieksza\n");
			break;
	}
	
	return 0;
}

