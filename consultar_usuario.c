#include "consultar_usuario.h"
#include "administracao.h"
#include "bancodedados.h"

int consultar_usuario() {
  FILE *arquivo;
  Dados dados;
  int id_busca, encontrou = 0;
  int r = 1;

  arquivo = fopen("adm.bin", "rb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  while (fread(&dados, sizeof(Dados), 1, arquivo)) {
    printf(CYAN "numero do tema #%d\n", r);
    printf(RESET);
    printf("Tema...: %s\n", dados.nome);
    r++;
  }

  // fechar o programa e abre de novo
  rewind(arquivo);//implamtamos isso para que o usario primeiro soubesse qual era a ordem dos temas para depois pode digitar qual o tema q ele queria ter informações

  printf("Digite o numero do tema : ");
  scanf("%d", &id_busca);

  while (fread(&dados, sizeof(Dados), 1, arquivo)) {
    if (dados.id == id_busca) {
      encontrou = 1;
      printf("Tema encontrado:\n");
      printf("id.....: %d\n", dados.id);
      printf("tema...: %s\n", dados.nome);
      printf("descricao...: %s\n", dados.descricao);
      printf("\n obra#1...: %s\n", dados.obra1);
      printf("\n obra#2...: %s\n", dados.obra2);
      printf("\n obra#3...: %s\n", dados.obra3);
      printf("\n obra#4...: %s\n", dados.obra4);
    }
  }

  fclose(arquivo);

  if (encontrou == 0) {
    printf("Nao ha registro com o valor pesquisado.\n");
  }

  getch();
  return 0;
}
