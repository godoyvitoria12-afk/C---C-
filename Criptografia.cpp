/*
	Name: Criptografia.cpp
	Author: Vitória Godoy
	Date: 01/09/25 10:19
	Description: Programa para criptografar dados pessoais
*/

#include <stdio.h>
#include <locale.h>

main()
{
setlocale (LC_ALL, "Portuguese");

char nome[40]; //vetor para nome completo
char docs[24]; //CPF+RG
char cpf[11];
char rg[10];
char crypto[65]; //vetor para a encriptação dos dados


puts("Programa para criptografar dados pessoais");
puts("===========================================");
printf("Nome Completo: "); gets(nome);
printf("\nInforme seu CPF: ");  gets(cpf);
printf("\nInforme seu RG: "); gets(rg);
//string = uma sequência de caracteres delimitadas por espaço em branco

puts("===========================================");
puts("Conteúdo dos vetores: ");
printf("\nNome:%s", nome); //formtação string %s (de string)     | printf("\nNome:%c", nome[8]); Pega a letra conforme o índice
printf("\ncpf:%s ", cpf);
printf("\nrg:%s  ", rg);


//imprimindo o vetor de nome caracter por caracter
puts("\nNome dentro do vetor:");
for(int i = 0; nome[i]!='\0'; i++)
printf("%c|",nome[i]); // %c serve para um único caractere
//imprimindo o vetor  cpf caracter por caracter
puts("\nCPF dentro do vetor:");
for(int i = 0; cpf[i]!='\0'; i++)
printf("%c|",cpf[i]); 


//imprimindo o vetor  rg caracter por caracter
puts("\nRG dentro do vetor:");
for(int i = 0; rg[i]!='\0'; i++)
printf("%c|",rg[i]);


//juntando o vetor cpf com o vetor rg
//marshalling juntando cpf com rg
int d = 0;
for(int i = 0; cpf[i] !='\0'; i++)
{
	docs[d] = cpf[i];
	docs[d+1]= rg[i];
	d=d+2;
}

puts("\nVetor Docs:");
for (int i=0; i< 24; i++)
printf("%c|", docs[i]);

//FAzendo o marshalling com os vetores:
//Nome e Docs (CPF e o RG)

int c = 0;


for(int i = 0; i<65; i++)
{
	
crypto[c] = nome [i];
crypto[c+1] = docs[i];	
c = c+2;
}


//imprimindo o vetor crypto caracter por caracter
puts("\nRG dentro do vetor Crypto:");
for(int i = 0; i < 65; i++)
printf("%c|",crypto[i]);

} //Fim do Programa

