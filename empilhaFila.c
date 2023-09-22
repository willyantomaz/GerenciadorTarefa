#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void criar_fila(Fila *fila){
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void inserir(Fila *fila, char descr[100], Pilha *pilha){
    Tarefa *novo = malloc(sizeof(Tarefa));
    if(novo){
        strcpy(novo->descricao, descr);
        novo->proximo = NULL;

        printf("\nQual a prioridade ? 0 baixa|1 alta");
        scanf("%d", &novo->prioridade);
        fflush(stdin);

        if (novo->prioridade == 1) {
            if(pilha->topo == NULL){
                pilha->topo = novo;
            } else {
                novo->proximo = pilha->topo;
                pilha->topo = novo;
            }
        } else {
            if(fila->prim == NULL){ 
                fila->prim = novo;
                fila->fim = novo;
            } else {
                fila->fim->proximo = novo;
                fila->fim = novo;
            }
        }

        fila->tam++;

    } else {
        printf("\nErro ao alocar memória. \n");
    }
}


Tarefa* remover(Fila *fila, Pilha *pilha){
    Tarefa *remove = NULL;

    if(pilha->topo){
        remove = pilha->topo;
        pilha->topo = remove->proximo;
    } else if(fila->prim){
        remove = fila->prim;
        fila->prim = remove->proximo;
        fila->tam--;
    } else {
        printf("\nSem tarefas.\n");
    }

    return remove;
}


void imprimir(Fila *fila, Pilha *pilha) {
    Tarefa *aux = pilha->topo;
    printf("Alta prioridade\n ");
    while (aux) {
        printf("%s ", aux->descricao);
        aux = aux->proximo;
    }

    aux = fila->prim;
    printf("\nBaixa prioridade \n ");
    while(aux){
        printf("%s ", aux->descricao);
        aux = aux->proximo;
    }
    
    
    printf("\nTodas as tarefas ordenada em prioridade\n");
    aux = pilha->topo;
    while (aux) {
        printf("%s ", aux->descricao);
        aux = aux->proximo;
    }

    aux = fila->prim;
    while(aux){
        printf("%s ", aux->descricao);
        aux = aux->proximo;
    }
    
    printf("\n");
}



void criar_pilha(Pilha *pilha) {
    pilha->topo = NULL;
}


