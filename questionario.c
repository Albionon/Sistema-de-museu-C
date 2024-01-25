#include "bancodedados.h"
#include "usuario.h"
#include "questionario.h"




void questionario() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    User user;
    int respostas[10];
    char *perguntas[10] = {
        "Como voce avalia a facilidade de acesso as informacoes sobre o museu e suas obras?",
        "Qual e a sua avaliacao geral da colecao de obras deste museu?",
        "Quais obras especificas mais chamaram a sua atencao? Avalie a qualidade delas.",
        "Como voce avalia a variedade e a diversidade das obras expostas?",
        "Os rotulos e descricoes das obras estavam informativos e faceis de entender?",
        "Como voce avalia a organizacao e o layout da exposicao?",
        "Avalie a interacao com o pessoal do museu. Quao prestativos e atenciosos foram?",
        "Qual e a sua opiniao sobre as comodidades oferecidas, como cafes, lojas de presentes e areas de descanso?",
        "Se voce participou de atividades educacionais ou eventos especiais relacionados ao museu, como os avaliaria?",
        "Com base em sua experiencia, o quanto você recomendaria este museu a outras pessoas?"
    };

    // Solicita o nome da pessoa
   printf("Digite seu nome: ");
        getchar();
        fgets(user.nome, sizeof(user.nome), stdin);
    // Remove a quebra de linha se houver

       system("cls");
    printf("Por favor, responda as seguintes perguntas com uma avaliacao de 1 a 5, sendo 1 muito ruim e 5 muito bom.\n");

    int i;
    for (i = 0; i < 10; i++) {
        system("cls");
        printf("\n%d. %s\n", i + 1, perguntas[i]);
        printf("Avaliacao (1-5): ");
        scanf("%d", &respostas[i]);

        if (respostas[i] < 1 || respostas[i] > 5) {
            printf("Por favor, forneça uma avaliacao de 1 a 5.\n");
            i--;
        }
    }

    // Salvando as respostas em um arquivo CSV
    FILE *arquivo;
    arquivo = fopen("respostas.csv", "a");  // Modo 'a' para adicionar ao arquivo se ele já existir

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    fprintf(arquivo, "Nome; Pergunta ; Resposta\n");

    for (i = 0; i < 10; i++) {
       fprintf(arquivo,"\"%s\";\"%s\";%d\n",user.nome, perguntas[i], respostas[i]);

    }

    fclose(arquivo);

    printf("\nRespostas coletadas e salvas em 'respostas.csv'.\n");

    return;
}
