#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <limits.h>
#include "queue.h"

// M x N matrix
#define M 1000
#define N 1000

void main_menu(void);
int zadatak_1();
void do_you_want_more(void);

int main(void)
{
	printf("******************************************************************\n");
	printf("*    SPA Vjeba 7 2018/2019                      Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 -BFS                                          *\n");
	printf("*    X - Izlaz                                                   *\n");
	printf("******************************************************************\n");
	printf("         Vas izbor: ");
	scanf(" %c", &izbor);
	switch (izbor)
	{
	case '1':
		zadatak_1();
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
// queue node used in BFS
struct Node
{
	// (x, y) represents matrix cell coordinates
	// dist represent its minimum distance from the source
	int x, y, dist;
};

// Below arrays details all 4 possible movements from a cell
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

// Function to check if it is possible to go to position (row, col)
// from current position. The function returns false if (row, col)
// is not a valid position or has value 0 or it is already visited
//bool isValid(int mat[][N], bool visited[][N], int row, int col)
//{
//	return (row >= 0) && (row < M) && (col >= 0) && (col < N)
//		&& mat[row][col] && !visited[row][col];
//}

int isValid(int mat[][N], int visited[][N], int row, int col)
{
	return(row >= 0) && (row < M) && (col >= 0) && (col < N)
		&& mat[row][col] && !visited[row][col];
}

// Find Shortest Possible Route in a matrix mat from source
// cell (i, j) to destination cell (x, y)
void BFS(int mat[][N], int i, int j, int x, int y)
{
	// construct a matrix to keep track of visited cells
	int visited[M][N];
	
	// initially all cells are unvisited
	memset(visited, 0, sizeof visited);

	// create an empty queue
	queue_t q= queue_new();


	// mark source cell as visited and enqueue the source node
	visited[i][j] = 0;
	queue_element_t tmp = {0,0,0};
	queue_enqueue(q, tmp);
	/*q.push({ i, j, 0 });*/

	// stores length of longest path from source to destination
	int min_dist = INT_MAX;

	// run till queue is not empty	
	while (!queue_is_empty(q))
	{
		// pop front node from queue and process it
		/*struct Node node = q.front();*/
		struct Node node = queue_front(q);
		//q.pop();
		queue_dequeue(q);

		// (i, j) represents current cell and dist stores its
		// minimum distance from the source
		int i = node.x, j = node.y, dist = node.dist;

		// if destination is found, update min_dist and stop
		if (i == x && j == y)
		{
			min_dist = dist;
			break;
		}

		// check for all 4 possible movements from current cell
		// and enqueue each valid movement
		for (int k = 0; k < 4; k++)
		{
			// check if it is possible to go to position
			// (i + row[k], j + col[k]) from current position
			if (isValid(mat, visited, i + row[k], j + col[k]))
			{
				// mark next cell as visited and enqueue it
				visited[i + row[k]][j + col[k]] = 1;
				//q.push({ i + row[k], j + col[k], dist + 1 });
				queue_enqueue( i + row[k], j + col[k], dist + 1 );
			}
		}
	}

	if (min_dist != INT_MAX)
		/*cout << "The shortest path from source to destination "
		"has length " << min_dist;*/
		printf(" Najmanja udaljenost: %d", min_dist);
	else
		/*cout << "Destination can't be reached from given source";*/
		printf("Nema izlaza");
}


int main()
{
	struct Point pocetak = { 0, 0};
	struct Point  kraj = { 3, 4 };
	int mat[M][N] =
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
	{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	};

	

	int dist = BFS(mat, source, dest);

	/*if (dist != INT_MAX)
		cout << "Shortest Path is " << dist;
	else
		cout << "Shortest Path doesn't exist";*/

	return 0;

}