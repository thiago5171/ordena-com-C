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

int menuDeAtualizarFunc(int cpf){
    int escolha;

    while(1){
         printf("\nAtualizar:\n");
        printf("\n1 - Nome\n");
        printf("2 - Idade\n");
        printf("3 - Salário\n");
        printf("4 - Todos os valores\n");
        printf("5 - Cancelar operação\n");

        printf("\nDigite a opção desejada: ");
        switch(scanf("%d",&escolha)) {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 4;
            case 5:
                return 0;
            default :
                printf("\nOpção inválida\n");
                break;
        }
    }
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

void atualizarFuncionario(Funcionario *funcionario, int tam){
    int cpf, id, i = 0;    
    printf("Insira o CPF do funcionario que terá os dados atualizados: ");
    scanf("%d",&cpf);
    int escolha = menuDeAtualizarFunc(cpf);
    while(i < tam) {
        if(funcionario[i].cpf == cpf) {
            id = i;
            break;
        }
        i++;
    }
    if(escolha == 1 || escolha == 4){
        printf("Nome: ");
        scanf("%s",funcionario[id].nome);
    }
    
    if(escolha == 2 || escolha == 4){
        printf("Idade: ");
        scanf("%d",&funcionario[id].idade);
    }
    
    if(escolha == 3 || escolha == 4){
        printf("Salário: ");
        scanf("%f",&funcionario[id].salario);
    }
    
    return;
    
}
