#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>


void main_menu(void);
void zadatak_1();
void do_you_want_more(void);
void zadatak_2();
int main(void)
{
	printf("******************************************************************\n");
	printf("*    SPA Vjeba 1 2018/2019                      Josip Vuckovic   *\n");
	printf("*    Ovaj program moze pokretati sve zadatke iz vjezbe te Vas    *\n");
	printf("*    molim da napravite izbor koji zadatak Vas zanima.           *\n");
	printf("******************************************************************\n");
	main_menu();
	return 0;
}
void main_menu(void)
{
	char izbor;
	printf("******************************************************************\n");
	printf("*    1 - Zadatak 1 - Vise dimenzijski nizovi, matrice            *\n");
	printf("*    2 - Zadatak 2 - Pregled koliko brojeva ima neki korak       *\n");
	printf("*    4 - Izlaz                                                   *\n");
	printf("******************************************************************\n");
	printf("         Vas izbor: ");
	scanf(" %c", &izbor);
	switch (izbor)
	{
	case '1':
		zadatak_1();
		break;
	case '2':
		zadatak_2();
		break;
	case '4':
		printf("\nHvala na koristenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		getchar();
		break;
	default:
		system("cls");
		printf("\n\n **Nepoznat odabir, molim Vas ponovite unos**\n\n");
		main_menu();
		break;
	}
}
void do_you_want_more(void)
{
	char odabir;
	printf("\n**********************************************************************\n");
	printf("*Zelite li drugi zadatak?*\n");
	printf("**********************************************************************\n");
	printf("y/n: ");
	scanf(" %c", &odabir);
	switch (odabir)
	{
	case 'y':
		system("cls");
		main_menu();
		break;
	case 'Y':
		system("cls");
		main_menu();
		break;
	case 'n':
		printf("\nHvala na korištenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		break;
	case 'N':
		printf("\nHvala na korištenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		break;
	default:
		printf("\nNepoznat unos!\n");
		do_you_want_more();
		break;
	}
}
void zadatak_1()
{
	int colums = 0, rows = 0, dimenzija_matrice=0;
	int zbrojglavne = 0, zbrojsporedne = 0;
	int **matrica;
	srand(time(0));
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Unosimo dimenziju kvadratne matrice i gledamo jeli najljepsa ili   *\n");
	printf("* nije. Najljepsa je ona kojoj je razlika zbrojeva glavne i sporedne *\n");
	printf("* dijagonale 0. Matrica se puni random brojevima. Max dim=100        *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite dimenziju kvadratne matrice: ");
	scanf("%d", &dimenzija_matrice);
	if (dimenzija_matrice>100)
	{
		printf("Prevelika matrica! Ponovite zadatak!\n");
		printf("Pritisni bilo koju tipku za nastavak...\n");
		getchar();
		getchar();
		do_you_want_more();
	}
	printf("\n**********************************************************************\n");
	matrica=calloc(dimenzija_matrice,sizeof (int*));
	for (colums= 0;colums  < dimenzija_matrice;colums ++)
	{
		matrica[colums] = calloc(dimenzija_matrice, sizeof*(matrica[colums]));
	}
	for (colums = 0; colums < dimenzija_matrice; colums++)
	{
		for ( rows= 0; rows < dimenzija_matrice; rows++)
		{
			matrica[colums][rows] = rand() % (100 + 1 - (-100)) + (-100);
			if (colums == rows)
				zbrojglavne += matrica[colums][rows];
			if (colums + rows == dimenzija_matrice - 1)
				zbrojsporedne += matrica[colums][rows];
			printf("%d", matrica[colums][rows]);
			printf("  ");
		}
		printf("\n");
	}
	printf("\n**********************************************************************\n");
	printf("Zbroj glavne dijagonale: %d\n", zbrojglavne);
	printf("Zbroj sporedne dihagonale: %d\n", zbrojsporedne);
	printf("\n**********************************************************************\n");
	if (zbrojglavne - zbrojsporedne == 0)
		printf("Matrica je najljepsa!");
	else
		printf("Matrica nije najljepsa!");
	printf("\n");
	free(matrica);
	do_you_want_more();
}

void zadatak_2()
{
	int dimenzija_niza = 0, korak = 0, koliko_brojeva = 0, i = 0, j=0;
	int *niz;
	srand(time(0));
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 2                                   *\n");
	printf("* Unosimo dimenziju niza (max 10 000) i neki korak, nakon toga       *\n");
	printf("* gledamo koliko parova brojeva ima baš taj korak kao razliku izmedu *\n");
	printf("* njih ( max 100).                                                   *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite dimenziju niza: ");
	scanf("%d", &dimenzija_niza);
	printf("\nUnesite korak: ");
	scanf("%d", &korak);
	if (dimenzija_niza > 10000 || korak>100)
	{
		printf("Krivi unos! Ponovite zadatak!\n");
		printf("Pritisni bilo koju tipku za nastavak...\n");
		getchar();
		getchar();
		do_you_want_more();
	}
	niz = calloc(dimenzija_niza, sizeof(int));
	printf("\n**********************************************************************\n");
	for ( i = 0; i < dimenzija_niza; i++)
	{
		niz[i] = rand();
		printf("%d", niz[i]);
		printf("  ");
	}
	printf("\n**********************************************************************\n");
	for ( i = 0; i < dimenzija_niza; i++)
	{
		for (j = i; j < dimenzija_niza; j++)
		{
			if (abs(niz[j] - niz[i+1]) == korak)
			koliko_brojeva++;
		}
	}
	printf("Parova brojeva koji imaju korak: %d je bilo: %d",korak,koliko_brojeva);
	printf("\n");
	free(niz);
	do_you_want_more();
}