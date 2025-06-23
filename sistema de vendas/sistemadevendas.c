#include <stdio.h>
#include <string.h>

int main() {
    char nomeProduto[50];
    int quantidade, numProdutos;
    float preco, totalProduto, totalDia;
    char continuar;

    do {
        totalDia = 0;
        printf("\n--- Registro de Vendas do Dia ---\n");
        printf("Quantos produtos diferentes foram vendidos hoje? ");
        scanf("%d", &numProdutos);
        getchar(); // limpar o buffer do teclado

        for (int i = 1; i <= numProdutos; i++) {
            printf("\nProduto %d:\n", i);

            printf("Nome do produto: ");
            fgets(nomeProduto, sizeof(nomeProduto), stdin);
            nomeProduto[strcspn(nomeProduto, "\n")] = 0; // remover '\n' do final

            printf("Quantidade vendida: ");
            scanf("%d", &quantidade);

            if (quantidade <= 0) {
                printf("Quantidade inválida. Ignorando produto.\n");
                getchar(); // limpar buffer
                continue;
            }

            printf("Preço unitário: R$ ");
            scanf("%f", &preco);

            if (preco < 0) {
                printf("Preço inválido. Ignorando produto.\n");
                getchar(); // limpar buffer
                continue;
            }

            totalProduto = quantidade * preco;
            printf("Total do produto %s: R$ %.2f\n", nomeProduto, totalProduto);

            totalDia += totalProduto;
            getchar(); // limpar o buffer após leitura com scanf
        }

        printf("\nTotal geral de vendas do dia: R$ %.2f\n", totalDia);

        printf("\nDeseja registrar outro dia de vendas? (s/n): ");
        scanf(" %c", &continuar);
        getchar(); // limpar o buffer

    } while (continuar == 's' || continuar == 'S');

    printf("\nEncerrando o sistema de vendas.\n");
    return 0;
}
