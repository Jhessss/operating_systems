#include "user_interface.h"

void show_intro()
{
	system("clear");
	printf("============[Trabalho 01 - Exercício 02]===========\n");
	printf("Nome: Jonathan Henrique Maia de Moraes - 12/0122553\n");
	printf("Disciplina: Fundamentos de Sistemas Operacionais\n");
	printf("Professor: Tiago Alves\n");
	printf("Universidade de Brasília - Campus FGA Gama - 2/2016\n");
	printf("=========================:=========================\n");
}

void show_list(IntList list, Flag flag)
{
	printf("====================[Resultado]====================\n");

	IntNode* node;
	int lines_number_quantity = 0;
	switch(flag)
	{
		case ASCENDING:
			printf("Ordem: Crescente\n");
			node = list.first;
			printf("Valores:\n");
			while(node != NULL) {
				if(lines_number_quantity > 10)
				{
					lines_number_quantity = 0;
					printf("\n");
				}
				else
				{
					lines_number_quantity++;
				}
				printf("[%d]", node->number);

				node = node->next;
			}
			break;

		case DESCENDING:
			printf("Ordem: Decrescente\n");
			node = list.last;
			printf("Valores:\n");
			while(node != NULL) {
				if(lines_number_quantity > 10)
				{
					lines_number_quantity = 0;
					printf("\n");
				}
				else
				{
					lines_number_quantity++;
				}
				printf("[%d]", node->number);

				node = node->previous;
			}
			break;
	}
	printf("\n=========================:=========================\n");
	printf("Pressione ENTER para encerrar o programa.\n");
	getchar();
	__fpurge(stdin);
}
