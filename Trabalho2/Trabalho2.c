#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define VAZIO ' '

// INÍCIO FUNÇÕES BASE DE UMA ÁRVORE
typedef struct no{
  char dado;
  struct no * traco;
  struct no * ponto;
}t_no;

t_no * criarNo(char dado){
   t_no * n =  (t_no *)malloc(sizeof(t_no));
   n->traco = NULL;
   n->ponto = NULL;
   n->dado = dado;
   return n;
}

/*int inserir(t_no * raiz, char dado){
    if(raiz == NULL){
       return -1;
    }
    if(raiz->dado > dado){//Esquerda
       if(raiz->traco == NULL){
    raiz->traco = criarNo(dado);
   
       }else{
          return inserir(raiz->traco, dado);
       }
    }else if(raiz->dado < dado){//Direita
  if(raiz->ponto == NULL){
    raiz->ponto = criarNo(dado);
       }else{
          return inserir(raiz->ponto, dado);
       }
    }
    return -1;
}*/

// FIM FUNÇÕES BASE DE UMA ÁRVORE

//INÍCIO FUNÇÕES BASE DE LISTAS E FILAS

typedef struct elemento{
  char codigo[10];
  char simbolo;
  struct elemento * proximo;
}t_elemento;

typedef struct lista{
  t_elemento * inicio;
  t_elemento * fim;
}t_lista;

t_lista * criarLista(){
  t_lista * l = (t_lista *)malloc(sizeof(t_lista));
  l->inicio = NULL;
  l->fim = NULL;
  return l;
}

int estaVazia(t_lista * l){
  if(l->inicio == NULL){
    return 1;
  }
  return 0;
}

void insereFim(char letra, char code[], t_lista * l){
  int i = 2, j = 0;
  t_elemento * nu = (t_elemento *)malloc(sizeof(t_elemento));
  nu->simbolo = letra;
  while(code[i] != '\n'){
    nu->codigo[j] = code[i];
    i++;
    j++;
  }
  nu->codigo[j] = '\0';
  nu->proximo = NULL;
  if(l->inicio == NULL){
    l->inicio = nu;
  } else{
    l->fim->proximo = nu;
  }
  l->fim = nu;
}

/*char removeInicio(t_lista * l){
  if(estaVazia(l)){
    return -1;
  }
  int tmp = l->inicio->dado;
  t_elemento * removido = l->inicio;
  l->inicio = l->inicio->proximo;
  if(l->inicio == NULL){
    l->fim = NULL;
  }
  free(removido);
  return tmp;
}
*/
/*void insereFila(char letra, char code[], t_lista * f){
  insereFim(letra, code, f);
}*/

/*char removeFila(t_lista * f){
  return removeInicio(f);
}*/

//FIM FUNÇÕES BASE DE LISTAS E FILAS

//INICIO FUNÇÕES DEBUG


void EmOrdem(t_no * raiz){
   if(raiz != NULL){

      EmOrdem(raiz->ponto);
      if(raiz->dado != VAZIO){
       printf("%c ",raiz->dado);
      }
      EmOrdem(raiz->traco);
   }
}

void ImprimirArvore(t_no * raiz){
  EmOrdem(raiz);
  printf("\n");
}

void ImprimirLista(t_lista * l){
  t_elemento * atual = l->inicio;
  while(atual != NULL){
    printf("letra %c codigo %s\n", atual->simbolo, atual->codigo);
    atual = atual->proximo;
  }
  printf("Fim da lista\n");
}
//FIM FUNÇÕES DEBUG

void AcharNo(t_no * arvoreCodigo, char * texto){
  int i;
  t_no * noAtual = arvoreCodigo;

  for (i = 2; texto[i] != '\n'; i++){
    if (texto[i] == '.'){
      if(noAtual->ponto == NULL){
        noAtual->ponto = criarNo(VAZIO);
      }
      noAtual = noAtual->ponto;
    }
    if (texto[i] == '-')
    {
      if(noAtual->traco == NULL){
        noAtual->traco = criarNo(VAZIO);
      }
      noAtual = noAtual->traco;
    }
  }
  noAtual->dado = texto[0];
}

void CriarArvore (t_no * arvoreCodigo){
  FILE * arquivo;
  char texto[20];

  arquivo = fopen("morse.txt", "r");

  if (arquivo == NULL){
    printf("falha na abertura do arquivo\n");
  } else {
    while (fgets(texto, 20, arquivo) != NULL){
      AcharNo(arvoreCodigo, texto);
    }
  }
}

void DecifrarMensagemArvore(t_no * arvoreCodigo){
  FILE * arquivo;
  char caracter;
  t_no * noAtual;

  arquivo = fopen("mensagem.txt", "r");

  if(arquivo == NULL){
    printf("falha na abertura do arquivo\n");
  } else {
    do{
      caracter = getc(arquivo);
      noAtual = arvoreCodigo;
      while(caracter != '/' && caracter != ' ' && caracter != EOF && caracter != '\n'){
        if(caracter == '.'){
          noAtual = noAtual->ponto;
        }
        if (caracter == '-')
        {
          noAtual = noAtual->traco;
        }
        caracter = getc(arquivo);
      }
      printf("%c", noAtual->dado);
      if (caracter == '/')
      {
        printf(" ");
      }
      if (caracter == '\n'){
        printf("\n");
      }
    }while(caracter != EOF);
    printf("\n");
  }
}

t_lista * CriarListaCodigo(t_lista * listaCodigo){
  FILE * arquivo;
  char texto[20];
  int i;
  t_no * noLetra;

  arquivo = fopen("morse.txt", "r");

  if (arquivo == NULL){
    printf("falha na abertura do arquivo\n");
    return NULL;
  } else {
    while (fgets(texto, 20, arquivo) != NULL){
      insereFim(texto[0], texto, listaCodigo);
    }
  }
  return listaCodigo;
}

bool ComparaString(char texto[], char code[]){
  int i, j = 0;
  for (i = 0; texto[i] != '\0' && code [i] != '\0'; i++){
    if(texto[i] == code[i]){
      j++;
    }
  }
  if ((i == j) && (texto[i] == code[i])){
    return true;
  }
  return false;
}

char ProcuraLetraLista(char texto[], t_lista * listaCodigo){
  int i = 0;
  t_elemento * atual = listaCodigo->inicio;
  while(atual != NULL && strcmp(texto, atual->codigo)){
    atual = atual->proximo;
  }
 // printf("   [ texto: %s e codigo: %s letra: %c ]\n",texto, atual->codigo, atual->simbolo);
  //printf("\n");
  return atual->simbolo;
}

void DecifrarMensagemLista(t_lista * listaCodigo){
  FILE * arquivo;
  char texto[10], caracter, simboloCorrespondente;
  int i = 0;
  t_no * elementoAtual;

  arquivo = fopen("mensagem.txt", "r");

  if(arquivo == NULL){
    printf("falha na abertura do arquivo\n");
  } else {
    do{
      caracter = getc(arquivo);

      i = 0;
      while(caracter != '/' && caracter != ' ' && caracter != EOF && caracter != '\n'){
        texto[i] = caracter;
        caracter = getc(arquivo);
        i++;
      }
      /*if (caracter == EOF){
        break;
      }*/
      texto[i] = '\0';
      if (texto[0] != '\0'){
        //printf("entrei\n");
        simboloCorrespondente = ProcuraLetraLista(texto, listaCodigo);
        printf("%c", simboloCorrespondente);
      }
      if (caracter == '/')
      {
        printf(" ");
      }
      if (caracter == '\n')
      {
        printf("\n");
      }
    }while(caracter != EOF);
    printf("\n");
  }
}

int main(){
  int t_inicial, t_final, tempo_lista, tempo_arvore, n, i;
  struct timespec start, stop;
  t_no * arvoreCodigo = criarNo(0);
  CriarArvore(arvoreCodigo);
  t_lista * listaCodigo = criarLista(listaCodigo);
  listaCodigo = CriarListaCodigo(listaCodigo);

  scanf("%d", &n);
  
  clock_gettime(CLOCK_REALTIME, &start);
  t_inicial = start.tv_nsec;
  for (i = 0; i < n; i++){
    DecifrarMensagemArvore(arvoreCodigo);
  }
  clock_gettime(CLOCK_REALTIME, &stop);
  t_final = stop.tv_nsec;
  tempo_arvore = t_final - t_inicial;
  printf("Tempo para decodificar usando uma árvore: %d\n", tempo_arvore);

  clock_gettime(CLOCK_REALTIME, &start);
  t_inicial = start.tv_nsec;
  for (int i = 0; i < n; ++i)
  {
    DecifrarMensagemLista(listaCodigo);
  }
  clock_gettime(CLOCK_REALTIME, &stop);
  t_final = stop.tv_nsec;
  tempo_lista = t_final - t_inicial;
  printf("Tempo para decodificar usando uma lista: %d\n", tempo_lista);

  return 0;
}