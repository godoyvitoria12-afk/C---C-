/*
	Name: Troca.cpp
	Author: Vitória Godoy
	Date: 08/09/25 08:34
	Description: Programa para realizar a troca de valores entre duas variaveis
*/
#include <stdio.h>

void trocar(int *, int *);// asterisco: passar referencia
main()
{
	int a, b, x;
	a = b = x = 0;
	
	printf("Digite o valor de A: "); scanf("%d", &a);
	printf("Digite o valor de B: "); scanf("%d", &b);
	
	trocar(&a, &b);
	
	printf("A: %d\n", a);
	printf("B: %d\n", b);
}

void trocar(int *a, int *b)// função para trocar os valores entre duas variaveis com passagem de parametro por refencia

{
	/*int x = 0; 
	x=*a;
	*a=*b;
	*b=x;*/
	
	*a = *a * *b; // pode ser trocado por +
	*b = *a / *b; // pode ser trocado por -
	*a = *a / *b;
}
