#include "user_interface.h"

void show_intro()
{
	system("clear");
	printf("============[Trabalho 01 - Exercício 01]===========\n");
	printf("Nome: Jonathan Henrique Maia de Moraes - 12/0122553\n");
	printf("Disciplina: Fundamentos de Sistemas Operacionais\n");
	printf("Professor: Tiago Alves\n");
	printf("Universidade de Brasília - Campus FGA Gama - 2/2016\n");
	printf("=========================:=========================\n");
}

void show_main_options_instructions()
{
	printf("\n=================[Menu Principal]==================\n");
	printf("Este programa realiza as seguintes operacoes:\n");
	printf("(1) - Estabelece um triangulo atraves de 03 pontos;\n");
	printf("(2) - Informa o tamanho de cada lado do triangulo;\n");
	printf("(3) - Informa se os 03 pontos definem um triangulo\n");
	printf("(4) - Informa o perimetro do triangulo;\n");
	printf("(5) - Informa a area do triangulo;\n");
	printf("Para selecionar uma operacao, digite o numero que\n");
	printf("corresponde a operacao desejada. Para sair digite\n");
	printf("o valor (q).\n");
	printf("=========================:=========================\n");
}

MainOption get_main_options_input()
{
	printf("\n>> ");
	char input = getchar();
	__fpurge(stdin);
	MainOption main_input;

	switch (input) {
		case '1':
			main_input = SET_TRIANGLE;
			break;

		case '2':
			main_input = SHOW_SIZE_OF_SIDES;
			break;

		case '3':
			main_input = SHOW_EXISTENCE;
			break;

		case '4':
			main_input = SHOW_PERIMETER;
			break;

		case '5':
			main_input = SHOW_AREA;
			break;

		case 'q':
			main_input = EXIT;
			break;

		default:
			main_input = BAD_INPUT;
	}

	return main_input;
}

void show_main_options_output(MainOption option)
{
	switch (option) {
		case SET_TRIANGLE:
			printf("\n\nOperacao Identificada: Novo triangulo.\n");
			printf("Pressione ENTER para continuar.\n");
			getchar();
			__fpurge(stdin);
			system("clear");
			break;

		case SHOW_SIZE_OF_SIDES:
			printf("\n\nOperacao Identificada: Tamanho dos lados.\n");
			printf("Pressione ENTER para continuar.\n");
			getchar();
			__fpurge(stdin);
			system("clear");
			break;

		case SHOW_EXISTENCE:
			printf("\n\nOperacao Identificada: Descobrir Existencia.\n");
			printf("Pressione ENTER para continuar.\n");
			getchar();
			__fpurge(stdin);
			system("clear");
			break;

		case SHOW_PERIMETER:
			printf("\n\nOperacao Identificada: Calcular Perimetro.\n");
			printf("Pressione ENTER para continuar.\n");
			getchar();
			__fpurge(stdin);
			system("clear");
			break;

		case SHOW_AREA:
			printf("\n\nOperacao Identificada: Calcular Area.\n");
			printf("Pressione ENTER para continuar.\n");
			getchar();
			__fpurge(stdin);
			system("clear");
			break;

		case EXIT:
			printf("\n\nOperacao Identificada: Sair do programa.\n");
			printf("Pressione ENTER para continuar.\n");
			getchar();
			__fpurge(stdin);
			system("clear");
			break;

		default:
			printf("\n\nOperacao Nao Identificada!\n");
			printf("Pressione ENTER para retornar ao menu principal.\n");
			getchar();
			__fpurge(stdin);
	}
}

void show_set_triangle_instructions()
{
	printf("\n=================[Novo Triangulo]=================\n");
	printf("Para criar um novo triangulo se faz necessario:\n");
	printf("Ponto a:\n");
	printf("\tCoordenadas x e y (Dominio: Inteiros)\n");
	printf("Ponto b:\n");
	printf("\tCoordenadas x e y (Dominio: Inteiros)\n");
	printf("Ponto c:\n");
	printf("\tCoordenadas x e y (Dominio: Inteiros)\n");
	printf("Insira as 03 coordenadas em uma unica linha, com um\n");
	printf("espaco entre cada valor.\n");
	printf("=========================:=========================\n");
}

CartesianTriangle get_triangle_input()
{
	printf("\n>> ");
	CartesianTriangle triangle;
	if(scanf("%lld %lld %lld %lld %lld %lld", &triangle.a.x, &triangle.a.y, &triangle.b.x,
			&triangle.b.y, &triangle.c.x, &triangle.c.y) != 6)
	{
		triangle.a.x = triangle.a.y = triangle.b.x = triangle.b.y = triangle.c.x
				= triangle.c.y = 0.0;
	}

	return triangle;
}

void show_set_triangle_output(CartesianTriangle triangle)
{
	printf("\n====================[Resultado]===================\n");
	printf("Ponto a:\n");
	printf("\tx = %lld\n", triangle.a.x);
	printf("\ty = %lld\n", triangle.a.y);
	printf("Ponto b:\n");
	printf("\tx = %lld\n", triangle.b.x);
	printf("\ty = %lld\n", triangle.b.y);
	printf("Ponto c:\n");
	printf("\tx = %lld\n", triangle.c.x);
	printf("\ty = %lld\n", triangle.c.y);
	printf("Se os valores das coordenadas sao todos 0,\n");
	printf("significa que ou foi informado os valores 0, ou\n");
	printf("houve alguma falha ao receber os valores.\n");
	printf("=========================:=========================\n");
	printf("Pressione ENTER para retornar ao menu principal.\n");
	getchar();
	__fpurge(stdin);
	system("clear");
}

void show_size_of_sides_instructions()
{
	printf("\n================[Tamanho dos Lados]===============\n");
	printf("Um triangulo possui tres lados: AB, BC e CA\n");
	printf("O Teorema de Pitagoras sera utilizado para descobrir\n");
	printf("o tamanho de cada lado:\n");
	printf("raiz_quadrada{(delta_x)^2 + (delta_y)^2}\n");
	printf("=========================:=========================\n");
	printf("Pressione ENTER para visualizar o resultado.\n");
	getchar();
	__fpurge(stdin);
}

void show_size_of_sides_output(double* size_of_sides)
{
	printf("\n====================[Resultado]===================\n");
	printf("Tamanho do Lado AB: %.2lf\n", size_of_sides[0]);
	printf("Tamanho do Lado BC: %.2lf\n", size_of_sides[1]);
	printf("Tamanho do Lado CA: %.2lf\n", size_of_sides[2]);
	printf("Se um dos valores informados for 0, significa que\n");
	printf("tal par de pontos esta na mesma posicao, logo, os\n");
	printf("pontos nao definem um triangulo.\n");
	printf("=========================:=========================\n");
	printf("Pressione ENTER para retornar ao menu principal.\n");
	getchar();
	__fpurge(stdin);
	system("clear");
}


void show_existence_instructions()
{
	printf("\n==============[Existencia do Triangulo]============\n");
	printf("Para um triangulo existir atraves de 03 pontos, se\n");
	printf("faz necessario:\n");
	printf("i. Os 03 pontos assumirem posicoes distintas, e;\n");
	printf("ii. Estar em conformidade com o Teorema da\n");
	printf("Desigualdade Triangular de Euclides:\n");
	printf("A soma de qualquer dois lados do triangulo deve ser\n");
	printf("maior que o terceiro lado do triangulo e o\n");
	printf("modulo da subtracao destes dois lados deve ser\n");
	printf("menor que o terceiro lado do triangulo.\n");
	printf("=========================:=========================\n");
	printf("Pressione ENTER para visualizar o resultado.\n");
	getchar();
	__fpurge(stdin);
}

void show_existence_output(Boolean exists)
{
	printf("\n====================[Resultado]===================\n");
	if(exists == true)
	{
		printf("Os pontos definem um triangulo!\n");
	}
	else
	{
		printf("Os pontos nao definem um triangulo.\n");
	}
	printf("=========================:=========================\n");
	printf("Pressione ENTER para retornar ao menu principal.\n");
	getchar();
	__fpurge(stdin);
	system("clear");
}


void show_perimeter_instructions()
{
	printf("\n==============[Perimetro do Triangulo]============\n");
	printf("Para calcular o perimetro de um triangulo, basta\n");
	printf("somar o tamanho de cada um dos 03 lados do mesmo.\n");
	printf("=========================:=========================\n");
	printf("Pressione ENTER para visualizar o resultado.\n");
	getchar();
	__fpurge(stdin);
}

void show_perimeter_output(double perimeter)
{
	printf("\n====================[Resultado]===================\n");
	printf("Perimetro do Triangulo: %.2lf\n", perimeter);
	printf("Se o valor informado for 0.00, significa que os\n");
	printf("03 pontos nao definem um triangulo.\n");
	printf("=========================:=========================\n");
	printf("Pressione ENTER para retornar ao menu principal.\n");
	getchar();
	__fpurge(stdin);
	system("clear");
}


void show_area_instructions()
{
	printf("\n==================[Area dos Lados]=================\n");
	printf("Para calcular a area de um triangulo com 03 pontos\n");
	printf("distintos, pode-se utilizar a Formula de Heron:\n");
	printf("i. Descubra o valor de S, que pode ser definido\n");
	printf("como a metade do perimetro do triangulo.\n");
	printf("ii. Aplique a formula aos lados do triangulo:\n");
	printf("raiz_quadrada{S(S-AB)(S-BC)(S-CA)}\n");
	printf("=========================:=========================\n");
	printf("Pressione ENTER para visualizar o resultado.\n");
	getchar();
	__fpurge(stdin);
}

void show_area_output(double area)
{
	printf("\n====================[Resultado]===================\n");
	printf("Area do Triangulo: %.2lf\n", area);
	printf("Se o valor informado for 0.00, significa que os\n");
	printf("03 pontos nao definem um triangulo.\n");
	printf("=========================:=========================\n");
	printf("Pressione ENTER para retornar ao menu principal.\n");
	getchar();
	__fpurge(stdin);
	system("clear");
}
