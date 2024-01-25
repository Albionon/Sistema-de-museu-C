#include "consultar.h"
#include "administracao.h"
#include "bancodedados.h"

int consultar()
{
  FILE *arquivo;
  Dados dados;
  int id_busca, encontrou=0;

  arquivo = fopen("adm.bin","rb");//abrindo arquivo para a leitura
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  printf("Digite o id para pesquisa: ");
  scanf("%d", &id_busca);

  while(fread(&dados, sizeof(Dados), 1, arquivo))//lopping para continuar na leitura do arquivo desejado
  {
    if(dados.id == id_busca)//comparação de id para localizar o arquivo
    {
      encontrou = 1;
      printf("Tema encontrado:\n");
      printf("id.....: %d\n",dados.id);
      printf("tema...: %s\n",dados.nome);
      printf("descricao...: %s\n",dados.descricao);
      printf("\n obra#1...: %s\n",dados.obra1);
      printf("\n obra#2...: %s\n",dados.obra2);
      printf("\n obra#3...: %s\n",dados.obra3);
      printf("\n obra#4...: %s",dados.obra4);
    }
  }

  fclose(arquivo);

  if(encontrou == 0)
  {
    printf("Nao ha registro com o valor pesquisado.");//comentario em caso de não achar o arquivo
  }

  getch();
  return 0;
}
