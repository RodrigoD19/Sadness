
#ifndef _HEADER_h_
#define _HEADER_h
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <pthread.h>
#include <fcntl.h>

#define FIFO_SRV "tubo"
#define FIFO_CLI "cli_%s"
#define FUSERS "teste.txt"
#define FITEMS "itens.txt"
#define MAX_USERS 20
#define MAX_PROM 10
#define MAX_ITEMS 30

typedef  struct items item;
struct items{
char  categoria[10];
char  nome_item[10];
char vendedor[10];
char licitador[10];
int tempo;
int valor_atual;
int item_id;
int  buy_now;
int price_discount;
};
 typedef struct tipo{    
char msg[50];
char pass[10];
int pid;}tipo1;
 typedef struct tipos {
        char palavra[100];
    }tipo2;

  typedef struct{
    int heart;
    char username[10];
    int saldo;
  } cliente;
  typedef struct {
    int id;
    int valor;
  }buy;
  typedef struct {
    char nome_item[10];
    char categoria[10];
    int preco_base;
    int buy_now;
    int duracao;
  }sell;

typedef struct {
  int tipostr;
  char username[10];
  union{ 
  tipo1 um;
  tipo2 dois;
  item tres;
  cliente quatro;
  buy seis;
  sell sete;
  int retorno;
    }a;

}inf;

#endif

