#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int cpf;
    int idade;
    float salario;
} Funcionario;

void realizarBuscaBinaria(Funcionario *funcionarios, int qntFuncionarios, int cpf);

void inserirFuncionario(Funcionario * funcionarios, int * quantidadeFuncionarios, Funcionario novoFuncionario);

void realizarBuscaBinaria(Funcionario *funcionarios, int qntFuncionarios, /*char **/int cpf);

void realizarBuscaSequencial(Funcionario *funcionarios, int qntFuncionarios, /*char **/int cpf);

void copiar(Funcionario funcionarios[], Funcionario copia[],int tam);

void bubblesort(Funcionario funcionarios[], Funcionario copia[],int tam);

void consultar();