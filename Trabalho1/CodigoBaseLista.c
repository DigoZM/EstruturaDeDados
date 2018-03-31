#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct elemento{
	char dado;
	struct elemento * proximo;
}t_elemento;


typedef struct lista{
	t_elemento * primeiro;
	t_elemento * ultimo;
}t_lista;


typedef struct pilha{
	t_lista * l;
}t_pilha;

typedef struct fila{
  t_lista * l;
}t_fila;


/* INICIO LISTA */

t_lista * CriaLista(){
   t_lista * l = (t_lista *)malloc(sizeof(t_lista));
   l->primeiro = NULL;
   l->ultimo = NULL;
   return l;
}

int EstaVazia(t_lista * l){
    if(l->primeiro == NULL){
       return 1;
    }
    return 0;
}

void InsereInicio(char valor, t_lista * l){
    t_elemento * novoprimeiro = (t_elemento *)malloc(sizeof(t_elemento));
    novoprimeiro->dado = valor;
    novoprimeiro->proximo = l->primeiro;
    l->primeiro = novoprimeiro;
    if(l->ultimo == NULL){
        l->ultimo = novoprimeiro;
    }
}


void InsereFinal(char valor, t_lista * l){
   t_elemento * novoultimo = (t_elemento *)malloc(sizeof(t_elemento));
   novoultimo->dado = valor;
   novoultimo->proximo = NULL; 
   if(l->primeiro == NULL){
      l->primeiro = novoultimo;
   }else{
     l->ultimo->proximo = novoultimo;
   }
   l->ultimo = novoultimo;
}

int RemoveInicio(t_lista * l){
    if(EstaVazia(l)){
        return -1;
    }
    int tmp = l->primeiro->dado;
    t_elemento * removido = l->primeiro;
    l->primeiro = l->primeiro->proximo;
    free(removido);
    if(l->primeiro == NULL){
       l->ultimo = NULL;
    }
    return tmp;
}






/* FIM LISTA */


/* INICIO PILHA */

t_pilha * CriaPilha(){
   t_pilha * p =  (t_pilha *)malloc(sizeof(t_pilha));
   p->l = CriaLista();
   return p;
}

void Empilhar(char valor,t_pilha * p){
  InsereInicio(valor, p->l);
}


char Desempilhar(t_pilha * p){
  return RemoveInicio(p->l);
}


int EstaVaziaPilha(t_pilha * p){
    return EstaVazia(p->l);
}



/* FIM PILHA */

/* INICIO FILA */

t_fila * CriaFila(){
   t_fila * f =  (t_fila *)malloc(sizeof(t_fila));
   f->l = CriaLista();
   return f;
}


void Enfileirar(char valor, t_fila * f){
  InsereFinal(valor, f->l);
}


char Desenfileirar(t_fila * f){
  return RemoveInicio(f->l);
}


int EstaVaziaFila(t_fila * f){
    return EstaVazia(f->l);
}

/* FIM FILA */

