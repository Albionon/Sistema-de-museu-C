#include "login.h"
#include "administracao.h"
#include "bancodedados.h"



int login()
{
 char ch = '\0';
 char vuser[20],user[20],vsenha[20],senha[20];
 int ctecla=0;

 strcpy(user,"adm"); //Usuário correto
 strcpy(senha,"pim23"); //Senha correta

 memset(vuser, '\0', sizeof(vuser));
 memset(vsenha, '\0', sizeof(vsenha));

 printf("Usuario: ");
 scanf("%s", vuser);
 printf("Senha: ");

 while(ctecla<5)//dando definição nas teclas que o usario pode usar na senha
 {
   ch = getch();

   switch(ch)
   {
    case BACKSPACE:
     if(ctecla>0)
     {
      fflush(stdin);
      putch(BACKSPACE);
      ch = '\0';
      vsenha[ctecla] = ch;
      ctecla--;
      putch(SPACE);
      putch(BACKSPACE);
     }
      break;
    case TAB:
     putch(TAB);
     ctecla = 5;
     break;
    case ENTER:
     putch(ENTER);
     ctecla = 5;
     break;
    default:
     vsenha[ctecla] = ch;
     putch('*');
     ctecla++;
     break;
   }
 }

 if(strcmp(user,vuser)==0 && strcmp(senha,vsenha)==0)// fazendo a comparação de string para verificação se a senha  e o usuario estão corretos
 {

   printf("\n\nAcesso permitido!\n\n");

 }
 else
 {
   printf("\n\nAcesso negado!\n\n");
   return 0;
 }

 return 1;//dando o retorno se o acesso foi negado ou autorizado!
}
