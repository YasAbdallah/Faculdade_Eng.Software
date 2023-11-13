#include <stdio.h>
#include <stdlib.h>


#define tamanho 100

struct str_no{
	char dado;
	str_no *pai;
	str_no *esqueda;
	str_no *direita;
};

struct str_no arvore[tamanho];

int indice = 0;
int opt = -1;
char pai, no;

void insere_arvore(int pai, char dado, int lado);
int pesquisa_arvore(char dado);
void menu(void);

int main(){
	int temp;
	
	menu();
	scanf("%d", &opt);
	
	do{
		switch(opt){
			switch(opt){
			case 1:
				printf("\nDigite o valor de PAI: ");
				scanf("%c", &pai);
				scanf("%c", &pai);
				
				printf("Digite o valor do NO: ");
				scanf("%c", &no);
				scanf("%c", &no);
				
				printf("Digite o lado da subarvore (E=%d/D=%d/R=%d): ",E, D, R);
				scanf("%d", &lado);
				
				temp = arvore_procura(pai);
				arvore_insere(temp, no, lado);
				
				break;
			case 2:
				printf("Digite o valor do NO: ");
				scanf("%c", &no);
				scanf("%c", &no);
				temp = arvore_procura(no);
				
				
				printf("No %c\nFilho Esquerda: %c\nFilho Direita: %c\n\n", arvore[temp].dado, arvore[arvore[temp].esq].dado, arvore[arvore[temp].dir].dado);
				system("pause");
				break;
		}	
	}while(opt != 0);
	system("pause");
	return (0);
}

void arvore_insere(int pai, char dado, int lado){
	int calc;

	switch(lado){
		case E:
			indice = (2 * pai) + 1
			arvore[pai].esq = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esq = -1;
			arvore[indice].dir = -1;
			indice++;
			break;
		case D:
			indice = (2 * pai) + 2
			arvore[pai].dir = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esq = -1;
			arvore[indice].dir = -1;
			indice++;
			break;
		case R:
			arvore[indice].dado = dado;
			arvore[indice].pai = -1;
			arvore[indice].esq = -1;
			arvore[indice].dir = -1;
			indice++;
			break;
	}
}

//Procura no
int arvore_procura(char dado){
	int i;
	if(indice != 0){
		for(i = 0; i < indice; i++){
			if (arvore[i].dado == dado){
				return (i);
			}
		}
	}else{
		return (0);
	}
}

//Desenha menu na tela
void menu_mostrar(void){
	int i;
	system("cls");
	for (i = 0; i < indice; i++){
		printf("| %c", arvore[i].dado);
	}
	printf("\n1 - insere um No na arvore");
	printf("\n2 - pesquisa um No na arvore");
	printf("\n0 - sair...\n\n");
}
