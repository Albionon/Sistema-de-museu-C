#include "bancodedados.h"
#include "usuario.h"
#include "ingresso.h"

#define VALOR_INTEIRO 30.00
#define MEIA_ENTRADA 15.00

void ingresso() {
    FILE *arquivo;
    FILE *csvFile;
    Dados dados;
    User user;
    int escolhaExposicao, escolhaIngresso, quantidade;
    int r = 1;
    float valor = 0.0;
    float valorTotal = 0.0; // Variável para armazenar o valor total a ser pago

    arquivo = fopen("adm.bin", "rb");//abrimento dos arquivos bin para mostrar as obras
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    csvFile = fopen("dados_ingressos.csv", "a");//abrimento para salvar informações do cliente e também para depois no csv serve no excel para fazer estaticas com a quatnidade vendida e tanto tempo e outras verificações
    if (csvFile == NULL) {
        perror("Erro ao criar o arquivo CSV");
        exit(1);
    }

    fprintf(csvFile, "CPF; Nome; Valor do Ingresso; Quantidade; Valor Total\n");

     system("cls");

    while (fread(&dados, sizeof(Dados), 1, arquivo)) {
        printf("Exposicao #%d\n", r);
        printf("%d: %s - %s\n", r, dados.nome, dados.descricao);
        printf("-------------------------------\n");
        r++;
  }


        printf("Escolha a exposicao: ");
        scanf("%d", &escolhaExposicao);
        if (escolhaExposicao < 1 || escolhaExposicao >= r) {
            printf("Escolha inválida. Tente novamente.\n");
            system("pause");
            return;
        }

        printf("------------------------------\n");
        printf(" Escolha o tipo de ingresso:\n");
        printf("1- Valor Inteiro - R$%.2f\n", VALOR_INTEIRO);
        printf("2- Meia entrada - R$%.2f\n", MEIA_ENTRADA);
        scanf("%d", &escolhaIngresso);

        if (escolhaIngresso < 1 || escolhaIngresso > 2) {
            printf("Escolha inválida. Tente novamente.\n");
            system("pause");
            return;
        }
        system("cls");
        printf("Digite seu nome: ");
        getchar();
        fgets(user.nome, sizeof(user.nome), stdin);
        size_t length = strlen(user.nome);
if (user.nome[length - 1] == '\n') {
    user.nome[length - 1] = '\0';

        printf("\nDigite seu CPF: ");
        scanf("%s", user.cpf);
        system("cls");
        printf("Digite a quantidade de ingressos: ");
        scanf("%d", &quantidade);

        switch (escolhaIngresso) {
            case 1:
                valor = VALOR_INTEIRO;
                break;
            case 2:
                valor = MEIA_ENTRADA;
                break;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }

        // Calcular o valor total
        valorTotal = valor * quantidade;
       system("cls");
        printf("Valor a pagar: R$%.2f\n", valorTotal);
         system("pause");
        // Escrever os dados no arquivo CSV
   fprintf(csvFile, "\"%s\";\"%s\";%.2f;%d;%.2f\n", user.cpf, user.nome, valor, quantidade, valorTotal);




    }

    fclose(arquivo);
    fclose(csvFile);

}
