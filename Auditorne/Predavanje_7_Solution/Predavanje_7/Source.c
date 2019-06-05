# include "C:\Users\Korisnik\Desktop\SPA\SPA 07 - list\list\list.h"
# include <stdio.h>
void list_print(list_t lista)
{
	list_iterator_t  iter;
	for (iter = list_iterator(lista); list_iterator_is_valid(iter); list_iterator_next(iter))
	{
		printf("%d ", list_get(iter));
	}
	list_iterator_delete(iter);
	putchar('\n');

	
}
list_t list_shuffle(list_t list1, list_t list2)
{
	list_t rez;
	rez = list_new();
	list_iterator_t iter1, iter2;
	iter1 = list_iterator(list1);
	iter2 = list_iterator(list2);
	while (list_iterator_is_valid(iter1) || list_iterator_is_valid(iter2))
	{
		if (list_iterator_is_valid(iter1))
		{
			list_add(rez, list_get(iter1));
			list_iterator_next(iter1);
		}
		if (list_iterator_is_valid(iter2))
		{
			list_add(rez, list_get(iter2));
			list_iterator_next(iter2);
		}

	}
	list_iterator_delete(iter1);
	list_iterator_delete(iter2);

	return rez;
}
int main()
{
	list_t list1, list2, list3;

	list1 = list_new();
	list2 = list_new();
		
	list_add(list1, 9);
	list_add(list1, 8);
	list_add(list1, 7);
	list_print(list1);
	
	list_add(list2, 6);
	list_add(list2, 5);
	list_add(list2, 4);
	list_add(list2, 3);
	list_add(list2, 2);

	list_print(list2);
	
	list3 = list_shuffle(list1, list2);
	list_print(list3);


	list_delete(list3);
	list_delete(list1);
	list_delete(list2);

	getchar();
	getchar();
	return 0;
}