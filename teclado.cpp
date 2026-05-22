/*
	Name: teclado.cpp
	Date: 22/05/26 16:20
	Description: programa para converter letras em numeros
*/
#include <stdio.h>
#include <ctype.h> // Incluído para usar o toupper

int main(){
	
    int n = 0; // Removido o i=0 daqui
    char letra[30]; 

    // Deixamos apenas um scanf para a quantidade de palavras
    scanf("%d", &n); 

    for(int i = 0; i < n; i++){
        
        scanf("%s", letra);
        
        for(int j = 0; letra[j] != '\0'; j++) {
            
            // Garante que a letra vira maiúscula antes de testar nos ifs
            letra[j] = toupper(letra[j]);
            
            if (letra[j] >= 'A' && letra[j] <= 'C') {
                printf("2");
            } 
            else if (letra[j] >= 'D' && letra[j] <= 'F') {
                printf("3");
            } 
            else if (letra[j] >= 'G' && letra[j] <= 'I') {
                printf("4");
            }
            else if (letra[j] >= 'J' && letra[j] <= 'L') {
                printf("5");
            } 
            else if (letra[j] >= 'M' && letra[j] <= 'O') {
                printf("6");
            } 
            else if (letra[j] >= 'P' && letra[j] <= 'S') { 
                printf("7");
            } 
            else if (letra[j] >= 'T' && letra[j] <= 'V') {
                printf("8");
            } 
            else if (letra[j] >= 'W' && letra[j] <= 'Z') { 
                printf("9");
            }
            
        } 
        
        // Pula a linha ao terminar a palavra
        printf("\n");

    } // Fim do loop principal

    return 0;
}
