#include <stdlib.h>

#ifndef INT_LIST_H
#define INT_LIST_H

typedef struct IntNode IntNode;

struct IntNode
{
	int number;
	IntNode* previous;
	IntNode* next;
};

typedef struct
{
	int size;
	IntNode* first;
	IntNode* last;
} IntList;

void insert(IntList* list, int number);

void free_list(IntList* list);

#endif
