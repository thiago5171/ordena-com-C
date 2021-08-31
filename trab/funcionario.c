#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"


void copiar(Funcionario funcionarios[], Funcionario copia[],int tam){
    for(int i = 0; i<tam; i++){
        copia[i] = funcionarios[i];
    }
}

void realizarBuscaBinaria(Funcionario *funcionarios, int qntFuncionarios, int cpf) {
    Funcionario *listaOrdenada = funcionarios;
    copiar(funcionarios,listaOrdenada,qntFuncionarios);
    int inicio = 0, fim = qntFuncionarios - 1, meio;
    int comparacoes = 0;
    do {
        comparacoes++;
        meio = (inicio + fim)/2;
        if (listaOrdenada[meio].cpf == cpf) {
            printf("O cliente com CPF = %d foi encontrado após %i interacoes\n", cpf, comparacoes);
            printf("Nome: %s\nIdade: %d\nSalario: $ %.2f\n\n",
                   funcionarios[meio].nome,
                   funcionarios[meio].idade,
                   funcionarios[meio].salario);
            return;
        } else if(funcionarios[meio].cpf < cpf) {
            inicio = meio + 1;
        } else if(funcionarios[meio].cpf > cpf){
            fim = meio - 1;
        }
        
    } while (inicio<=fim);
    printf("\nNão encontrado!\n");
}
void inserirFuncionario(Funcionario * funcionarios, int * quantidadeFuncionarios, Funcionario novoFuncionario) {
    //funcionarios = (Funcionario*) realloc(funcionarios, sizeof(Funcionario) *(*quantidadeFuncionarios + 1));

    funcionarios[*quantidadeFuncionarios] = novoFuncionario;
    *quantidadeFuncionarios += 1;
}

void realizarBuscaSequencial(Funcionario *funcionarios, int qntFuncionarios, /*char*/int cpf) {
    for (int i = 0; i < qntFuncionarios; i++) {
        //if (strcmp(cpf, funcionarios[i].cpf) == 0) {
        if (cpf == funcionarios[i].cpf) {
            printf("O cliente com CPF = %d foi encontrado após %i interacoes\n", cpf, i + 1);
            printf("Nome: %s\nIdade: %d\nSalario: $ %.2f\n\n",
                   funcionarios[i].nome,
                   funcionarios[i].idade,
                   funcionarios[i].salario);
            return;
        }
    }
    printf("\nNão encontrado!\n");
}



void bubblesort(Funcionario funcionarios[], Funcionario copia[],int tam){
    
    copiar(funcionarios,copia,tam);

    Funcionario aux[0];
    for(int i = 1; i < tam;i++){
        for(int j = 0; j < tam-1; j++){
            if(copia[j].cpf > copia[j + 1].cpf){
                aux[0] = copia[j];
                copia[j] = copia[j+1];
                copia[j+1]= aux[0];
            }
        }
    }
}

 