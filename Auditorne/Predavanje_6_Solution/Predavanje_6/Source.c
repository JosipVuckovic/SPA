#include <stdio.h>
#include "C:\Users\Korisnik\Desktop\SPA\SPA 06 - stack\stack\stack.h"
#include "C:\Users\Korisnik\Desktop\SPA\SPA 06 - queue\queue\queue.h"

void ispis_stoga(stack_t s)
{
	stack_t temp = stack_new();
	while (!stack_is_empty(s))
	{
		stack_element_t e = stack_pop(s);
		stack_push(temp, e);
	}
	while (!stack_is_empty(temp))
	{
		stack_element_t e = stack_pop(temp);
		printf("%d", e);
		stack_push(s, e);
	}

}

int main()
{
	stack_t parni;
	stack_t pomocni;
	parni = stack_new();
	pomocni = stack_new();
	stack_push(parni, 4);
	stack_push(parni,2);
	stack_push(parni, 8);
	printf("Na vrhu stoga je: %d", stack_top(parni));
	
	stack_delete(parni);
	getchar();
	getchar();
	
	return 0;
}