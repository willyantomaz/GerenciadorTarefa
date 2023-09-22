#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct Tarefa{
    char descricao[100];
    int prioridade;
    struct Tarefa *proximo;
} Tarefa;

typedef struct Fila{
    Tarefa *prim;
    Tarefa *fim;
    int tam;
} Fila;

typedef struct Pilha{
    Tarefa *topo;
} Pilha;

void criar_fila(Fila *fila);
void inserir(Fila *fila, char descricao[100],Pilha *pilha);
Tarefa* remover(Fila *fila,Pilha *pilha);
void imprimir(Fila *fila, Pilha *pilha);
void criar_pilha(Pilha *pilha);

#endif