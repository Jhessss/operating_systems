#include <stdio.h>
#include "int_list.h"

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

typedef enum
{
	DESCENDING,
	ASCENDING
} Flag;

void show_intro();

void show_list(IntList list, Flag flag);

#endif // USER_INTERFACE_H
