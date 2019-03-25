#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>


void main_menu(void);
void zadatak_1();
void do_you_want_more(void);
//void zadatak_2();
void zadatak_3();
//int zadatak_4();
int main(void)
{
	printf("******************************************************************\n");
	printf("*    SPA Vjeba 3 2018/2019                      Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 - Zbroj podniza                               *\n");
	printf("*    3 - Zadatak 3 - Moderna skolica                             *\n");
	//printf("*    4 - Knapsack kamion                                         *\n");
	printf("*    5 - Izlaz                                                   *\n");
	printf("******************************************************************\n");
	printf("         Vas izbor: ");
	scanf(" %c", &izbor);
	switch (izbor)
	{
	case '1':
		zadatak_1();
		break;
	//case '2':
	//	zadatak_2();
	//	break;
	case '3':
		zadatak_3();
		break;
	//case '4':
	//	zadatak_4();
	//	break;
	case '5':
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

//int max(int n1, int n2) {
//	return n1 > n2 ? n1 : n2;
//}
int find_max_sub( int *arr, int length) {
	int max_sum = arr[0]; int curr_max = arr[0]; // set values of first element
	for (int i = 1; i < length; i++) {// iterate
		curr_max = max(arr[i], curr_max + arr[i]); // return max of arr[i] and curr_max +arr[i]
		max_sum = max(max_sum, curr_max);
	}
	return max_sum;
}
void zadatak_1()
{
	int test_niz[12] = { 3, 4, 4, 6, 2, 8, 6, 9, 7, 3, 1, 4 };
	int test_niz_2[18] = { 9,2,3,5,-7,-6,5,-8,8,-7,2,-3, 1, -3,-4, 1,-5,-6 };
	int test_niz_3[8] = { -2 ,-3, 4, -1, -2, 1, 5, -3 };
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 1                                   *\n");
	printf("* Nagrade s radija.                                                  *\n");
	printf("**********************************************************************\n");
	int br_clan = 18;
	int i = find_max_sub(test_niz_2, br_clan);
	printf("%d", i);
	
	do_you_want_more();

}

int br_koraka(int n) {
	int koraka = 0;
	while (1) {
		if (n == 1)
			break;
		if (!(n % 3)) {
			n /= 3;
			koraka++;
		}
		else if (!(n % 2)) {
			n /= 2;
			koraka++;
		}
		else if (n>1) {
			--n;
			koraka++;
		}
	}
	return koraka;
}

void zadatak_3()
{
	srand((unsigned)time(NULL));
	int n = rand() % 10;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                        Zadatak 3                                   *\n");
	printf("* Moderna skolica.                                                   *\n");
	printf("**********************************************************************\n");
	printf("N= %d trebas %d koraka", n, br_koraka(n));
	printf("\n Trebas %d koraka", br_koraka(5));
	printf("\n Trebas %d koraka", br_koraka(10));
	do_you_want_more();
}

//int maks(int a, int b) { return (a > b) ? a : b; }
//
//// Returns the maximum value that can be put in a knapsack of capacity W 
//int knapSack(int W, int wt[], int val[], int n)
//{
//	// Base Case 
//	if (n == 0 || W == 0)
//		return 0;
//
//	// If weight of the nth item is more than Knapsack capacity W, then 
//	// this item cannot be included in the optimal solution 
//	if (wt[n - 1] > W)
//		return knapSack(W, wt, val, n - 1);
//
//	// Return the maximum of two cases:  
//	// (1) nth item included  
//	// (2) not included 
//	else return maks(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
//		knapSack(W, wt, val, n - 1)
//	);
//}

//// Returns the maximum value that can be put in a knapsack of capacity W 
//int knapSack2(int pijesak,int sljunak, int pijesak_prijevoz[], int sljunak_prijevoz[],int benga_prijevoz, int broj_kamiona)
//{
//	// Base Case 
//	if (broj_kamiona == 0 || pijesak == 0 || sljunak == 0)
//		return 0;
//
//	// If weight of the nth item is more than Knapsack capacity W, then 
//	// this item cannot be included in the optimal solution 
//	if (pijesak_prijevoz[broj_kamiona - 1] >= pijesak || sljunak_prijevoz[broj_kamiona-1]>= sljunak )
//		return knapSack(W, wt, val, n - 1);
//
//	// Return the maximum of two cases:  
//	// (1) nth item included  
//	// (2) not included 
//	else return maks(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
//		knapSack(W, wt, val, n - 1)
//	);
//}
//struct materijala_u_kamionu {
//	int pijeska_u_kamionu;
//	int sljunka_u_kamionu;
//	int goriva_za_kamion;
//};
//
//int knapsack_kamion(int n, int c, struct materijala_u_kamionu m)
//{
//	int i, j; 
//	int w[5];
//	int p[5];
//	int M[5][3][3];
//	for (i = 0; i <= n; i++)
//		M[i][0] = 0; 
//	for (j = 0; j <= c; j++)  
//		M[0][j] = 0; 
//	for (i = 1; i <= n; i++) 
//		for (j = 1; j <= c; j++)
//		{ 
//			M[i][j] = M[i - 1][j]; 
//	
//			if (j >= w[i]) 
//				if ((M[i - 1][j - w[i]] + p[i]) > M[i - 1][j]) M[i][j] = M[i - 1][j - w[i]] + p[i];
//		}
//		return M[n][c];
//}
//
//int zadatak_4()
//{
//	int potrebno_pijeska=0, potrebno_sljunka=0, broj_kamiona=0;
//	struct materijala_u_kamionu prijevoz[5];
//	system("cls");
//	printf("**********************************************************************\n");
//	printf("*                        Zadatak 4                                   *\n");
//	printf("* Knapsack prema podatcima iz pdfa, neki kamioni i gradjevinski mat. *\n");
//	printf("**********************************************************************\n");
//	printf("\n");
//	potrebno_pijeska = 5;
//	printf("Koliko pijeska: %d ", potrebno_pijeska);
//	potrebno_sljunka = 60;
//	printf("Koliko sljunka: %d ", potrebno_sljunka);
//	broj_kamiona = 5;
//	printf("Koliko kamiona: %d", broj_kamiona);
//
//	prijevoz[0].pijeska_u_kamionu = 3;
//	prijevoz[0].sljunka_u_kamionu = 36;
//	prijevoz[0].goriva_za_kamion = 120;
//	
//	prijevoz[1].pijeska_u_kamionu = 10;
//	prijevoz[1].sljunka_u_kamionu = 25;
//	prijevoz[1].goriva_za_kamion = 129;
//
//	prijevoz[2].pijeska_u_kamionu = 5;
//	prijevoz[2].sljunka_u_kamionu = 50;
//	prijevoz[2].goriva_za_kamion = 250;
//
//	prijevoz[3].pijeska_u_kamionu = 1;
//	prijevoz[3].sljunka_u_kamionu = 45;
//	prijevoz[3].goriva_za_kamion = 130;
//	
//	prijevoz[4].pijeska_u_kamionu = 4;
//	prijevoz[4].sljunka_u_kamionu = 20;
//	prijevoz[4].goriva_za_kamion = 119;
//	
//	
//	
//	
//	do_you_want_more();
//}
