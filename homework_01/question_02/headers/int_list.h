#include <stdlib.h>

#ifndef INT_LIST_H
#define INT_LIST_H

typedef struct
{
	int number,
	IntNode* previous,
	IntNode* next,
} IntNode;

typedef struct
{
	int size,
	IntNode* first,
	IntNode* last,
} IntList;

void insert(IntList* list, int number);

#endif
