#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro{
    int numero_matricula;
    char nome[100];
    struct registro *prox;
};
typedef struct registro regFunc;

void Novo(regFunc **N, int mat, char name[]){
    regFunc *aux;

    aux = (regFunc*)malloc(sizeof(regFunc));

    aux -> numero_matricula = mat;
    int tam = strlen(name);
    for (int i=0; i<tam;i++){
        aux -> nome[i] = name[i];
    }
    aux -> nome[tam] = '\0';
    aux -> prox = *N;
    *N = aux;
} 

void Leitura(regFunc *N){
    while(N){
        printf("Matricula: %d\n", N->numero_matricula);
        printf("Nome: %s\n\n", N->nome);
        N = N -> prox;
    }
}

regFunc* Remove(regFunc **N, int m){ //retorna um ponteiro para a struct
    regFunc *aux, *remove = NULL;

    if(*N){
        if((*N)->numero_matricula == m){
            remove = *N;
            *N = remove -> prox;
        } else{
            aux = *N;
            while(aux -> prox && aux ->prox->numero_matricula != m){
                aux = aux->prox;
            } if(aux -> prox){
                remove = aux -> prox;
                aux -> prox = remove -> prox;
            }
        }
    }
    return remove;
}

int main(){
    regFunc *listaRFunc, *remover; //representação do struct
    listaRFunc = NULL;
    int num, opcao;
    char nom[100];
    for(int i=0;i<10;i++){
        printf("Escreva o nome do funconario:");
        scanf("%s", nom);
        printf("Escreva o numero de matricula: ");
        scanf("%d", &num);
        Novo(&listaRFunc, num, nom);
    }
        

        printf("\nMENU\n\n0 - lista de funcionarios\n 1 - remover funcionario\n 2 - adicionar funcionario\n");
        scanf("%d", &opcao);
    while(opcao == 1 ||opcao == 0 || opcao == 2){
        switch (opcao)
        {
        case 0:
            Leitura(listaRFunc);
            return opcao;
        case 1:
            printf("Matricula: ");
            scanf("%d", &num);
            remover = Remove(&listaRFunc, num);
            if(remover){
                printf("removendo: %d\n", remover -> numero_matricula);
                free(remover);
                printf("\nLISTA ATUALIZADA\n");
                Leitura(listaRFunc);
            }
            return opcao;
        
        default:
            break;
        }
    }

    return 0;

}
