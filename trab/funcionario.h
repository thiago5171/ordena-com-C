#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int cpf;
    int idade;
    float salario;
} Funcionario;

void inserirFuncionario(Funcionario * funcionarios, int * quantidadeFuncionarios,  Funcionario novoFuncionario);
void realizarBuscaBinaria(Funcionario *funcionarios, int qntFuncionarios, /*char **/int cpf);
void realizarBuscaSequencial(Funcionario *funcionarios, int qntFuncionarios, /*char **/int cpf);