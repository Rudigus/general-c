#include <stdio.h>

// Lista 02 - Questão 1
// Aluno: Rodrigo Matos Aguiar - Rudigus

// Registro que define um funcionário.
typedef struct funcionario 
{
	char nome[35];
	char sexo;
	int pecasProduzidas;
} funcionario;

// Calcula o número de peças produzidas por funcionários de determinado sexo.
int calcularPecasProduzidas(funcionario *funcionarios, char sexoEscolhido, int n)
{
	int pecasProduzidas = 0;
	for(int i = 0; i < n; i++)
	{
		if(funcionarios[i].sexo == sexoEscolhido)
		{
			pecasProduzidas += funcionarios[i].pecasProduzidas;
		}
	}
	return pecasProduzidas;
}

funcionario calcularMaiorProducao(funcionario *funcionarios, int n)
{
	funcionario melhorFuncionario = funcionarios[0];
	for(int i = 1; i < n; i++)
	{
		if(funcionarios[i].pecasProduzidas > melhorFuncionario.pecasProduzidas)
		{
			melhorFuncionario = funcionarios[i];
		}
	}
	return melhorFuncionario;
}

// Recebe um número n de funcionários como input e printa informações baseadas neles.
int main()
{
	int n;
	printf("Informe o número de funcionários: ");
	scanf("%d", &n);
	funcionario funcionarios[n];
	for(int i = 0; i < n; i++)
	{
		printf("\nInforme o nome, sexo e número de peças produzidas pelo funcionário, \nseparados por 1 (um) espaço: ");
		scanf("%s %c %d", funcionarios[i].nome, &funcionarios[i].sexo, &funcionarios[i].pecasProduzidas);
	}
	printf("\nPeças produzidas por funcionários do sexo: Masculino - %d, Feminino - %d.", calcularPecasProduzidas(funcionarios, 'M', n), calcularPecasProduzidas(funcionarios, 'F', n));
	funcionario melhorFuncionario = calcularMaiorProducao(funcionarios, n);
	printf("\n\nFuncionário(a) com a maior produção registrada, contabilizando %d peças produzidas: %s.\n", melhorFuncionario.pecasProduzidas, melhorFuncionario.nome); 
}

