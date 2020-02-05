#include <stdio.h>

// Lista 02 - Questão 2
// Aluno: Rodrigo Matos Aguiar - Rudigus

// Registro que representa um aluno.
typedef struct aluno
{
	char nome[256];
	double nota[3];
} aluno;

void printarRegistroAluno(aluno aluno)
{
	printf("Aluno %s\n{\n    Nota da Avaliação Parcial 1: %.1lf\n    Nota da Avaliação Parcial 2: %.1lf\n    Nota da Avaliação Final: %.1lf\n}\n", aluno.nome, aluno.nota[0], aluno.nota[1], aluno.nota[2]);
}

int main()
{
	aluno aluno;
	printf("Informe o nome do aluno e as notas obtidas nas avaliações: parcial 1, parcial 2 e final, separados por 1 (um) espaço: ");
	scanf("%s %lf %lf %lf", aluno.nome, &aluno.nota[0], &aluno.nota[1], &aluno.nota[2]);
	printarRegistroAluno(aluno);
}

