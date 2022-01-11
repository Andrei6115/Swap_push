#include "test.h"

void	print_circle(t_circle *a)
{
	t_node	*temp;

	temp = a->first;
	if (!temp)
	{
		printf("\n\tERROR\n");
		return ;
	}
	do
	{
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp && temp != a->first);
}

