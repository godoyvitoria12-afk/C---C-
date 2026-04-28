/*
	Name: MergeSort.cpp
	Author: Vitória Godoy
	Date: 28/04/26 11:20
	Description: Implementação do algoritmo merge sort
*/

#include <stdio.h>

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

main(){
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int tam = sizeof(vet)/sizeof(int);
	int i;
	
	puts("\nVetor original :");
	for(i =0; i< tam; i++)
	printf("%d|", vet[i]);
	
	mergeSort(vet,0, tam-1);
	
	puts ("\nVetor oredenado por Merge Sort :");
	for(i =0; i<tam; i++)
	printf("%d|", vet[i]);
} //fim main

void mergeSort (int *V, int inicio, int fim){
	if (inicio<fim)
	{
		int meio= (inicio + fim) /2;
		mergeSort(V, inicio, meio); //divide lado direito
		mergeSort(V, meio +1, fim); //divide lado esquerdo
		merge(V, inicio, meio, fim); //juntando
		
	}//fim if
	
} //fim void mergeSort

//Func que junta os sub-vetores divididos pela func recursiva MergeSort
void merge(int *V, int inicio, int meio, int fim){
	
	int i,j,k;
	int tamEsq, tamDir; 
	
	tamEsq = meio - inicio + 1;
	tamDir = fim - meio; // corrigido
	
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
