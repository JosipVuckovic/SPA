#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "book.h"
#include "set.h"
#include "djb2.h"
#include "map.h"

void main_menu(void);
int zadatak_1();
int zadatak_2();
void do_you_want_more(void);

int main(void)
{
	printf("******************************************************************\n");
	printf("*    SPA Vjeba 6 2018/2019                      Josip Vuckovic   *\n");
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
	printf("*    Grupa L1:                                                   *\n");
	printf("*    1 - Zadatak 1 -Broj autora i knjiga                         *\n");
	printf("*    2 - Zadatak 2 - Ispis svih autora i knjiga                  *\n");
	printf("*    X - Izlaz                                                   *\n");
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
	case 'X':
	case 'x':
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
		printf("\nHvala na koristenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		break;
	case 'N':
		printf("\nHvala na koristenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		break;
	default:
		printf("\nNepoznat unos!\n");
		do_you_want_more();
		break;
	}
}

void autori_ukupno(struct book *books, unsigned broj) {
	char autor[255+1];
	printf("\n");
	printf("\n**********************************************************************\n");
	map_t knjige;
	knjige = map_new_advanced(strcmp, djb2);
	for (int i = 0; i < broj; ++i)
	{
		strcpy(autor, books[i].author);

		if (!*autor)
			return;

		//pregled dali vec imamo autora i ubacivanje u mapu
		if (map_has_key(knjige, autor))
		{
			map_put(knjige, _strdup(autor), map_get(knjige, autor));
		}
		else
		{
			map_put(knjige, _strdup(autor), 1);
		}
	}
	printf("U datoteci je: %d knjiga te %d autora.", broj, map_size(knjige));
}

void autori_i_knjige(struct book *books, unsigned broj) {
	char autor[255+1];
	printf("\n");
	printf("\n**********************************************************************\n");
	printf("\n Ispis autora i broja njihovih knjiga: \n");
	map_t knjige;
	knjige = map_new_advanced(strcmp, djb2);
	for (int i = 0; i < broj; ++i)
	{
		strcpy(autor, books[i].author);

		if (!*autor)
			return;

		//pregled dali vec imamo autora i ubacivanje u mapu
		if (map_has_key(knjige, autor))
		{
			map_put(knjige, _strdup(autor), map_get(knjige, autor) + 1);
		}
		else
		{
			map_put(knjige, _strdup(autor), 1);
		}
	}

	for (map_iterator_t iterator = map_iterator(knjige); map_iterator_is_valid(iterator); map_iterator_next(iterator))
	{
		map_element_t element = map_iget(iterator);
		printf("\nAutor: %s Br. knjiga: %d", element.key, element.value);
	}
}


int zadatak_1()
{

	struct book *books = NULL;
	unsigned broj = 0;

	if (load_books("knjige.csv", &books, &broj))
		return -1;

	autori_ukupno(books, broj);
	free(books);
	do_you_want_more();
	return 0;
}
int zadatak_2()
{
	struct book *books = NULL;
	unsigned broj = 0;

	if (load_books("knjige.csv", &books, &broj))
		return -1;
	autori_i_knjige(books, broj);
	free(books);
	do_you_want_more();
	return 0;
}
