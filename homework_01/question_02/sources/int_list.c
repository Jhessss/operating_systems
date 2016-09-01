#include "int_list.h"

void insert(IntList* list, int number)
{
	IntNode* node = (IntNode*) malloc(sizeof(IntNode));
	node->number = number;

	if(list->size == 0)
	{
		node->previous = NULL;
		node->next = NULL;

		list->first = node;
		list->last = node;
	}
	else if(number < list->first->number)
	{
		(list->first)->previous = node;

		node->previous = NULL;
		node->next = list->first;

		list->first = node;
	}
	else if(number > list->last->number)
	{
		(list->last)->next = node;

		node->previous = list->last;
		node->next = NULL;

		list->last = node;
	}
	else
	{
		IntNode* comparable = list->first;
		while(comparable->next != NULL && number > comparable->number)
		{
			comparable = comparable->next;
		}

		// Last
		if(number > comparable->number)
		{
			comparable->next = node;

			node->previous = comparable;
			node->next = NULL;

			list->last = node;
		}
		else
		{
			(comparable->previous)->next = node;

			node->previous = comparable->previous;
			node->next = comparable;

			comparable->previous = node;
		}
	}

	list->size++;
}
