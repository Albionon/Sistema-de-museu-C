#include "consultarbl.h"
#include "administracao.h"
#include "bancodedados.h"

int consultarbl()
{
  FILE *arquivo;
  Dados dados;
  int r=1;
#define RESET "\033[0m"
  arquivo = fopen("adm.bin","rb");
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  while(fread(&dados, sizeof(Dados),1,arquivo))
  {
      printf(CYAN "Registro #%d\n",r);//cyan é a cor escolhida para da uma visual melhor para diferenciar os temas
      printf(RESET);
      printf("ID.....: %d\n",dados.id);
      printf("Tema...: %s\n",dados.nome);
      printf("descricao...: %s\n",dados.descricao);
      printf("\n obra#1...: %s\n",dados.obra1);
      printf("\n obra#2...: %s\n",dados.obra2);
      printf("\n obra#3...: %s\n",dados.obra3);
      printf("\n obra#4...: %s\n",dados.obra4);
      printf("-------------------------------\n");
      r++;
  }

  fclose(arquivo);
  getch();
  return 0;
}
