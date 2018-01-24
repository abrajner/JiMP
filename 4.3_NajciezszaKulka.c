#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void PorownanieKulek (int kulka[8])
{
	if (kulka[0]+kulka[1]+kulka[2]==1)  
	{
		if (kulka[0]==1)
			printf("Pierwsza kulka jest najciezsza\n");
		else if (kulka[1]==1)
			printf("Druga kulka jest najciezsza\n");
		else
			printf("Trzecia kulka jest najciezsza\n");
	}
	else if (kulka[3]+kulka[4]+kulka[5]==1)
	{
		if (kulka[3]==1)
			printf("Czwarta kulka jest najciezsza\n");
		else if (kulka[4]==1)
			printf("Piata kulka jest najciezsza\n");
		else
			printf("Szosta kulka jest najciezsza\n");
	}
	else 
	{
		if (kulka[6]==1)
			printf("Siodma kulka jest najciezsza\n");
		else if (kulka[7]==1)
			printf("Osma kulka jest najciezsza\n");
		else
			printf("Dziewiata kulka jest najciezsza\n");
	}

}

int main(void)
{
	int kulka[] = {0,0,0,0,0,0,0,0};
	srand(time(0));
	int losowaKulka= rand()%sizeof(kulka);
	kulka[losowaKulka] = 1;

	PorownanieKulek (kulka);
	return 0;
}
