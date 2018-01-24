#include <stdio.h>

int ObliczanieCyfryPodanejPrzezUzytkownika (int CyfraPodanaPrzezUzytkownika)
{
	if (CyfraPodanaPrzezUzytkownika>=6)
	{
		if (CyfraPodanaPrzezUzytkownika<=8)
		{
			if (CyfraPodanaPrzezUzytkownika>=7)
			{
				if (CyfraPodanaPrzezUzytkownika==8)
				{
					printf ("twoja cyfra to 8\n");
				}
				else 
				{
					printf("twoja cyfra to 7\n");
				}
			}
			else
			{
				printf("twoja cyfra to 6\n");
			}
		}
		else
		{
			if (CyfraPodanaPrzezUzytkownika==10)
			{
				printf("twoja cyfra to 10\n");
			}
			else
			{
				printf("twoja cyfra to 9\n");
			}
		}
	}
	else
	{
		if (CyfraPodanaPrzezUzytkownika<=3)
		{
			if (CyfraPodanaPrzezUzytkownika>=2)
			{
				if (CyfraPodanaPrzezUzytkownika==3)
				{
					printf ("twoja cyfra to 3\n");
				}
				else 
				{
					printf("twoja cyfra to 2\n");
				}
			}
			else
			{
				printf("twoja cyfra to 1\n");
			}
		}
		else
		{
			if (CyfraPodanaPrzezUzytkownika==4)
			{
				printf("twoja cyfra to 4\n");
			}
			else
			{
				printf("twoja cyfra to 5\n");
			}
		}
	}
}
int main (void)
{
	int CyfraPodanaPrzezUzytkownika;
	printf ("podaj cyfre od 1-10\n");
	scanf ("%d", &CyfraPodanaPrzezUzytkownika);
	if (CyfraPodanaPrzezUzytkownika>10||CyfraPodanaPrzezUzytkownika<1)
	{
		printf ("nieprawidlowa cyfra, miales podac cyfre z zakrasu od 1 do 10\n");	
	}
	else 
	{	
		ObliczanieCyfryPodanejPrzezUzytkownika (CyfraPodanaPrzezUzytkownika);
	}
	return 0;
}
