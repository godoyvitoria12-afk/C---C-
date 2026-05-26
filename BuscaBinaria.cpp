/*
	Name: BuscaBinaria.cpp
	Date: 26/05/26 10:58
	Description: ordenação Merge Sort seguida de Busca Binária.
*/

#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *V, int tam, int elem);
void mergeSort(int *V, int inicio, int fim);
void merge(int *V, int inicio, int meio, int fim);

int main(){ // Definido explicitamente como int
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int tam = sizeof(vet)/sizeof(int);
	int i, elem; // Declarada a variável elem
	
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
	int resultado = buscaBinaria(vet, tam, elem); 
	
	if(resultado == -1) {
		printf("Elemento %d nao foi encontrado no vetor.\n", elem);
	}

	return 0;
} //fim main

int buscaBinaria(int *V, int tam, int elem){
	int inicio = 0, fim, meio, comp = 0;
	fim = tam - 1;
	
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		comp++;
		
		if(V[meio] != elem){
			if(V[meio] > elem)
				fim = meio - 1;
			else 
				inicio = meio + 1;
		}
		else{
			printf("\nElemento localizado na %da posicao do vetor, no indice: %d\n", meio + 1, meio);
			printf("Localizado com %d comparacoes", comp);
			return meio; // Retorna o índice onde foi encontrado
		}
	}
	return -1;
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
