#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "stack.h"
#include "list.h"
#include "queue.h"

void main_menu(void);
void zadatak_1();
void do_you_want_more(void);
void zadatak_2();
void zadatak_3();
int zadatak_4();
int zadatak_7();
int main(void)
{
	printf("******************************************************************\n");
	printf("*    SPA Vjeba 4 2018/2019                      Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 - Najstariji na stacku                        *\n");
	printf("*    2 - Zadatak 2 - Pojavljivanje druge liste u prvoj           *\n");
	printf("*    3 - Zadatak 3 - Izbacivanje najmanjeg clana iz reda         *\n");
	printf("*    Grupa L2:                                                   *\n");
	printf("*    4 - Zadatak 1 - Izbacivanje n elemenata sa stoga            *\n");
	/*printf("*    5 - Zadatak 1 - Izbacivanje n elemenata sa stoga            *\n");
	printf("*    6 - Zadatak 1 - Izbacivanje n elemenata sa stoga            *\n");*/
	printf("*    Grupa L3:                                                   *\n");
	printf("*    7 - Zadatak 1 - Ima li vise parnih ili neparnih na stogu    *\n");
	/*printf("*    8 - Zadatak 1 - Izbacivanje n elemenata sa stoga            *\n");
	printf("*    9 - Zadatak 1 - Izbacivanje n elemenata sa stoga            *\n");*/
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
	case '3':
		zadatak_3();
		break;
	case '4':
			zadatak_4();
		break;
	case '7':
		zadatak_7();
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
stack_element_t stack_deque(stack_t neki_stack)
{
	stack_element_t tmp_element=NULL;
	stack_t tmp_stack = stack_new();
	while (!stack_is_empty(neki_stack))
	{
		/*tmp_element=stack_pop(neki_stack);
		printf("%d\n", tmp_element);
		stack_push(tmp_stack, tmp_element);*/
		stack_push(tmp_stack, stack_pop(neki_stack));
	}
	tmp_element = stack_top(tmp_stack);
	while (!stack_is_empty(tmp_stack))
	{
		stack_push(neki_stack, stack_pop(tmp_stack));
	}
	stack_delete(tmp_stack);
	return tmp_element;

}
void zadatak_1(void)
{
	
	stack_t testni_stack = stack_new();
	stack_push(testni_stack, 3);
	stack_push(testni_stack, 10);
	stack_push(testni_stack, 6);
	stack_push(testni_stack, 7);
	stack_push(testni_stack, 1);
	stack_push(testni_stack, 9);
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Testiranje funkcije za skidanje najstarijeg elementa sa stacka.    *\n");
	printf("* Hardcodiran je testni stack iz pdfa                                *\n");
	printf("**********************************************************************\n");
		
	printf("\nZadnji je: %d", stack_deque(testni_stack));
	stack_delete(testni_stack);

	do_you_want_more();
}

int pojavljivanje_druge(list_t prva_lista, list_t druga_lista)
{
	list_iterator_t iterator_prva = list_iterator(prva_lista);
	list_iterator_t iterator_druga = list_iterator(druga_lista);
	list_element_t tmp = NULL;
	int i=0,j=0;
	while (list_iterator_is_valid(iterator_prva))
	{
		if (list_get(iterator_prva) == list_get(iterator_druga))
		{
			j++;
			list_iterator_next(iterator_druga);
			if (list_iterator_is_valid(iterator_druga))
			{
				i++;
				list_iterator_next(iterator_prva);
								
			}
			else
			{
				list_iterator_delete(iterator_prva);
				list_iterator_delete(iterator_druga);
				return i+1 - j;
			}
		}
		if ((list_get(iterator_prva) != list_get(iterator_druga))&&j>0)
		{
			j=0;
			iterator_druga=list_iterator(druga_lista);
			

		}
		list_iterator_next(iterator_prva);
		i++;
		
	}
	list_iterator_delete(iterator_prva);
	list_iterator_delete(iterator_druga);
	return -1;
}
void zadatak_2(void)
{
	list_t prva_lista = list_new();
	list_t druga_lista = list_new();
	/*0, 3, -1, 1, 3, -1, 5, 9, 7, 8, 9;*/
	list_add(prva_lista,0);
	list_add(prva_lista,3);
	list_add(prva_lista,-1);
	list_add(prva_lista,-1);
	list_add(prva_lista,3);
	list_add(prva_lista,-1);
	list_add(prva_lista,5);
	list_add(prva_lista,3);
	list_add(prva_lista,-1);
	list_add(prva_lista,7);
	list_add(prva_lista,9);
	/*3, -1, 5*/
	list_add(druga_lista,-1);
	list_add(druga_lista,3);
	list_add(druga_lista,-1);
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 2                                   *\n");
	printf("* Prvo pojavljivanje druge liste u prvoj. Liste su hardcodirane prema*\n");
	printf("* uputi iz pdfa                                                      *\n");
	printf("**********************************************************************\n");
	printf("Prvo pojavljivanje druge liste u prvoj je na indexu: %d",pojavljivanje_druge(prva_lista, druga_lista));
	list_delete(prva_lista);
	list_delete(druga_lista);
	do_you_want_more();
}
queue_element_t remove_smallest(queue_t red)
{
	if (queue_is_empty(red))
		return -1;
	queue_element_t najmanji = queue_front(red);
	queue_element_t tmp = najmanji;
	for (int i = 0; i < queue_size(red); i++)
	{
		tmp = queue_dequeue(red);
		/*printf("%d ", tmp);*/
		if (tmp < najmanji)
			najmanji = tmp;
		queue_enqueue(red,tmp);
	}
	for (int i = 0; i < queue_size(red); i++)
	{
		tmp = queue_dequeue(red);
		if (tmp != najmanji)
		{
			queue_enqueue(red, tmp);	
			
		}
		if (tmp == najmanji)
			i--;
	}
	/*printf("\n");
	for (int i = 0; i < queue_size(red); i++)
	{
		tmp = queue_dequeue(red);
		printf("%d ", tmp);
		queue_enqueue(red, tmp);
	}*/
	return najmanji;
}
void zadatak_3(void)
{
	queue_t red = queue_new();
	//11, 5, 12, 55, 7, 2, 6
	queue_enqueue(red, 11);
	queue_enqueue(red, 5);
	queue_enqueue(red, 12);
	queue_enqueue(red, 55);
	queue_enqueue(red, 7);
	queue_enqueue(red, 2);
	queue_enqueue(red, 6);
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 3                                   *\n");
	printf("* Izbacivanje najmanjeg clana iz reda. Te povrat njegove vrijednosti.*\n");
	printf("* Red je hardcodiran prema upiti iz pdfa.                            *\n");
	printf("**********************************************************************\n");
	printf("\nNajmanji je bio: %d ", remove_smallest(red));
	queue_delete(red);
	do_you_want_more();
}
stack_element_t multyPoP(stack_t neki_stack, int n)
{
	stack_element_t zadnji_skinuti = NULL;
	for (int i=0;i<n;i++)
	{
		if (stack_is_empty(neki_stack))
			break;
		zadnji_skinuti = stack_pop(neki_stack);
	}
	return zadnji_skinuti;
}
int zadatak_4 ()
{
	int n = 0;
	stack_t testni_stack = stack_new();
	/*4, 2, 6, 8, 3, 1, 2*/
	stack_push(testni_stack, 4);
	stack_push(testni_stack, 2);
	stack_push(testni_stack, 6);
	stack_push(testni_stack, 8);
	stack_push(testni_stack, 3);
	stack_push(testni_stack, 1);
	stack_push(testni_stack, 2);
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Skidanje n elemenata sa stacka, ukoliko je n veci od stacka, skida *\n");
	printf("* se do kraja stacka, stack hardcodiran kao u pdfu                   *\n");
	printf("**********************************************************************\n");
	printf("Unsi koliko elemenata. n=");
	scanf("%d", &n);
	printf("\nZadnji je: %d", multyPoP(testni_stack,n));
	stack_delete(testni_stack);

	do_you_want_more();
	return 0;
}
int par_nepar(stack_t neki_stack)
{
	stack_t tmp_stack = stack_new();
	stack_element_t tmp_element = NULL;
	int par = 0, nepar = 0;
	while (!stack_is_empty(neki_stack))
	{
		tmp_element = stack_pop(neki_stack);
		if (tmp_element % 2 == 0)
			par++;
		else
			nepar++;
		stack_push(tmp_stack, tmp_element);
	}
	while (!stack_is_empty(tmp_stack))
	{
		stack_push(neki_stack, stack_pop(tmp_stack));
	}
	if (par > nepar)
		return 1;
	else
		return 0;
}
int zadatak_7()
{
	stack_t testni_stack = stack_new();
	/*4, 2, 6, 8, 6, 1, 2*/
	stack_push(testni_stack, 4);
	stack_push(testni_stack, 2);
	stack_push(testni_stack, 6);
	stack_push(testni_stack, 8);
	stack_push(testni_stack, 6);
	stack_push(testni_stack, 1);
	stack_push(testni_stack, 2);
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Provjera ima li vise parnih ili neparnih na stacku. Stack mora     *\n");
	printf("* ostati ne promjenjen, stack hardcodiran kao u pdfu                 *\n");
	printf("**********************************************************************\n");
	if (par_nepar(testni_stack) == 1)
		printf("\nIma vise parnih brojeva");
	else
		printf("Ili ima više neparnih ili ih je isto");
	stack_delete(testni_stack);

	do_you_want_more();
	return 0;
}