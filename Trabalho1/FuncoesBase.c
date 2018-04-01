#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define NUMERO 2
#define CARACTER 3

//INICIO DECLARAÇAO STRUCTS CHAR
typedef struct elementoChar{
	char dado;
	struct elementoChar * proximo;
}t_elementoChar;

typedef struct listaChar{
	t_elementoChar * primeiro;
	t_elementoChar * ultimo;
}t_listaChar;

typedef struct pilhaChar{
	t_listaChar * l;
}t_pilhaChar;

typedef struct filaChar{
  t_listaChar * l;
}t_filaChar;
//FIM DECLARAÇAO STRUCTS CHAR

//INICIO DECLARAÇAO STRUCTS FLOAT
typedef struct elementoFloat{
  double dado;
  struct elementoFloat * proximo;
}t_elementoFloat;

typedef struct listaFloat{
  t_elementoFloat * primeiro;
  t_elementoFloat * ultimo;
}t_listaFloat;

typedef struct pilhaFloat{
  t_listaFloat * l;
}t_pilhaFloat;

typedef struct filaFloat{
  t_listaFloat * l;
}t_filaFloat;
//FIM DECLARAÇAO STRUCTS FLOAT

//INICIO LISTA CHAR
t_listaChar * CriaListaChar(){
   t_listaChar * l = (t_listaChar *)malloc(sizeof(t_listaChar));
   l->primeiro = NULL;
   l->ultimo = NULL;
   return l;
}

int EstaVaziaChar(t_listaChar * l){
    if(l->primeiro == NULL){
       return TRUE;
    }
    return FALSE;
}

void InsereInicioChar(char valor, t_listaChar * l){
    t_elementoChar * novoprimeiro = (t_elementoChar *)malloc(sizeof(t_elementoChar));
    novoprimeiro->dado = valor;
    novoprimeiro->proximo = l->primeiro;
    l->primeiro = novoprimeiro;
    if(l->ultimo == NULL){
        l->ultimo = novoprimeiro;
    }
}

void InsereFinalChar(char valor, t_listaChar * l){
   t_elementoChar * novoultimo = (t_elementoChar *)malloc(sizeof(t_elementoChar));
   novoultimo->dado = valor;
   novoultimo->proximo = NULL; 
   if(l->primeiro == NULL){
      l->primeiro = novoultimo;
   }else{
     l->ultimo->proximo = novoultimo;
   }
   l->ultimo = novoultimo;
}

char RemoveInicioChar(t_listaChar * l){
    if(EstaVaziaChar(l)){
        return -1;
    }
    char tmp = l->primeiro->dado;
    t_elementoChar * removido = l->primeiro;
    l->primeiro = l->primeiro->proximo;
    free(removido);
    if(l->primeiro == NULL){
       l->ultimo = NULL;
    }
    return tmp;
}
// FIM LISTA CHAR

//INICIO LISTA FLOAT
t_listaFloat * CriaListaFloat(){
   t_listaFloat * l = (t_listaFloat *)malloc(sizeof(t_listaFloat));
   l->primeiro = NULL;
   l->ultimo = NULL;
   return l;
}

int EstaVaziaFloat(t_listaFloat * l){
    if(l->primeiro == NULL){
       return TRUE;
    }
    return FALSE;
}

void InsereInicioFloat(double valor, t_listaFloat * l){
    t_elementoFloat * novoprimeiro = (t_elementoFloat *)malloc(sizeof(t_elementoFloat));
    novoprimeiro->dado = valor;
    novoprimeiro->proximo = l->primeiro;
    l->primeiro = novoprimeiro;
    if(l->ultimo == NULL){
        l->ultimo = novoprimeiro;
    }
}

void InsereFinalFloat(double valor, t_listaFloat * l){
   t_elementoFloat * novoultimo = (t_elementoFloat *)malloc(sizeof(t_elementoFloat));
   novoultimo->dado = valor;
   novoultimo->proximo = NULL; 
   if(l->primeiro == NULL){
      l->primeiro = novoultimo;
   }else{
     l->ultimo->proximo = novoultimo;
   }
   l->ultimo = novoultimo;
}

double RemoveInicioFloat(t_listaFloat * l){
    if(EstaVaziaFloat(l)){
        return -1;
    }
    double tmp = l->primeiro->dado;
    t_elementoFloat * removido = l->primeiro;
    l->primeiro = l->primeiro->proximo;
    free(removido);
    if(l->primeiro == NULL){
       l->ultimo = NULL;
    }
    return tmp;
}
//FIM LISTA FLOAT

//INICIO PILHA CHAR
t_pilhaChar * CriaPilhaChar(){
   t_pilhaChar * p =  (t_pilhaChar *)malloc(sizeof(t_pilhaChar));
   p->l = CriaListaChar();
   return p;
}

void EmpilharChar(char valor,t_pilhaChar * p){
  InsereInicioChar(valor, p->l);
}

char DesempilharChar(t_pilhaChar * p){
  return RemoveInicioChar(p->l);
}

int EstaVaziaCharPilha(t_pilhaChar * p){
    return EstaVaziaChar(p->l);
}
// FIM PILHA CHAR

//INICIO PILHA FLOAT
t_pilhaFloat * CriaPilhaFloat(){
   t_pilhaFloat * p =  (t_pilhaFloat *)malloc(sizeof(t_pilhaFloat));
   p->l = CriaListaFloat();
   return p;
}

void EmpilharFloat(double valor,t_pilhaFloat * p){
  InsereInicioFloat(valor, p->l);
}


double DesempilharFloat(t_pilhaFloat * p){
  return RemoveInicioFloat(p->l);
}


int EstaVaziaFloatPilha(t_pilhaFloat * p){
    return EstaVaziaFloat(p->l);
}
//FIM PILHA FLOAT

//INICIO FILA CHAR
t_filaChar * CriaFilaChar(){
   t_filaChar * f =  (t_filaChar *)malloc(sizeof(t_filaChar));
   f->l = CriaListaChar();
   return f;
}

void EnfileirarChar(char valor, t_filaChar * f){
  InsereFinalChar(valor, f->l);
}

char DesenfileirarChar(t_filaChar * f){
  return RemoveInicioChar(f->l);
}

int EstaVaziaCharFila(t_filaChar * f){
    return EstaVaziaChar(f->l);
}
//FIM FILA CHAR

//INICIO FILA FLOAT
t_filaFloat * CriaFilaFloat(){
   t_filaFloat * f =  (t_filaFloat *)malloc(sizeof(t_filaFloat));
   f->l = CriaListaFloat();
   return f;
}

void EnfileirarFloat(double valor, t_filaFloat * f){
  InsereFinalFloat(valor, f->l);
}

double DesenfileirarFloat(t_filaFloat * f){
  return RemoveInicioFloat(f->l);
}

int EstaVaziaFloatFilaFloat(t_filaFloat * f){
    return EstaVaziaFloat(f->l);
}
//FIM FILA FLOAT

int ValidaExpressao(t_filaChar * filaCaracterVerificar){
  char caracter;
  t_pilhaChar * pilhaInicializador = CriaPilhaChar();

  while(!EstaVaziaCharFila(filaCaracterVerificar)){
    caracter = DesenfileirarChar(filaCaracterVerificar);
    if(caracter == '('){
      EmpilharChar(caracter, pilhaInicializador);
    }
    if(caracter == ')'){
      if(EstaVaziaCharPilha(pilhaInicializador)){
        return FALSE;
      } else{
        caracter = DesempilharChar(pilhaInicializador);
        if(caracter != '('){
          return FALSE;
        }
      }
    }
  }

  return TRUE;
}

void Menu(t_filaFloat * filaNumerica, t_filaChar * filaCaracter, t_filaFloat * filaOrdem){
  char caracter = '0';
  double valorNumerico = 0;
  t_filaChar * filaCaracterVerificar = CriaFilaChar();

  printf("Digite a expressão que deseja calcular:\n");
  while(caracter != '\n'){
    scanf("%c", &caracter);
    if(caracter != ' '){
      if(caracter >= '0' && caracter <= '9'){
        while(caracter >= '0' && caracter <= '9'){
          valorNumerico = (valorNumerico*10) + caracter - '0';
          scanf("%c", &caracter);
        }
        EnfileirarFloat(valorNumerico, filaNumerica);
        EnfileirarFloat(NUMERO, filaOrdem);
      }
      EnfileirarChar(caracter, filaCaracterVerificar);
      EnfileirarChar(caracter, filaCaracter);
      EnfileirarFloat(CARACTER, filaOrdem);
    }
  }
  if(ValidaExpressao(filaCaracterVerificar)){
    printf("Expressao Válida\n");
  } else {
    printf("Expressao não válida\n");
  }
}
int main(int argc, char const *argv[])
{
  t_filaFloat* filaNumerica = CriaFilaFloat();
  t_filaChar* filaCaracter = CriaFilaChar();
  t_filaFloat* filaOrdem = CriaFilaFloat();

  Menu(filaNumerica, filaCaracter, filaOrdem);

  return 0;
}