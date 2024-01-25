#include "administracao.h"
#include "usuario.h"

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    int op = 1;

    // esse while e para definir qual área vai ser se é adm ou cliente
    while (op != 3) {
        printf("Digite 1 para administração do museu: ");
        printf("\nDigite 2 para cliente: ");
        printf("\nDigite 3 para sair do programa:\n ");
        scanf("%d", &op);



        switch (op) {
            case 1:
               if (login()) {
                    while (op != 6){// definido para a pessoa so sai quando a escolhar for até 6 que e a opção de sair
                        system("pause");
//menu administrativo só usuario com senha e login podem entrar
                        system("cls");
                        printf("Sistema - Administrativo do museu  2023 \n\n");
                        printf("1-Incluir obra \n");
                        printf("2-Consultar por ID\n");
                        printf("3-Consultar em bloco\n");
                        printf("4-Alterar\n");
                        printf("5-Excluir\n");
                        printf("6-Sair\n");
                        printf("Escolha uma opcao: ");
                        scanf("%d", &op);

                        switch (op) {
                            case 1:
                                incluir();// funções definidas de acordo com o que o professor passou em sala de aula
                                break;
                            case 2:
                                consultar();
                                break;
                            case 3:
                                consultarbl();
                                break;
                            case 4:
                                alterar();
                                break;
                            case 5:
                                excluir();
                                break;
                            case 6:
                                printf("Saindo do Menu .\n");
                                break;
                            default:
                                printf("Opcao invalida!\n");
                                getch();
                                break;
                        }
                    }
                }
                break;

            case 2:
                // área do usuário cliente para o museu
                while (op != 4) { // mesmo looping dos anteriores com a mesma lógica
                    printf("Menu Principal:\n");
                    printf("1 - Comprar ingresso\n");
                    printf("2 - Responder ao questionário\n");
                    printf("3 - Consultar obras\n");
                    printf("4 - Sair\n");
                    printf("Escolha uma opção: ");
                    scanf(" %d", &op);

                    switch (op) {
                            case 1:
                                ingresso();// sistema de compras com indentificação e limite de comprar até 3 por pessoa
                                break;
                            case 2:
                                questionario();// questionario de satifasção do cliente com sua experiência com a obra
                                break;
                            case 3:
                                consultar_usuario();// opção do usuario pode consultar as obras antes da sua comprar para ver se o tema e as obras o atraem
                                break;
                            case 4:
                             printf("saindo do menu.\n");// saindo do menu do cliente e voltando para parte principal
                                break;
                            default:
                                printf("Opcao invalida!\n");
                                getch();
                                break;
                    }
                }
                break;

                 case 3:// para sair do  programa e do lopping
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida!\n");
                getchar();
                break;
        }
    }

    return 0;
}
