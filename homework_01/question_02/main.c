#include <string.h>
#include "user_interface.h"

int main(int argc, char* argv[])
{
	show_intro();

	IntList list;
	list.size = 0;
	list.first = NULL;
	list.last = NULL;

	Flag flag = ASCENDING;

	int i;
	int number = 0;
	for(i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "-r") == 0)
		{
			flag = DESCENDING;
		}
		else if(strcmp(argv[i], "-d") == 0)
		{
			flag = ASCENDING;
		}
		else
		{
			number = atoi(argv[i]);
			if(number != 0)
			{
				insert(&list, number);
			}
		}
	}

	show_list(list, flag);
	free_list(&list);
	return 0;
}
