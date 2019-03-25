#include <stdlib.h>
#include <stdio.h>
//struct node
//{
//	int value;
//	struct node *next;
//};
//
//int main ()
//{
//	struct node *head = NULL;
//	struct node *prvi = malloc(sizeof(struct node));
//	struct node *drugi = malloc(sizeof(struct node));
//	struct node *treci = malloc(sizeof(struct node));
//	head = prvi;
//	prvi->value = 4;
//	prvi->next = drugi;
//	drugi->value = 17;
//	drugi->next = treci;
//	treci->value = 33;
//	treci->next = NULL;
//	while (head != NULL)
//	{
//		printf("%d ", head->value);
//		head = head->next;
//	}
//
//	free(prvi);
//	free(drugi);
//	free(treci);
//	getchar();
//	getchar();
//	return 0;
//
//
//}
//
//#include <stdio.h>
//#include <stdlib.h>

/* implementacija jednostruko povezane liste */

/* struktura za opis jednog clana liste */
//struct node {
//	double value;		/* vrijednost pohranjena u clanu */
//	struct node *next;	/* pokazivac na iduci clan */
//};
//
///* dodaje novu vrijednost na pocetak liste */
//void add_first(struct node **phead, double value) {
//
//	struct node *node;
//
//	node = malloc(sizeof(struct node));
//
//	node->value = value;
//	node->next = *phead;
//
//	*phead = node;
//
//}
//
///* dodaje novu vrijednost na kraj liste */
//void add_last(struct node **phead, double value) {
//
//	while (*phead != NULL)
//		phead = &(*phead)->next;
//
//	*phead = malloc(sizeof(struct node));
//
//	(*phead)->value = value;
//	(*phead)->next = NULL;
//
//}
//
//void add_after_smallest(struct node *head, double value)
//{
//	struct node *najmanji, *novi;
//	najmanji = malloc(sizeof(struct node));
//	najmanji = head;
//	head = head->next;
//	novi = malloc(sizeof(struct node));
//	while (head != NULL)
//	{
//		if (najmanji->value > head->value)
//		{
//			najmanji = head;
//		}
//		head = head->next;
//	}
//	novi->value = value;
//	novi->next = najmanji->next;
//	najmanji->next = novi;
//}
//
///* ispisuje sve clanove liste */
//void print_all(struct node *head) {
//	while (head != NULL) {
//		printf("%lf\n", head->value);
//		head = head->next;
//	}
//}
//
///* prazni listu i oslobadja alociranu memoriju */
//void clear(struct node *head) {
//
//	while (head != NULL) {
//		struct node *temp = head;
//		head = head->next;
//		free(temp);
//	}
//
//}
//
///* test */
//int main() {
//
//	/* pokazivac na prvi clan liste */
//	struct node *head = NULL;
//
//	add_last(&head, 3.14);
//	add_last(&head, 4.71);
//	add_first(&head, 9.81);
//	add_after_smallest(head, 6.54);
//	print_all(head);
//
//	clear(head);
//	getchar();
//	getchar();
//
//	return 0;
//
//}
/* implementacija dvostruko povezane liste */

/* struktura za opis jednog clana liste */
struct node {
	double value;			/* vrijednost pohranjena u clanu */
	struct node *next;		/* pokazivac na iduci clan */
	struct node *previous;	/* pokazivac na prethodni clan */
};

/* dodaje novu vrijednost na pocetak liste */
void add_first(struct node **phead, struct node **ptail, double value) {

	struct node *node;

	node = malloc(sizeof(struct node));

	node->value = value;
	node->next = *phead;
	node->previous = NULL;

	if (*phead != NULL)
		(*phead)->previous = node;

	if (*ptail == NULL)
		*ptail = node;

	*phead = node;

}

/* dodaje novu vrijednost na kraj liste */
void add_last(struct node **phead, struct node **ptail, double value) {

	struct node *node;

	node = malloc(sizeof(struct node));

	node->value = value;
	node->next = NULL;
	node->previous = *ptail;

	if (*ptail != NULL)
		(*ptail)->next = node;

	if (*phead == NULL)
		*phead = node;

	*ptail = node;

}

/* ispisuje sve clanove liste */
void print_all(struct node *head) {
	while (head != NULL) {
		printf("%lf\n", head->value);
		head = head->next;
	}
	putchar('\n');
}

/* ispisuje sve clanove liste, od zadnjeg prema prvom */
void print_reverse(struct node *tail) {
	while (tail != NULL) {
		printf("%lf\n", tail->value);
		tail = tail->previous;
	}
	putchar('\n');
}

/* prazni listu i oslobadja alociranu memoriju */
void clear(struct node *head) {

	while (head != NULL) {
		struct node *temp = head;
		head = head->next;
		free(temp);
	}

}

void add_n(struct node **phead, struct node **ptail, double value, int n)
{
	struct node *novi;
	novi = malloc(sizeof(struct node));
	while (n-- && *phead != NULL )
	{
		phead = &(*phead)->next;
	}
	novi->value = value;
	novi->next = *phead;

	if (*phead)
	{
		novi->previous = (*phead)->previous;
		(*phead)->previous = novi;
	}
	else
	{
		novi->previous = *ptail;
		*ptail = novi;
	}
	*phead = novi;
}

/* test */
int main() {

	struct node *head = NULL;	/* pokazivac na prvi clan liste */
	struct node *tail = NULL;	/* pokazivac na zadnji clan liste */

	add_last(&head, &tail, 3.14);
	add_last(&head, &tail, 2.71);
	add_first(&head, &tail, 9.81);
	add_n(&head, &tail, 5.60, 2);
	print_all(head);
	print_reverse(tail);

	clear(head);
	getchar();
	getchar();
	return 0;

}
