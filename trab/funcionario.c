#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

void inserirFuncionario(Funcionario * funcionarios, int * quantidadeFuncionarios, Funcionario novoFuncionario) {
    funcionarios = realloc(funcionarios, sizeof(Funcionario) * (*quantidadeFuncionarios + 1));

    funcionarios[*quantidadeFuncionarios] = novoFuncionario;
    *quantidadeFuncionarios += 1;
}

void realizarBuscaBinaria(Funcionario *funcionarios, int qntFuncionarios, int cpf) {
    Funcionario *listaOrdenada = funcionarios;

    int i = qntFuncionarios / 2;
    int comparacoes = 0;
    do {
        comparacoes++;
        if (listaOrdenada[i].cpf == cpf) {
            printf("O cliente com CPF = %d foi encontrado após %i interacoes\n", cpf, comparacoes);
            printf("Nome: %s\nIdade: %d\nSalario: $ %.2f\n\n",
                   funcionarios[i].nome,
                   funcionarios[i].idade,
                   funcionarios[i].salario);
            return;
        } else if(funcionarios[i].cpf > cpf) {
            i += i / 2;
        } else {
            i -= i / 2;
        }
    } while (i / 2 == 0);
    printf("\nNão encontrado!\n");
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
/*
Funcionario* bubblesort(Funcionario* funcionarios,int tam){

    for(i = 1; i < tam;i++){
        for(j = 0; j < tam-1; j++){
            if(){

            }
        }

    }
}*/


Funcionario* realizarQuickSort(Funcionario* funcionarios,int tam){
    int a = 1, b = tam - 1;
    Funcionario *listaOrdenada = funcionarios;
    Funcionario pivo = listaOrdenada[0];
    if (tam <= 1){
        return funcionarios;
    }
    while(a<=b){
        while ((listaOrdenada[a].cpf < pivo.cpf) && (a < tam)){
            a++;
        }
        while ((listaOrdenada[b].cpf > pivo.cpf) && (b > 0)){
            b--;
        }
        if (a < b){
            Funcionario aux = listaOrdenada[b];
            listaOrdenada[b] = listaOrdenada[a];
            listaOrdenada[a] = aux;
            a++;
            b--;
        }
    }
    listaOrdenada[0] = listaOrdenada[b];
    listaOrdenada[b] = pivo;
    realizarQuickSort(listaOrdenada, b);
    realizarQuickSort(&listaOrdenada[a], tam-a);
    return listaOrdenada;
}


