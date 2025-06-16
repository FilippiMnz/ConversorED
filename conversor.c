#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no* proximo;
}tipoNo;

typedef struct lista{
    tipoNo* topo;
}tipoLista;

tipoLista* criar(){
    tipoLista* lista = (tipoLista*) malloc(sizeof(tipoLista));
    if(lista == NULL){
        printf("Erro de alocacao");
        return NULL;
    }
    lista->topo = NULL;
    return lista;
}


void push(tipoLista* lista, int dado){
    tipoNo* novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    novoNo->dado = dado;
    novoNo->proximo = lista->topo;
    lista->topo = novoNo;
}
int pop(tipoLista* lista){
    if(lista->topo == NULL){
        return -1;
    }
    tipoNo* temporario = lista->topo;
    int retirado = temporario->dado;
    lista->topo = lista->topo->proximo;
    free(temporario);
    return retirado;
}


void Liberar(tipoLista* lista){
    while(lista->topo != NULL){
        pop(lista);
    }
    free(lista);
}

void converte(int numero, tipoLista* lista){
    if (numero == 0){
        push(lista, 0);
        return;
    }
    while(numero > 0){
        int resto = numero % 2;
        push(lista, resto);
        numero = numero /2;
    }
}

int main(){
    int numero;
    printf("Insira um Numero decimal para a conversao: ");
    scanf("%d",&numero);

    tipoLista* lista = criar();
    converte(numero, lista);

    printf("O numero em binario fica: ");
    while(lista->topo !=NULL){
        printf("%d", pop(lista));
    }
    printf("\n");
    Liberar(lista);
    return 0;
}
