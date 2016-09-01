#include <string.h>
#include "user_interface.h"

int main()
{
	show_intro();

	// [1]
	double number1 = 7.3, number2;
	char s1[100], s2[100];

	// [2]
	double* dPtr;

	// [3]
	dPtr = &number1;

	// [4]
	printf("[4]\t[dPtr(number1):\t%lf\t]\n", *dPtr);

	// [5]
	number2 = *dPtr;

	// [6]
	printf("[6]\t[number2:\t%lf\t]\n", number2);

	// [7]
	printf("[7]\t[addr(number1):\t%p\t]\n", &number1);

	// [8]
	printf("[8]\t[addr(dPtr):\t%p\t]\n", &dPtr);

	// [9]
	printf("[9]\t[Nao. dPtr tem HEX-8 acrescido\t]\n");
	printf("\t[ao valor do end. de number1.\t]\n");

	// [10]
	scanf("%s", s1);
	strcpy(s2, s1);
	printf("[10]\t[strcmp(s1,s2):\t%d\t\t]\n", strcmp(s1,s2));

	// [11]
	printf("[11]\t[strcat(s1,s2):\t%s\t]\n", strcat(s1,s2));

	// [12]
	printf("[12]\t[Pode. Caso ultrapasse o buffer.]\n");

	// [13]
	printf("[13]\t[strlen(s1):\t%zd\t\t]\n", strlen(s1));
	return 0;
}
