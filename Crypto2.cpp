/*
	Name: Crypto2.cpp
	Author: Vit�ria Godoy
	Date: 08/09/25 07:59
	Description: Programa para cifrar uma mensagem realizam o "merge"
*/
#include <stdio.h>

// sess�o de prototipa��o
void merge(char[], char[]);
int i, j; // variaveis globais
char crypto[40]; //jun��o dos dois vetores

int main()
{
	i = j = 0;
	char nome[20]; //nome completo
	char docs[20];// cpf e rg
	
	printf("Insira seu nome completo: "); gets(nome);
	printf("Informe seu CPF e RG: "); gets(docs);
	
	merge(nome, docs);//invoke da fun��o
	
	puts("\ntexto cifrado:");
	for(j=0; crypto[j] != '\0'; j++)
		printf("%c", crypto[j]);

	
	
	return 0;
}

void merge(char nome[], char docs[]) // MERGE: fun��o para realizar a mistura entre os dois vetores
{
	for(i=0; nome[i] != '\0'; i++){
		crypto[j] = nome[i];
		crypto[j+1] = docs[i];
		j = j+2;
	}
}
