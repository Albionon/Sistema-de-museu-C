#include "excluir.h"
#include "administracao.h"
#include "bancodedados.h"

int excluir()
{
  FILE *arquivo, *novoArquivo;
  Dados dados;
  int id_busca,encontrou=0;
  int op;
  int exclui=0;

  arquivo = fopen("adm.bin","rb");
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  novoArquivo = fopen("temp.bin", "wb");
  if (novoArquivo == NULL)
  {
    perror("Erro ao criar o novo arquivo");
    exit(1);
  }
  printf("Digite o ID do tema para exclusao: ");
  scanf("%d", &id_busca);

  while(fread(&dados, sizeof(Dados),1,arquivo))
  {
    if(dados.id == id_busca)
    {
      encontrou = 1;
      printf("Tema encontrado:\n");
      printf("ID.....: %d\n",dados.id);
      printf("Tema...: %s",dados.nome);

    }
  }

  if(encontrou==1)
  {
    fseek(arquivo, 0, SEEK_SET); //posiciona no início do arquivo.
    printf("Deseja realmente excluir este tema?(1-Sim | 2-Nao): ");
    scanf("%d", &op);
    if(op==1)
    {
      // Ler os registros do arquivo original e gravar no novo arquivo, exceto o registro a ser excluído
      while (fread(&dados, sizeof(Dados), 1, arquivo))
      {
        printf("%d %d\n",dados.id,id_busca);getch();
        if (dados.id != id_busca)
        {
          exclui = 1;
          fwrite(&dados, sizeof(Dados), 1, novoArquivo);
        }
      }
    }
  }

  fclose(arquivo);
  fclose(novoArquivo);

  if(encontrou == 0)
  {
    printf("Nao ha registro com o valor pesquisado.");
  }
  if(exclui==1)
  {
    remove("adm.bin");
    if (rename("temp.bin", "adm.bin") != 0)
    {
      perror("Erro ao renomear o arquivo");
      exit(1);
    }
    printf("Tema excluido com sucesso!\n");
    remove("temp.bin");
  }
  getch();
  return 0;
}
