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

int EstaVaziaFloatFila(t_filaFloat * f){
    return EstaVaziaFloat(f->l);
}
//FIM FILA FLOAT

//INICIO FUNCOES PARA DEBUG DO CODIGO
void ImprimirListaChar(t_listaChar * l){
  t_elementoChar * atual = l->primeiro;
  while(atual != NULL){
    printf("%c ", atual->dado);
    atual = atual->proximo;
  }
  printf("\n");
}

void ImprimirFilaChar(t_filaChar * f){
  ImprimirListaChar(f->l);
  printf("Fim da Fila de caracter\n");
}

void ImprimirPilhaChar(t_pilhaChar * p){
  ImprimirListaChar(p->l);
  printf("Fim da Pilha de caracter\n");
}

void ImprimirListaFloat(t_listaFloat * l){
  t_elementoFloat * atual = l->primeiro;
  while(atual != NULL){
    printf("%.2lf ", atual->dado);
    atual = atual->proximo;
  }
  printf("\n");
}

void ImprimirFilaFloat(t_filaFloat * f){
  ImprimirListaFloat(f->l);
  printf("Fim da Fila de numero\n");
}

void ImprimirPilhaFloat(t_pilhaFloat * p){
  ImprimirListaFloat(p->l);
  printf("Fim da Pilha de numero\n");
}
//FIM FUNCOES PARA DEBUG DO CODIGO

int EhNumero(char caracter){
	if (caracter >= '0' && caracter <= '9')
	{
		return TRUE;
	}
	return FALSE;
}

int ProximoNaLista(t_listaChar* l){
	t_elementoChar * atual = l->primeiro;

	if (EstaVaziaChar(l))
	{
		return FALSE;
	}

	if(EhNumero(atual->dado)){
		return NUMERO;
	}
	return CARACTER;
}

int ProximoNaFila(t_filaChar* f){
	return ProximoNaLista(f->l);	
}

double DesenfileirarNumero(t_filaChar* f, char caracter){
	double valorNumerico = 0;

	valorNumerico = (valorNumerico*10) + caracter - '0';

	while(ProximoNaFila(f) == NUMERO){
		caracter = DesenfileirarChar(f);
        valorNumerico = (valorNumerico*10) + caracter - '0';        
    }
    return valorNumerico;
}

int PrioridadeMaiorIgual(char caracter, char caracterDesempilhado){
	if (caracter == '+' || caracter == '='){

		return TRUE;
	}
	if (caracter == '*' || caracter == '/')
	{
		if (caracterDesempilhado == '*' || caracterDesempilhado == '/'){
			return TRUE;
		}
		else{
			return FALSE;
		}
	}
}

int ValidaExpressao(t_filaChar * filaCaracterVerificar){
  char caracter;
  t_pilhaChar * pilhaInicializador = CriaPilhaChar();
  int i = 0;

  while(!EstaVaziaCharFila(filaCaracterVerificar)){
    caracter = DesenfileirarChar(filaCaracterVerificar);
    if(i == 1){
      i = 0;
      if(caracter == ')')
        return FALSE;
    }
    if(caracter == '('){
      EmpilharChar(caracter, pilhaInicializador);
      i = 1;
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
  if(!EstaVaziaCharPilha(pilhaInicializador)){
  	return FALSE;
  }
  return TRUE;
}

void InfixaParaPosfixa(t_filaChar* expressaoInfixa,t_filaChar* expressaoPosfixaChar, \
 t_filaFloat* expressaoPosfixaFloat, t_filaFloat* expressaoPosfixaOrdem){
	t_pilhaChar* pilhaInicializador = CriaPilhaChar();
	char caracter, caracterDesempilhado;
	double valorNumerico;

	while(!EstaVaziaCharFila(expressaoInfixa)){
		caracter = DesenfileirarChar(expressaoInfixa);
		if(caracter >= '0' && caracter <= '9'){
			valorNumerico = DesenfileirarNumero(expressaoInfixa, caracter);
			EnfileirarFloat(valorNumerico, expressaoPosfixaFloat);
			EnfileirarFloat(NUMERO, expressaoPosfixaOrdem);

		} 
		else if(caracter == '(' || caracter == ')'){

			if(caracter == '('){
				EmpilharChar(caracter, pilhaInicializador);
			}
			if(caracter == ')'){
				do{
					caracterDesempilhado = DesempilharChar(pilhaInicializador);
					if(caracterDesempilhado != '('){
						EnfileirarChar(caracterDesempilhado, expressaoPosfixaChar);
						EnfileirarFloat(CARACTER, expressaoPosfixaOrdem);
					}
				}while(caracterDesempilhado != '(');
			}
		}
		else if (caracter == '+' || caracter == '-' || caracter == '/' || caracter == '*'){
			if(EstaVaziaCharPilha(pilhaInicializador)){
				EmpilharChar(caracter, pilhaInicializador);
			} else {
				do{
					caracterDesempilhado = DesempilharChar(pilhaInicializador);
					if(caracterDesempilhado == '('){
						EmpilharChar(caracterDesempilhado, pilhaInicializador);
						break;
					} 
					else if(caracterDesempilhado == '*' || caracterDesempilhado == '/'){
						EnfileirarChar(caracterDesempilhado, expressaoPosfixaChar);
						EnfileirarFloat(CARACTER, expressaoPosfixaOrdem);
					} else if (caracterDesempilhado == '+' || caracterDesempilhado == '-'){
						if (caracter == '*' || caracter == '/'){
							EmpilharChar(caracterDesempilhado, pilhaInicializador);
						}
						if (caracter == '+' || caracter == '-'){
							EnfileirarChar(caracterDesempilhado, expressaoPosfixaChar);
							EnfileirarFloat(CARACTER, expressaoPosfixaOrdem);
						}
					}
				}while(!EstaVaziaCharPilha(pilhaInicializador) && PrioridadeMaiorIgual(caracter, caracterDesempilhado));
				EmpilharChar(caracter, pilhaInicializador);
			}
		}		
	}
	while(!EstaVaziaCharPilha(pilhaInicializador)){
		caracterDesempilhado = DesempilharChar(pilhaInicializador);
		EnfileirarChar(caracterDesempilhado, expressaoPosfixaChar);
		EnfileirarFloat(CARACTER, expressaoPosfixaOrdem);
	}
}



double CalculaPosfixa(t_filaChar* expressaoPosfixaChar, t_filaFloat* expressaoPosfixaFloat, t_filaFloat* expressaoPosfixaOrdem){
	t_pilhaFloat* pilhaInicializador = CriaPilhaFloat();
	char caracterDenfileirado, caracterProximo;
	double valorNumerico, numeroDesenfileirado, operando1, operando2, filaOrdem;
	int filaOrdemInt;

	while(!EstaVaziaCharFila(expressaoPosfixaChar) || !EstaVaziaFloatFila(expressaoPosfixaFloat)){
		filaOrdem = DesenfileirarFloat(expressaoPosfixaOrdem);
		filaOrdemInt = filaOrdem;
		switch (filaOrdemInt){
			case NUMERO:
				numeroDesenfileirado = DesenfileirarFloat(expressaoPosfixaFloat);
				EmpilharFloat(numeroDesenfileirado, pilhaInicializador);
				break;
			case CARACTER:
				caracterDenfileirado = DesenfileirarChar(expressaoPosfixaChar);
				operando2 = DesempilharFloat(pilhaInicializador);
				if (EstaVaziaFloatPilha(pilhaInicializador)){
					operando1 = 0;
				} else {
					operando1 = DesempilharFloat(pilhaInicializador);
				}

				if(caracterDenfileirado == '+'){
	        		valorNumerico = operando1 + operando2;
	        	}
	        	if(caracterDenfileirado == '-'){
	        		valorNumerico = operando1 - operando2;
	        	}
	        	if(caracterDenfileirado == '*'){
	        		valorNumerico = operando1 * operando2;
	        	}
	        	if(caracterDenfileirado == '/'){
	        		if (operando2 == 0)
	        		{
	        			printf("Divisão por 0, expressão não válida\n");
	        			return 0;
	        		}
	        		valorNumerico = operando1 / operando2;
	        	}
	        	EmpilharFloat(valorNumerico, pilhaInicializador);
				break;
		}	
	}
	return DesempilharFloat(pilhaInicializador);
}

int Menu(t_filaChar* expressaoInfixa){
  char caracter = '0';
  double valorNumerico = 0;
  t_filaChar * filaCaracterVerificar = CriaFilaChar();


  printf("Digite a expressão que deseja calcular:\n");
  do{
    scanf("%c", &caracter);
    
    if(caracter != ' ' && caracter != '\n'){
      EnfileirarChar(caracter, expressaoInfixa);

      if(caracter != ' ' && caracter != '\n'){
        EnfileirarChar(caracter, filaCaracterVerificar);
      }
    }
  }while(caracter != '\n');
  if(ValidaExpressao(filaCaracterVerificar)){
    printf("Expressão Válida\n");
    return TRUE;
  } else {
    printf("Expressão não válida\n");
    while(EstaVaziaCharFila(expressaoInfixa)){
      DesenfileirarChar(expressaoInfixa);
    }
    return FALSE;
  }
}
int main(int argc, char const *argv[])
{
	t_filaChar* expressaoInfixa = CriaFilaChar();
	t_filaChar* expressaoPosfixaChar = CriaFilaChar();
	t_filaFloat* expressaoPosfixaFloat = CriaFilaFloat();
	t_filaFloat* expressaoPosfixaOrdem = CriaFilaFloat();
	double resultado;

	if (Menu(expressaoInfixa)){
  		InfixaParaPosfixa(expressaoInfixa, expressaoPosfixaChar, expressaoPosfixaFloat, expressaoPosfixaOrdem);
		resultado = CalculaPosfixa(expressaoPosfixaChar, expressaoPosfixaFloat, expressaoPosfixaOrdem);
		printf("Resultado: %.2lf\n", resultado);
	}
	return 0;
}
