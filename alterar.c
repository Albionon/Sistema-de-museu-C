#include "alterar.h"
#include "administracao.h"
#include "bancodedados.h"

int alterar()
{
  FILE *arquivo;
  Dados dados;
  int id_busca,encontrou=0;

  arquivo = fopen("adm.bin","rb+");
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  printf("Digite o ID para pesquisa: ");
  scanf("%d", &id_busca);
  fflush(stdin);
  while(fread(&dados, sizeof(Dados),1,arquivo))
  {
    if(dados.id == id_busca)
    {
      encontrou = 1;
      // Faça as alterações desejadas nos dados do registro
      printf("Digite o novo tema...:\n ");
      fgets(dados.nome,sizeof(dados.nome),stdin);
      fflush(stdin);
      printf("Digite a nova descricao...:\n ");
      fgets(dados.descricao,sizeof(dados.descricao),stdin);
      fflush(stdin);
       printf("\n\nDigite a nova obra#1...:\n ");
      fgets(dados.obra1,sizeof(dados.obra1),stdin);
      fflush(stdin);
       printf("\n\nDigite a nova obra#2...: ");
      fgets(dados.obra2,sizeof(dados.obra2),stdin);
      fflush(stdin);
       printf("\n\nDigite a nova obra#3...: ");
      fgets(dados.obra3,sizeof(dados.obra3),stdin);
      fflush(stdin);
       printf("\n\nDigite a nova obra#4...: ");
      fgets(dados.obra4,sizeof(dados.obra4),stdin);
      fflush(stdin);





      // Volta para a posição do arquivo para escrever as alterações
      fseek(arquivo, -(long)sizeof(Dados), SEEK_CUR);
      fwrite(&dados, sizeof(Dados), 1, arquivo);
      printf("Dados alterado com sucesso!\n");
      break; //Finaliza o loop
    }
  }

  fclose(arquivo);

  if(encontrou == 0)
  {
    printf("Nao ha registro com o valor pesquisado.");
  }
  getch();
  return 0;
}
