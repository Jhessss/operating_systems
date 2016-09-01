#include "user_interface.h"

void show_intro()
{
	system("clear");
	printf("============[Trabalho 01 - Exercício 03]===========\n");
	printf("Nome: Jonathan Henrique Maia de Moraes - 12/0122553\n");
	printf("Disciplina: Fundamentos de Sistemas Operacionais\n");
	printf("Professor: Tiago Alves\n");
	printf("Universidade de Brasília - Campus FGA Gama - 2/2016\n");
	printf("=========================:=========================\n");
}

void show_end_program()
{
	printf("\n=========================:=========================\n");
	printf("Pressione ENTER para encerrar o programa.\n");
	getchar();
	__fpurge(stdin);
}
