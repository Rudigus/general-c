#include <stdio.h>

// Lista 02 - Questão 4
// Aluno: Rodrigo Matos Aguiar - Rudigus

typedef struct contato
{
	char nome[256];
	char endereco[256];
	char telefone[32];
	char situacao;
} contato;

void printarRegistroContato(contato contato)
{
	printf("\nContato %s\n{\n    Endereço: %s\n    Telefone: %s\n    Situação: %c\n}\n", contato.nome, contato.endereco, contato.telefone, contato.situacao);
}

int main()
{
	int n;
	printf("Informe o número de contatos da agenda: ");
	scanf("%d", &n);
	contato agenda[n];
	for(int i = 0; i < n; i++)
	{
		printf("Informe o nome, endereço, telefone e situação (L – Livre, X – Ocupado e * - Apagado) do %dº contato, separados por 1 (um) espaço: ", i + 1);
		scanf("%s %s %s %c", agenda[i].nome, agenda[i].endereco, agenda[i].telefone, &agenda[i].situacao);
	}
	for(int i = 0; i < n; i++)
	{
		printarRegistroContato(agenda[i]);
	}
	
}

