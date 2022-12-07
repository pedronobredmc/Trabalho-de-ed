#include <stdio.h>
#include <stdlib.h>

//pilha
typedef struct pilha_no{
    char dado;
    struct pilha_no * prox;
} pilha_no;
//lista
typedef struct _lista_no{
    int dado;
    struct _lista_no * prox;
} lista_no;
//fila
typedef struct fila_no{
	struct fila_no * prox;
	int dado;
}fila_no;

typedef struct fila_t{
	fila_no * frente;
	fila_no * final;
}fila_t;

pilha_no * pilha_cria(void){
    pilha_no * cabeca = malloc(sizeof(pilha_no));
    cabeca -> prox = NULL;
    return cabeca;
}

void pilha_push(pilha_no * cabeca, char val){
	if(cabeca){
        pilha_no * novo_no = malloc(sizeof(pilha_no));
        novo_no -> dado = val;
        novo_no -> prox = cabeca -> prox;
        cabeca -> prox = novo_no;
	}
}

char pilha_pop(pilha_no * cabeca){
	if (cabeca){
		pilha_no * seguinte = cabeca -> prox;
	
		if (seguinte){
			char val = seguinte -> dado;
			cabeca -> prox = seguinte -> prox;
			free(seguinte);
			return val;
		}
	}
	return -1;
}

fila_t * fila_cria(void){
	fila_t * nova_fila = malloc(sizeof(fila_t));
	nova_fila -> frente = NULL;
	nova_fila -> final = NULL;
    return nova_fila;
}

void fila_put(fila_t * fila, int val){
	fila_no * novo_no = malloc(sizeof(fila_no));
	novo_no -> dado = val;
	novo_no -> prox = NULL;
	
	if (fila -> frente == NULL){
		fila -> frente = fila -> final = novo_no;
	}else{
		fila -> final -> prox = novo_no;
		fila -> final = novo_no;
	}	

}

lista_no * lista_cria(void){
    lista_no * cabeca = malloc(sizeof(lista_no));
    cabeca -> prox = NULL;
    return cabeca;
}

void lista_insere(lista_no * lista, int val){
    lista_no * novo_no = malloc(sizeof(lista_no));
    novo_no -> dado = val;
    novo_no -> prox = lista -> prox;
    lista -> prox = novo_no;
}

int main(){
    
}