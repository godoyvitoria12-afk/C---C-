/*
	Name: códIndiano.cpp
	Author: Vitória Godoy
	Date: 18/08/25 - 25/08
	Description: Program para demonstrar o emprego as diversas formas de invocar uma funções
*/

#include <stdio.h>
int lerNum();
int multiplicar (int,int);
int somar(int,int);
int subtrair(int,int);
float dividir(int,int);
int potencializar (int,int);

main()
{
	//printf("\nA soma eh: %d", somar(lerNum(), lerNum()));
	//printf("\nA multiplicacao eh: %d", multiplicar(lerNum(), lerNum()));
	//printf("\nA subtrcao de eh: %d", subtrair(lerNum(), lerNum()));
	//printf("\nA divisao de eh: %.2f", dividir(lerNum(), lerNum()));
	printf("\nA potenciacao de eh: %d", potencializar(lerNum(), lerNum()));

}// fim main

int somar(int x, int y){
	return x+y;
}

int multiplicar (int xis, int ypslon){
	return xis * ypslon;
}

int subtrair(int x, int y){
	return x-y;
}

float dividir(int x, int y){
	return (float)y/x;
}

int lerNum(){
	int num = 0;
	printf("\nDigite um numero: ");
	scanf ("%d",&num);
	return num;
}

int potencializar (int base, int expoente)
{
	int result = 1;
	for(int i=0; i< expoente; i++)
		result = result*base;
	return result;
}
