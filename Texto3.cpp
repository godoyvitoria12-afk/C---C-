/*
	Name: Texto3.cpp
	Author: Vit�ria Godoy
	Date: 08/09/25 10:42
	Description: Programa para demonstrar o uso de ponteiros comtratamento de strings
*/
#include <stdio.h> 
#include <string.h>

int tam = 0;
main()
{
	char nome[20];
	int tam = 0;
	printf("\nNome: "); gets(nome);
	
	tam = sizeof(nome) / sizeof(char);
	printf("\nTamanho do vetor: %d", tam);
	
	printf("\nNome digitado: %s", nome);
	
}
//fun��o para imprimir o nome ao contr�rio
void inverso(char *nome)
{
	 printf("\nNome ao contr�rio: ");
    for (int i = tam - 1; i >= 0; i--) {
        printf("%c", nome[i]);
    }
    printf("\n");
}
