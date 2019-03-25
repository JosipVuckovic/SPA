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
	printf("*    SPA Vjeba 2 2018/2019                      Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 - Merge sort, vjerovatnost dogadaja           *\n");
	printf("*    2 - Zadatak 2 - Vrhovi                                      *\n");
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
void merge(float* arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	/* create temp arrays */
	float* L;
	float* R;
	L = (float*)calloc(n1, sizeof(float));
	R = (float*)calloc(n2, sizeof(float));
	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(float* arr, int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;
		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
void zadatak_1()
{
	/*float testni_niz_1[5] = { 0.1, 0.3, 0.2, 0.5, 0.4 };*/
	//float testni_niz_2[9] = { 0.69 , 0.19, 0.42, 0.12, 0.61, 0.52, 0.76, 0.23, 0.93 };
	float* uneseni_niz;
	/*float uneseni_niz[5] = { 0.1, 0.3, 0.2, 0.5, 0.4 };*/
	int br_elemenata = 0;
	float sansa = 0;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Maksimalna vjerovatnost 3 dogadaja.                                *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite koliko elemenata zelite: ");
	scanf("%d", &br_elemenata);
	printf("\n**********************************************************************\n");
	uneseni_niz = (float*)calloc(br_elemenata, sizeof(float));
	for (int i = 0; i < br_elemenata; i++)
	{
		printf("Unesite %d. clan:  ", i + 1);
		scanf("%d", &uneseni_niz[i]);
		printf("\n");
	
	}
	mergeSort(uneseni_niz, 0,br_elemenata-1);
	for ( int i = 0; i < br_elemenata; i++)
	{
		printf("%f ", uneseni_niz[i]);
	}
	sansa = uneseni_niz[br_elemenata - 1] * uneseni_niz[br_elemenata- 2] * uneseni_niz[br_elemenata- 3];
	printf("**********************************************************************\n");
	printf("\nMaksimalna vjerovatnost 3 dogadaja je: %.2f\n", sansa);
	free(uneseni_niz);
	do_you_want_more();
}
int b_search(int* uneseni_niz, int poc, int kraj)
{
	int sred = (poc + kraj) / 2;
	if (uneseni_niz[sred - 1] < uneseni_niz[sred] && uneseni_niz[sred + 1] < uneseni_niz[sred])
	{
		return uneseni_niz[sred];
	}
	else if (uneseni_niz[sred - 1] > uneseni_niz[sred])
	{
		return b_search(uneseni_niz, poc, sred - 1);
	}
	else if (uneseni_niz[sred] <uneseni_niz[sred + 1])
	{

		return b_search(uneseni_niz, sred + 1, kraj);
	}
	return 0;
}
void zadatak_2()
{
	int* uneseni_niz;
	/*int test_niz_2[10] = { 10 ,89 ,76, 25, 63, 48, 11, 28, 63, 19 };*/
	/*int test_niz[5] = { 100, 123, 78, 122, 1 };*/
	int br_elemenata = 0;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 2                                   *\n");
	printf("* Vrhovi.                                                            *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite koliko elemenata zelite: ");
	scanf("%d", &br_elemenata);
	printf("\n");
	printf("**********************************************************************\n");
	uneseni_niz = (int*)calloc(br_elemenata, sizeof(int));
	for (int i = 0; i < br_elemenata; i++)
	{
	printf("Unesite %d. clan:  ", i + 1);
	scanf("%d", &uneseni_niz[i]);
	printf("\n");

	}
	printf("\nNadjen je vrh s visinom: %d", b_search(uneseni_niz, 0, br_elemenata));
	free(uneseni_niz);
	do_you_want_more();
}
