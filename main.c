#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

int main(void) {
    Tarefa *r;
    Fila fila;
    Pilha pilha;  
    int opcao, prioridade;
    char descricao[100];

    criar_fila(&fila);
    criar_pilha(&pilha);  

    do {
        printf("\n0 - Sair\n1 - inserir\n2 - remover\n3 - Imprimir\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                printf("Digite a descrição:");
                scanf("%s", descricao);
                fflush(stdin);
                inserir(&fila, descricao, &pilha);
                break;
            case 2:
                r = remover(&fila, &pilha);
                if (r) {
                    printf("Removido: %s\n", r->descricao);
                    free(r);
                }
                break;
            case 3:
                imprimir(&fila, &pilha); 
                break;
            default:
                if (opcao != 0)
                    printf("\nOpcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}