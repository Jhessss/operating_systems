#include "int_list.h"

void insert(IntList* list, int number)
{
	// The New Node Memory Allocation
	IntNode* node = (IntNode*) malloc(sizeof(IntNode));
	node->number = number; // The data assigned
	if((*list).size == 0)
	{
		// The New Node is the First Node and Last Node
		node->previous = NULL;
		node->next = NULL;

		(*list).first = node;
		(*list).last = node;
	}
	else if(number < (*list).first->number)
	{
		// The New Node Data has Lesser value than the First
		// The New Node becomes the First node
		(*list).first->previous = node;

		node->previous = NULL;
		node->next = (*list).first;

		(*list).first = node;
	}
	else if(number > (*list).last->number)
	{
		// The New Node Data has Greater value than the Last
		// The New Node becomes the Last node
		(*list).last->next = node;

		node->previous = (*list).last;
		node->next = NULL;

		(*list).last = node;
	}
	else
	{
		// The New Node Data is between the First and the Last
		IntNode* comparable = (*list).first;
		while(comparable->next != NULL && number > comparable->number)
		{
			// Trace the exactly Node which the New Node Data is Lesser
			comparable = comparable->next;
		}

		// Insert New Node at the previous position of the Node
		(comparable->previous)->next = node;

		node->previous = comparable->previous;
		node->next = comparable;

		comparable->previous = node;
	}

	// Increment the list size
	(*list).size++;
}

void free_list(IntList* list)
{
	IntNode* next = (*list).first;
	while(next != NULL)
	{
		IntNode* node = next;
		next = node->next;

		free(node);
	}
}
