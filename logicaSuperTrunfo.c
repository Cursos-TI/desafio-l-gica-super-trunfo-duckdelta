#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas

int main() {
    // VARIÁVEIS DA CARTA 1
    char carta1_estado;
    char carta1_codigo[4];
    char carta1_cidade[36];
    int carta1_populacao;
    float carta1_area;
    float carta1_pib;
    int carta1_pontos_turisticos;

    // VARIÁVEIS DA CARTA 2
    char carta2_estado;
    char carta2_codigo[4];
    char carta2_cidade[36];
    int carta2_populacao;
    float carta2_area;
    float carta2_pib;
    int carta2_pontos_turisticos;

    // COLETA DOS DADOS DA CARTA 1
    printf("-Digite uma letra entre A e H representando o estado da 1ª carta (Exemplo: A): \n");
    scanf(" %c", &carta1_estado);
    printf("-Digite o código representando a 1ª carta (Exemplo: A01): \n");
    scanf("%s", carta1_codigo);
    printf("-Digite o nome da cidade representando a 1ª carta (Exemplo: Maceió): \n");
    scanf("%s", carta1_cidade);
    printf("-Digite a quantidade de população da cidade representando a 1ª carta (Exemplo: 957916): \n");
    scanf("%d", &carta1_populacao);
    printf("-Digite a área (em km²) da cidade representando a 1ª carta (Exemplo: 509.320): \n");
    scanf("%f", &carta1_area);
    printf("-Digite o PIB (em bilhões) da cidade representando a 1ª carta (Exemplo: 27.480): \n");
    scanf("%f", &carta1_pib);
    printf("-Digite a quantidade de pontos turísticos da cidade representando a 1ª carta (Exemplo: 23): \n");
    scanf("%d", &carta1_pontos_turisticos);

    // COLETA DOS DADOS DA CARTA 2
    printf("\n-Digite uma letra entre A e H representando o estado da 2ª carta (Exemplo: B): \n");
    scanf(" %c", &carta2_estado);
    printf("-Digite o código representando a 2ª carta (Exemplo: B01): \n");
    scanf("%s", carta2_codigo);
    printf("-Digite o nome da cidade representando a 2ª carta (Exemplo: Xique-Xique): \n");
    scanf("%s", carta2_cidade);
    printf("-Digite a quantidade de população da cidade representando a 2ª carta (Exemplo: 44757): \n");
    scanf("%d", &carta2_populacao);
    printf("-Digite a área (em km²) da cidade representando a 2ª carta (Exemplo: 5079.662): \n");
    scanf("%f", &carta2_area);
    printf("-Digite o PIB (em bilhões) da cidade representando a 2ª carta (Exemplo: 0.461): \n");
    scanf("%f", &carta2_pib);
    printf("-Digite a quantidade de pontos turísticos da cidade representando a 2ª carta (Exemplo: 5): \n");
    scanf("%d", &carta2_pontos_turisticos);

    // CÁLCULOS DERIVADOS
    float carta1_densidade = carta1_populacao / carta1_area;
    float carta2_densidade = carta2_populacao / carta2_area;

    float carta1_pib_per_capita = (carta1_pib * 1000000000) / carta1_populacao;
    float carta2_pib_per_capita = (carta2_pib * 1000000000) / carta2_populacao;

    int op1, op2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    float soma_carta1, soma_carta2;

    // MENU DE PRIMEIRO ATRIBUTO
    printf("\n===== MENU DE COMPARAÇÃO - ATRIBUTO 1 =====\n");
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &op1);

    // MENU DE SEGUNDO ATRIBUTO (DINÂMICO)
    printf("\n===== MENU DE COMPARAÇÃO - ATRIBUTO 2 =====\n");
    printf("Escolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != op1) {
            switch(i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Digite sua opção: ");
    scanf("%d", &op2);

    // COMPARAÇÃO DOS ATRIBUTOS ESCOLHIDOS
    switch(op1) {
        case 1: valor1_carta1 = carta1_populacao; valor1_carta2 = carta2_populacao; break;
        case 2: valor1_carta1 = carta1_area; valor1_carta2 = carta2_area; break;
        case 3: valor1_carta1 = carta1_pib; valor1_carta2 = carta2_pib; break;
        case 4: valor1_carta1 = carta1_pontos_turisticos; valor1_carta2 = carta2_pontos_turisticos; break;
        case 5: valor1_carta1 = carta1_densidade; valor1_carta2 = carta2_densidade; break;
        default: printf("Opção inválida para o primeiro atributo.\n"); return 1;
    }

    switch(op2) {
        case 1: valor2_carta1 = carta1_populacao; valor2_carta2 = carta2_populacao; break;
        case 2: valor2_carta1 = carta1_area; valor2_carta2 = carta2_area; break;
        case 3: valor2_carta1 = carta1_pib; valor2_carta2 = carta2_pib; break;
        case 4: valor2_carta1 = carta1_pontos_turisticos; valor2_carta2 = carta2_pontos_turisticos; break;
        case 5: valor2_carta1 = carta1_densidade; valor2_carta2 = carta2_densidade; break;
        default: printf("Opção inválida para o segundo atributo.\n"); return 1;
    }

    // Exibição dos valores
    printf("\nComparação entre %s e %s:\n", carta1_cidade, carta2_cidade);

    printf("\nAtributo 1: ");
    switch(op1) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
    printf(" -> %.2f x %.2f\n", valor1_carta1, valor1_carta2);

    printf("Resultado do atributo 1: %s venceu!\n",
        (op1 == 5) ? 
            (valor1_carta1 < valor1_carta2 ? carta1_cidade : (valor1_carta2 < valor1_carta1 ? carta2_cidade : "Empate")) :
            (valor1_carta1 > valor1_carta2 ? carta1_cidade : (valor1_carta2 > valor1_carta1 ? carta2_cidade : "Empate"))
    );

    printf("\nAtributo 2: ");
    switch(op2) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
    printf(" -> %.2f x %.2f\n", valor2_carta1, valor2_carta2);

    printf("Resultado do atributo 2: %s venceu!\n",
        (op2 == 5) ? 
            (valor2_carta1 < valor2_carta2 ? carta1_cidade : (valor2_carta2 < valor2_carta1 ? carta2_cidade : "Empate")) :
            (valor2_carta1 > valor2_carta2 ? carta1_cidade : (valor2_carta2 > valor2_carta1 ? carta2_cidade : "Empate"))
    );

    // Soma dos atributos
    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor1_carta2 + valor2_carta2;

    printf("\nSoma dos dois atributos:\n");
    printf("%s: %.2f\n", carta1_cidade, soma_carta1);
    printf("%s: %.2f\n", carta2_cidade, soma_carta2);

    printf("Resultado final: %s\n",
        (soma_carta1 > soma_carta2) ? carta1_cidade :
        (soma_carta2 > soma_carta1) ? carta2_cidade : "Empate!"
    );

    return 0;
}