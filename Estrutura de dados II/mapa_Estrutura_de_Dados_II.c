#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Constantes
#define E 0
#define D 1
#define R -1

//Tipo nó
typedef struct NO {
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;

//Tipo árvore
typedef struct ARVORE{
	NO *raiz;
}ARVORE;

//Declaração da árvore
ARVORE a;

//Protótipos das funções
void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int paiNo, int valor, int lado);
void preOrdem(NO* raiz);
void menu(void);

//Função que sempre deve ser chamada ao se criar uma nova árvore
void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}

//Função utilizada para inicializar um novo nó na árvore
void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Falha de alocacao.\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}



//Função que realiza a inserção de maneira ordenada
//Valores menores ou iguais vão à esquerda
//Valores maiores vão à direita
void insereNoArvoreOrdenada(int paiNo, int valor, int lado)
{
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);

	switch(lado){
		case E:
			while(corrente){
				pai = corrente;
				corrente = corrente->esq;
				if(!corrente){
					printf("Inserindo no a esquerda de %d\n", paiNo);
					pai->esq = novoNo;
					system("pause");
				}
			}
			break;
		case D:
			while(corrente){
				pai = corrente;
				if(novoNo->dado >= corrente->dado){
					corrente = corrente->dir;
					if(!corrente){
						printf("Inserindo no a direita de %d\n", paiNo);
						pai->dir = novoNo;
						system("pause");
					}				
				}else{
					corrente = corrente->esq;
				}
			}
			break;
		case R:
			printf("Inserindo a raiz da arvore\n");
			a.raiz = novoNo;
			system("pause");
			break;
	}
}

//Executa o caminhamento pré-ordem a partir do nó indicado por "raiz"
void preOrdem(NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

int main()
{
	int pai, valor, lado, controle;
	setlocale(LC_ALL, "Portuguese");
	inicializaArvore(a);
	do{
		menu();
		scanf("%d", &controle);
		fflush(stdin);
		switch(controle){
			case 1:
				printf("Valor do NO pai: ");
				fflush(stdin);
				scanf("%d", &pai);
				
				printf("Valor do NO: ");
				fflush(stdin);
				scanf("%d", &valor);
				
				printf("Qual lado vai inserir: (E = %d; D = %d; R = %d)", E, D, R);
				fflush(stdin);
				scanf("%d", &lado);
				
				insereNoArvoreOrdenada(pai, valor, lado);
				
				break;
			case 2:
				printf("\n\n Mostrando Pre-ordem: ");
				preOrdem(a.raiz);
				printf("\n\n");
				system("pause");
				break;
			case 0:
				printf("Saindo....");
				break;
		}
	}while(controle != 0);

}

void menu(void){
	system("cls");
	printf("1 - inserir no na arvore\n2 - Mostrar pre-ordem\n0 - Sair\n\n");
}
