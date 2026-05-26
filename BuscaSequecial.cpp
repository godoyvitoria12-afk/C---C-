/*
	Name: BuscaSequecial.cpp
	Date: 26/05/26
	Description: Implementação da Busca Sequencial/linear, com método de ordenação Merge Sort
*/

#include <stdio.h>
#include <stdlib.h>

int buscaSequencial(int *V, int tam, int elem);
void mergeSort(int *V, int inicio, int fim);
void merge(int *V, int inicio, int meio, int fim);

int main(){ 
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int tam = sizeof(vet)/sizeof(int);
	int i, elem;
	
	puts("\nVetor original :");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
	
	mergeSort(vet, 0, tam - 1);
	
	puts("\n\nVetor ordenado por Merge Sort :");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
	
	// Solicita o elemento para a busca binária
	printf("\n\nDigite o elemento que deseja buscar: ");
	scanf("%d", &elem);
	
	// Corrigido a passagem do vetor (de *V para vet)
	int resultado = buscaSequencial(vet, tam, elem); 
	
	if(resultado == -1) {
		printf("Elemento %d nao foi encontrado no vetor.\n", elem);
	}

	return 0;
} //fim main

int buscaSequencial(int *V, int tam, int elem){
	int comp=0;
	for(int i = 0; i < tam; i++){
		comp++;
		if(elem == V[i]){
			printf("\nElemento localizado na %da posicao do vetor, no indice: %d\n", elem, i);
			printf("Localizado com %d comparacoes - Busca Sequencial", comp);
			exit(0);
		}
	}
	puts("Elemento localizado");
}

void mergeSort(int *V, int inicio, int fim){
	if (inicio < fim)
	{
		int meio = (inicio + fim) / 2;
		mergeSort(V, inicio, meio); //divide lado esquerdo
		mergeSort(V, meio + 1, fim); //divide lado direito
		merge(V, inicio, meio, fim); //juntando
	}
} 

//Func que junta os sub-vetores divididos pela func recursiva MergeSort
void merge(int *V, int inicio, int meio, int fim){
	int i, j, k;
	int tamEsq, tamDir; 
	
	tamEsq = meio - inicio + 1;
	tamDir = fim - meio; 
	
	int esquerda[tamEsq], direita[tamDir];
	
	for(i = 0; i < tamEsq; i++)
		esquerda[i] = V[inicio + i];
	
	for(j = 0; j < tamDir; j++)
		direita[j] = V[meio + 1 + j];

	i = 0;
	j = 0;
	k = inicio; 
	
	while(i < tamEsq && j < tamDir)
	{
		if(esquerda[i] < direita[j]){
			V[k] = esquerda[i];
			i++;
		}else{
			V[k] = direita[j];
			j++;
		}
		k++;
	}
	
	while(i < tamEsq)
	{
		V[k] = esquerda[i];
		i++;
		k++;
	}
	
	while(j < tamDir)
	{
		V[k] = direita[j];
		j++;
		k++;
	}
}
