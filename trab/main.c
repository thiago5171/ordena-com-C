#include <stdio.h>
#include "funcionario.h"
#include <stdlib.h>
// prototipos
int escolherOpcao();
Funcionario preencherDados();
         

Funcionario *funcionarios;
Funcionario *copia;
int quantidadeFuncionarios = 0;

int main(void) {
    funcionarios = (Funcionario*) malloc(sizeof(Funcionario)*100);
    copia = (Funcionario*) malloc(sizeof(Funcionario));

    while(1){
        switch(escolherOpcao()) {
            case 1:
                inserirFuncionario(funcionarios, &quantidadeFuncionarios, preencherDados());
                
                break;
            case 2:

                break;
            case 3:
                copiar(funcionarios, copia, quantidadeFuncionarios);
                consultar();
                break;
            case 4:
                break;
            case 5:
                return 0;
        }
    }
}
 
int escolherOpcao() {
    int opcao = 0;
    while (1) {
        printf("\n1 - Contratar funcionario\n");
        printf("2 - Exibir funcionario por nome\n");
        printf("3 - Consultar funcionario\n");
        printf("4 - Atualizar dados de um funcionario\n");
        printf("5 - Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        if (opcao <= 0 && opcao > 5) {
            printf("A opcao digitada eh invalida!\n");
        } else {
            break;
        }
    }
    return opcao;
}

Funcionario preencherDados() {
    Funcionario novoFuncionario;
    
    printf("\nDigite o nome do funcionario: ");
    scanf("%s",novoFuncionario.nome);
    
    printf("Digite O número do cpf: ");
    scanf("%d", &novoFuncionario.cpf);
    
    printf("Digite a idade:");
    scanf("%d", &novoFuncionario.idade);
    
    printf("Digite o  salário: ");
    scanf("%f",&novoFuncionario.salario);
    
    return novoFuncionario; 
}



void consultar() {
    int cpf;
    printf("Digite o cpf que deseja buscar: ");
    scanf("%d", &cpf);

    printf("Métodos de pesquisa: \n");
    printf("1 - Sequencial;\n");
    printf("2 - Binário;\n");
    printf("Qual metodo de pesquisa deseja utilizar: ");
    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1) {
        realizarBuscaSequencial(funcionarios, quantidadeFuncionarios, cpf);
    } else if (opcao == 2) {
        realizarBuscaBinaria(copia, quantidadeFuncionarios, cpf);
    } else {
        printf("Busca inválida\n\n");
    }
}

