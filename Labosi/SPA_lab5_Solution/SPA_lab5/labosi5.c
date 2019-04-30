#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#include "book.h"
#include "trie.h"

struct node {
	struct book knjiga;
	struct node *left;
	struct node *right;
};
struct book *books;

struct node *bst_add_recursive(struct node **root, struct book knjiga) {

	if (*root == NULL) {
		*root = malloc(sizeof(struct node));
		(*root)->knjiga = knjiga ;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return *root;
	}
	else if ((*root)->knjiga.id > knjiga.id)
		return bst_add_recursive(&(*root)->left, knjiga);
	else if ((*root)->knjiga.id < knjiga.id)
		return bst_add_recursive(&(*root)->right, knjiga);
	else
		/* duplikat: (*root)->value == value */
		return *root;

}
void tree_print_inorder(struct node *root) {
	
	if (root == NULL)
		return;
	
	tree_print_inorder(root->left);		/* inorder poretkom ispisi lijevo podstablo */
	printf("%d. %s - %d kn \n", root->knjiga.id, root->knjiga.name, root->knjiga.price);			/* ispisi trenutni cvor */
	tree_print_inorder(root->right);	/* inorder poretkom ispisi desno podstablo */

}


void tree_free(struct node *root) {

	if (root == NULL)
		return;

	tree_free(root->left);	/* oslobodi memoriju za sve cvorove iz lijevog podstabla */
	tree_free(root->right);	/* oslobodi memoriju za sve cvorove iz desnog podstabla */
	free(root);				/* oslobodi memoriju za trenutni cvor */

}

int main() {
	
	trie_t root;
	struct node *root_id=NULL;
	//struct book *books;
	unsigned num_books;
	char book_name[BOOK_NAME_MAX_LEN + 1];
	unsigned i;

	/* ucitavanje knjiga iz datoteke */
	if (load_books("knjige.csv", &books, &num_books))
		return -1;

	/* korijen triea, pocetak svih rijeci, uvijek alociran */
	root = trie_new_node();

	for (i = 0; i < num_books; i++) {
		printf("%d %s %d\n", books[i].id, books[i].name, books[i].price);
	}
	putchar('\n');
	/* ubacivanje knjiga u trie */
	for (i = 0; i < num_books; i++)
		trie_insert_word(root, books[i].name);
	/*knjige id insert BST*/
	for (i = 0; i < num_books; i++)
		bst_add_recursive(&root_id, books[i]);

	printf("Inorder:    ");
	tree_print_inorder(root_id);
	putchar('\n');
	tree_free(root_id);
	/* knjige su u trieu, ne trebaju nam vise kao zaseban niz */
	free(books);

	/* pretrazivanje knjiga */
	while (1) {
		int search_result = 0;

		printf("\nUpisi ime knjige (prazan string za izlaz iz programa): ");
		gets(book_name);

		if (!strcmp(book_name, ""))
			break;

		search_result = trie_search_word(root, book_name);
		printf("'%s' %s ispravan naziv knjige.\n", book_name, search_result ? "je" : "nije");
		if (!search_result) {
			printf("Moguci kandidati su:\n");
			trie_print_prefixed_word(root, book_name);
		}
	}
	
	return 0;
}
