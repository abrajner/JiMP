#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(void* dane, size_t rozmiarDanych)
{
	long long suma = 0;
	int liczbaElementow = rozmiarDanych/sizeof(char);
	char* kopiaDanych = malloc(sizeof(unsigned char)*liczbaElementow);

	memcpy(kopiaDanych, dane, rozmiarDanych);

	for(int i = 0; i<liczbaElementow; i++)
	{
		printf("%x ", (char)kopiaDanych[i]);
		suma += (char)kopiaDanych[i];
	}	
	printf("\n");

	free(kopiaDanych);
	return suma;
}

int main(void)
{
	char a = 45;
	printf("%lli \n", copyArgumentAndPrintCharByCharReturningSumOfArguments(&a, sizeof a));
	int b = 12;
	printf("%lli \n", copyArgumentAndPrintCharByCharReturningSumOfArguments(&b, sizeof b));
	char c[] = "asdfghjjhgf";
	printf("%lli \n", copyArgumentAndPrintCharByCharReturningSumOfArguments(&c, sizeof c));
	return 0;
}

