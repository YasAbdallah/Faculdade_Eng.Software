#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Cadastro {
	char num_lote[10];
	int codigo;
	char nome[31], cpf[15], vacina[21], data[10];
}Cadastro;

void criarArquivoPaciente();
void cadastrarPaciente();
void listarCadastrados();

int main(){
	setlocale(LC_ALL, "");
	int controle;
	
	do{
		printf("\nO que deseja fazer?\n\n1 - Cadastrar vacina\n2 - Listar Aplicações\n3 - Consultar CPF\n4 - Sair\n");
		scanf("%d", &controle);
		fflush(stdin);
		system("cls");
		switch(controle){
			case 1:
				cadastrarPaciente();
				system("pause");
				system("cls");	
				break;
			case 2:
				listarCadastrados();
				system("pause");
				system("cls");
				break;
			case 3:
				break;
			case 4:
				printf("Saindo....");
				break;
			default:
				printf("Opção informada é inválida.");
				break;
		}
	}while(controle != 4);
	
	return (0);
}

void cadastrarPaciente(){
	struct Cadastro paciente;
	int code;
	FILE *arq;
	arq = fopen("pacientes.txt", "a+");
	printf("************************************\n");
	printf("***** Cadastrando Nova Vacina! *****\n");
	printf("************************************\n\n");
	
	code = paciente.codigo++;

	printf("Informe o nome do paciente: ");
	scanf("%s", paciente.nome);
	fflush(stdin);
	
	printf("Informe o CPF do paciente: ");
	scanf("%s", paciente.cpf);
	fflush(stdin);
	
	printf("Informe a vacina aplicada: ");
	scanf("%s", paciente.vacina);
	fflush(stdin);
	
	printf("Informe a data da aplicação: ");
	scanf("%s", paciente.data);
	fflush(stdin);
	
	printf("Informe o número do lote da vacina: ");
	scanf("%s", paciente.num_lote);
	fflush(stdin);
	
	fputc(code, arq);
	fputc(',', arq);
	fputs(paciente.nome, arq);
	fputc(',', arq);
	fputs(paciente.cpf, arq);
	fputc(',', arq);
	fputs(paciente.vacina, arq);
	fputc(',', arq);
	fputs(paciente.data, arq);
	fputc(',', arq);
	fputs(paciente.num_lote, arq);
	fputs("\n", arq);
	fclose(arq);
}
void listarCadastrados(){
	struct Cadastro paciente;
	FILE *arq;
	arq = fopen("pacientes.txt", "rb");
	printf("************************************\n");
	printf("******* Listando Aplicações! *******\n");
	printf("************************************\n\n");
	
	while(fread(&paciente, sizeof(struct Cadastro), 1, arq)){
		printf("Código: %d\nNome: %s\nCPF: %s\n", paciente.codigo, paciente.nome, paciente.cpf);
		printf("Vacina: %s\nData: %s\nNúmero do lote: %d\n", paciente.vacina, paciente.data, paciente.num_lote);
		printf("====================================");
	}
}
void criarArquivoPaciente(){
	FILE *arq;
	arq = fopen("pacientes.txt", "a+");
	if (arq == NULL){
		printf("Encontramos um problema ao criar o arquivo.");
		fclose(arq);
	}else{
		printf("Arquivo criado com sucesso!");
		fclose(arq);
	}	
}
