/*
	Name: ListasEncadeadas.cpp
	Author: Vitória Godoy
	Date: 17/03/26 09:55
  Description: Implementação da estrutura de dados Lista encadeada
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cores ANSI
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define WHITE   "\x1b[37m"
#define BLACK   "\x1b[30m"
#define BG_BLUE    "\x1b[44m"

typedef struct No {
    char nome[20];
    int idade;
    struct No *prox;
} No;

int tam = 0;

// Protótipos
void iniciarLista(No *Lista);
int vazia(No *Lista);
No *alocaMemoria();
void insereFim(No *Lista);
void insereInicio(No *Lista);
void exibirLista(No *Lista);
void retiraFim(No *Lista);
void retiraInicio(No *Lista);
void tratarOpcao(No *Lista, int opc);
int menu();

int main() {
    // No nosso caso, o "Lista" é o nó sentinela (head)
    No *Lista = (No *) malloc(sizeof(No));
    if (!Lista) {
        puts("Sem memoria");
        exit(1);
    }
    
    iniciarLista(Lista);

    int opc = 0;
    do {
        opc = menu();
        tratarOpcao(Lista, opc);
        if(opc != 7) {
            printf("\nPressione qualquer tecla para continuar...");
            getchar(); getchar(); // Pausa simples
        }
    } while(opc != 7);

    return 0;
}

int menu() {
    int opc;
    system("cls || clear"); // Limpa a tela
    printf(MAGENTA "=== MENU LISTA ENCADEADA ===\n" RESET);
    printf("1 - Zerar a Lista\n");
    printf("2 - Exibir a Lista\n");
    printf("3 - Inserir no FIM\n");
    printf("4 - Inserir no INICIO\n");
    printf("5 - Excluir do FIM\n");
    printf("6 - Excluir do INICIO\n");
    printf("7 - SAIR\n");
    printf("======================\nEscolha: ");
    scanf("%d", &opc);
    return opc;
}

void iniciarLista(No *Lista) {
    Lista->prox = NULL;
    tam = 0;
}

int vazia(No *Lista) {
    return (Lista->prox == NULL);
}

No *alocaMemoria() {
    No *novo = (No *) malloc(sizeof(No));
    if (!novo) exit(1);
    printf("Nome: ");
    scanf("%s", novo->nome);
    printf("Idade: ");
    scanf("%d", &novo->idade);
    novo->prox = NULL;
    return novo;
}

void inserirInicio(No *Lista){
	No *novo = alocaMemoria();
	No *head = Lista->prox;
	Lista->prox = novo;
	novo->prox = head;
	puts("No inserido no INICIO da lista!!");
}

void insereFim(No *Lista) {
    No *novo = alocaMemoria();
    No *tmp = Lista;
    while (tmp->prox != NULL) tmp = tmp->prox;
    tmp->prox = novo;
    tam++;
}

void insereInicio(No *Lista) {
    No *novo = alocaMemoria();
    novo->prox = Lista->prox;
    Lista->prox = novo;
    tam++;
}

void retiraInicio(No *Lista) {
    if (vazia(Lista)) {
        printf(RED "Lista ja esta vazia!\n" RESET);
        return;
    }
    No *lixo = Lista->prox;
    Lista->prox = lixo->prox;
    free(lixo);
    tam--;
}

void retiraFim(No *Lista) {
    if (vazia(Lista)) {
        printf(RED "Lista ja esta vazia!\n" RESET);
        return;
    }
    No *ant = Lista;
    No *atual = Lista->prox;
    while (atual->prox != NULL) {
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = NULL;
    free(atual);
    tam--;
}

void exibirLista(No *Lista) {
    if (vazia(Lista)) {
        puts(RED "\n====> Lista VAZIA!" RESET);
    } else {
        No *tmp = Lista->prox;
        printf("\n--- LISTA (Tam: %d) ---\n", tam);
        while (tmp != NULL) {
            // AQUI MUDAMOS AS CORES
            printf("[" CYAN "%s" RESET "|%d anos]", tmp->nome, tmp->idade);
            
            if(tmp->prox != NULL)
                printf(YELLOW " -> " RESET); // Seta colorida
            
            tmp = tmp->prox;
        }
        printf(BLUE " -> NULL\n" RESET);
    }
}

void tratarOpcao(No *Lista, int opc) {
    switch(opc) {
        case 1: iniciarLista(Lista); break;
        case 2: exibirLista(Lista); break;
        case 3: insereFim(Lista); break;
        case 4: insereInicio(Lista); break;
        case 5: retiraFim(Lista); break;
        case 6: retiraInicio(Lista); break;
        case 7: printf("Saindo...\n"); break;
        default: puts("Opção inválida!");
    }
}
