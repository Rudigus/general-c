#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define n 5

// Lista 02 - Questão 5
// Aluno: Rodrigo Matos Aguiar - Rudigus

typedef struct contato
{
	char nome[256];
	char endereco[256];
	char telefone[32];
	char situacao;
} contato;

// Agenda de contatos
contato agenda[n];

void printarRegistroContato(contato contato)
{
	printf("\nContato %s\n{\n    Endereço: %s\n    Telefone: %s\n    Situação: %c\n}\n", contato.nome, contato.endereco, contato.telefone, contato.situacao);
}

void inserirRegistros()
{
	for(int i = 0; i < n; i++)
	{
		printf("\nInforme o nome, endereço, telefone e situação (L – Livre, X – Ocupado e * - Apagado) do %dº contato, separados por 1 (um) espaço: ", i + 1);
		scanf("%s %s %s %c", agenda[i].nome, agenda[i].endereco, agenda[i].telefone, &agenda[i].situacao);
	}
	for(int i = 0; i < n; i++)
	{
		printarRegistroContato(agenda[i]);
	}
}

void pesquisarRegistros()
{
	printf("\nInforme o nome do contato que deseja pesquisar: ");
	char nome[256];
	scanf("%s", nome);
	for(int i = 0; i < n; i++)
	{
		if(strcmp(agenda[i].nome, nome) == 0)
		{
			printf("\nO contato com o nome fornecido foi encontrado:\n");
			printarRegistroContato(agenda[i]);
			return;
		}
	}
	printf("\nNão foi encontrado nenhum contato com o nome fornecido.\n");
}

contato alterarRegistros()
{
	for(int i = 0; i < n; i++)
	{
		printf("\n%d - %s\n", i, agenda[i].nome);
	}
	int contatoEscolhido;
	printf("\nInforme o contato cujos campos se deseja alterar: ");
	scanf("%d", &contatoEscolhido);
	printf("\n1 - Nome\n\n2 - Endereço\n\n3 - Telefone\n\n4 - Situação\n");
	int campoEscolhido;
	printf("\nInforme o campo que deseja alterar: ");
	scanf("%d", &campoEscolhido);
	printf("\nInforme o valor do campo: ");
	switch(campoEscolhido)
	{
		case 1:
			scanf("%s", agenda[contatoEscolhido].nome);
			break;
		case 2:
			scanf("%s", agenda[contatoEscolhido].endereco);
			break;
		case 3:
			scanf("%s", agenda[contatoEscolhido].telefone);
			break;
		case 4:
			scanf("%c", &agenda[contatoEscolhido].situacao);
			break;
		default:
			printf("\nOpção inválida. Alteração abortada.\n");
	}
	printarRegistroContato(agenda[contatoEscolhido]);
}

int main()
{
	int opcao = -1;
	bool contatosRegistrados = false;
	while(opcao != 4)
	{
		printf("\nMenu\n\nInforme a opção desejada:\n\n1 - Inserir Registros\n\n2 - Pesquisar Registros\n\n3 - Alterar Registros\n\n4 - Sair\n"); 
		scanf("%d", &opcao);
		switch(opcao)
		{
			case 1:
				inserirRegistros();
				contatosRegistrados = true;
				break;
			case 2:
				if(contatosRegistrados)
				{
					pesquisarRegistros(agenda);
				}
				else
				{
					printf("\nOperação cancelada. Primeiro, registre os 5 contatos.\n");
				}
				break;
			case 3:
				if(contatosRegistrados)
				{
					alterarRegistros();
				}
				else
				{
					printf("\nOperação cancelada. Primeiro, registre os 5 contatos.\n");
				}
				break;
			case 4:
				printf("\nFinalizando o programa...\n");
				break;
			default:
				printf("\nOpção inválida. Tente novamente.\n");
				break;
		}	
	}
}








