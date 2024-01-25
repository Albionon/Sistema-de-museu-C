#ifndef BANCODEDADOS_H_INCLUDED
#define BANCODEDADOS_H_INCLUDED

//Todas as estruturas de dados do sistema

typedef struct {
    int id;
    char nome[100];
    char descricao[500];
    char obra1[500];
    char obra2[500];
    char obra3[500];
    char obra4[500];
} Dados;

typedef struct
{
  char nome[30];
  char cpf[12];
} User;


#endif
