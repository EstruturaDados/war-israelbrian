#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constantes globais 
#define MAX_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 10 
#define MAX_TROPAS 20

// Definição da estrutura (Struct)
struct Territorio {
    char nome [TAM_NOME];
    char cor[TAM_COR];
    int qtd_tropas;
};

void limparBufferEntrada() {
    int c;
    while ((c =getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio territorios[MAX_TERRITORIOS];
    int totalTerritorios = 0;

    // Mensagens iniciais do jogo
    printf("---------------------------------------\n");
    printf("        Bem vindo ao jogo WAR!\n");
    printf("---------------------------------------\n");
    printf("Vamos cadastrar os territorios do jogo!\n");
    printf("---------------------------------------\n");

    // Iniciio da logica do programa - Só pede os dados do territorio para cadastro enquanto a condição do (do while) for true
    do {
            printf("\nDigite o nome do territorio: "); // Printa a mensagem pedindo o nome
            fgets(territorios[totalTerritorios].nome, TAM_NOME, stdin); // Armazena o nome com '\n' 
            territorios[totalTerritorios].nome[strcspn(territorios[totalTerritorios].nome, "\n")] = 0; // Remove o '\n'
    
            printf("Digite a cor do territorio: ");
            fgets(territorios[totalTerritorios].cor, TAM_COR, stdin);
            territorios[totalTerritorios].cor[strcspn(territorios[totalTerritorios].cor, "\n")] = 0;
    
            printf("Digite a quantidade de tropas do territorio: ");
            scanf("%d", &territorios[totalTerritorios].qtd_tropas);
            limparBufferEntrada();

            totalTerritorios++;

            printf("\nTerritorio cadastrado com sucesso!\n");
            printf("--------------------------------------\n");
    } while (totalTerritorios < MAX_TERRITORIOS);
    
    // condição para validar se o totalTerritorios já aingiu o limite de 5 territorios cadastrados
    if (totalTerritorios > MAX_TERRITORIOS) {
        printf("Limite de territorios atingido!\n");
        printf("--------------------------------------\n");
    }

    // Impressão dos dados cadastrados - Todos os territorios e seus atributos (nome, cor, qtd_tropas)
    printf("\nTerritorios cadastrados:\n");
        for (int i = 0; i < totalTerritorios; i++) {
            printf("\nTerritorio %d:\n", i + 1);
            printf("Nome: %s\n", territorios[i].nome);
            printf("Cor: %s\n", territorios[i].cor);
            printf("Quantidade de tropas: %d\n", territorios[i].qtd_tropas);
            printf("-------------------------\n");
        }

    return 0; // fim do programa
}