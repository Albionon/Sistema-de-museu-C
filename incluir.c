#include "incluir.h"
#include "administracao.h"
#include "bancodedados.h"


int incluir()
{
  FILE *arquivo;//o ponteiro para o arquivo bin
  Dados dados;// definimos a nossa estrutura principal de dados como Dados e aqui definimos sua variavel dentro do programa

  arquivo = fopen("adm.bin","ab");//abrimento do arquivo
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  printf("Digite o id.....: ");
  scanf("%d", &dados.id);
  fflush(stdin);
  printf("Digite o tema...: ");
  fgets(dados.nome,sizeof(dados.nome),stdin);
  fflush(stdin);
  printf("Digite a descricao...: ");
  fgets(dados.descricao,sizeof(dados.descricao),stdin);
  fflush(stdin);
  printf("\n\nDigite a obra #1 ...: ");
  fgets(dados.obra1,sizeof(dados.obra1),stdin);
  fflush(stdin);
   printf("\n\nDigite a obra #2 ...: ");
  fgets(dados.obra2,sizeof(dados.obra2),stdin);
  fflush(stdin);
  printf("\n\nDigite a obra #3 ...: ");
  fgets(dados.obra3,sizeof(dados.obra3),stdin);
  fflush(stdin);
   printf("\n\nDigite a obra #4 ...: ");
  fgets(dados.obra4,sizeof(dados.obra4),stdin);
  fflush(stdin);


  fwrite(&dados, sizeof(Dados), 1, arquivo);//salvando arquivo digitado

  fclose(arquivo);//fechamento do arquivo

  printf("Registro incluido com sucesso.\n");//avisando que o arquivo foi salvo com sucesso
  getch();
  return 0;
}
