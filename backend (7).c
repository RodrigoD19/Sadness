#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "header.h"
#include "users_lib.h"
#define TAM_PROMOCAO 50
#define RD 0
#define WR 1
char fifo_cli[20];
char *fifos_cli [MAX_USERS];
cliente ativos[MAX_USERS];
int sair=0,threadatuais;
int fd,fc;
int numusers=0;
int pids[10];
void signal_handler(int sig){
	if (sig==SIGUSR1){
		printf("Apanhei te");
	//	sleep(5);
		sair=1;
	}
}
void * heart(void* data){
	int i;
	while(1){
		sleep(30);
		for(i=0;i<numusers;i++){
			if(ativos[i].heart==0){
				kickcliente(ativos[i].username);
				printf("o gajo expulso e o %s",ativos[i].username);
			}
		}
		for(i=0;i<numusers;i++){
			ativos[i].heart=0;
		}

	}
}
void* fazthread(void* data){

	int* canal_re=(int*)data;
char mens[TAM_PROMOCAO];
int nbytes;
while(sair!=1){
//meter ciclo numa thread
	if(sair==1){
		//return;
		printf("entrou aqui");
		//close(canal_re[WR]);
		//int i=threadatuais;
	//	sair=0;
		break;

	}
	nbytes = read(canal_re[RD],mens,TAM_PROMOCAO-1);
	mens[nbytes] = '\0';
	int l=0;
	if(nbytes>0){ 
	printf("%s",mens);
	printf("\n O pid do fork e %d\n",pids[0]);
	int i;
	for(i=0;i<numusers;i++){
	fc=open(&fifos_cli[i],O_WRONLY);
	inf p;
	p.tipostr=3;
	strcpy(p.a.dois.palavra,mens);
	write(fc,&p,sizeof(inf));
	close(fc);
	}
	 }
}
pthread_exit(NULL);
}


int openprom(int faz,pthread_t *tarefa){
setbuf(stdin,NULL);
int i;
 struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigaction(SIGUSR1, &sa, NULL);
	//static pthread_t tarefa[2];
	 printf("o faz ta com %d\n",faz);
//	 getchar();
static int canal_re[2];
if(faz==1){ 
char prom[15]="./";
char op[15];
char palavra[TAM_PROMOCAO];

printf("Deseja ver qual promotor:   ");
fflush(stdin);
scanf("%s",&op);
if(pipe(canal_re) < 0){
	printf("deu erro na cricao do pipe");
	exit(1);

}
int est;
 int pid_son = fork();
if (pid_son == 0){
close(WR);
dup(canal_re[WR]);
close(canal_re[WR]);
close(canal_re[RD]);

	strcat(prom,op);
	execl(&prom,&prom,NULL);
	printf("programa nao encontrado %s",prom);
	return -1;
	

	
}


 
pids[threadatuais]=pid_son;
	threadatuais++;
	if(threadatuais<10){ 
	if(pthread_create(&tarefa[threadatuais],NULL,fazthread,canal_re)!=0){
		printf("Erro a abrir thread");
	//	return -1;
	}
	 }
	//char cmd[10];
	//scanf("%s",&cmd);
	//printf("o comando lido %s",cmd);
	}else{
	//	union sigval value;
	//	sigqueue(pid_son,SIGKILL,value);
	for(i=0;i<threadatuais;i++){  
		pthread_kill(&tarefa[i],SIGUSR1);	
		sair=1;
		kill(pids[i], SIGTERM);
 
		int died = 0;
		for (int loop; !died && loop < 5 /*For example*/ ; ++loop)
	{	
 
    pid_t id;
   //sleep(1); 
   
    //if (waitpid(pids[i], &status, WNOHANG) == pids[i]) died = 1;
	}
	
	//if (!died) kill(pids[i], SIGKILL);
		//break;
	//	pthread_exit(NULL);
	int status[threadatuais];
	  wait(&status[i]);
	}
	sair=0;
	threadatuais=0;
	  
	 }
	 
	// for (i=0;i<threadatuais;i++){
	//	pthread_join(&tarefa[i],NULL);
	 //}
	//printf("Vou sair pelo sigusr 1\n");
	
	

 }
	



int usuarios(char *name,inf p){
    	if(loadUsersFile(name)==-1){
	printf("impossibilidade de abrir o ficheiro");
	return 0;
};	printf ("O user e %s e a pass e %s",p.username,p.a.um.pass);

	if(isUserValid(p.username,p.a.um.pass)!=1){
	printf("\nUsuario Invalido ou password errada\n");
	fc=open(fifo_cli,O_WRONLY);
	p.tipostr=1;
	strcpy(p.a.um.msg,"User Invalido");
	write(fc,&p,sizeof(inf));
	close(fc);
	return 0;
	}
	printf("o numusers e %d",numusers);
	if(numusers<MAX_USERS){
	strcpy(&fifos_cli[numusers],fifo_cli);
	strcpy(ativos[numusers].username,p.username);
	ativos[numusers].heart=1;
	printf("Entrou no array %s e o crl do ativos e %s",&fifos_cli[numusers],ativos[numusers].username);  
	numusers++;	
	fc=open(fifo_cli,O_WRONLY);
	p.tipostr=1;
	strcpy(p.a.um.msg,"User Valido");
	write(fc,&p,sizeof(inf));
	close(fc);}
	else{
	fc=open(fifo_cli,O_WRONLY);
	p.tipostr=1;
	strcpy(p.a.um.msg,"Servidor cheio");
	write(fc,&p,sizeof(inf));
	close(fc);
	}
	return 1;

   //	int saldo= getUserBalance(userv); 
 //	printf("O saldo agora e %d\n",saldo);
   // 	saldo=saldo-1;
    //	updateUserBalance(userv,saldo);	
//	printf("o saldo apos e %d\n ",saldo);
//	char h[]= "./";
//	strcat(h,name);
//	printf("o h e %s\n", h);
  //  	saveUsersFile(h);
}
int openitens(item *p){
char str[200];
int a=0;
FILE *f= fopen("./itens.txt", "r");
if(!f){fprintf(stderr, "Erro a abrir o ficheiro dos itens\n");
return -1;
}
while(fgets(str,sizeof(str),f)!=NULL){
sscanf(str,"%d %s %s %d %d %d %s %s", &p[a].item_id,p[a].nome_item,p[a].categoria,
&p[a].valor_atual,&p[a].buy_now,&p[a].tempo,p[a].vendedor, p[a].licitador);
a++;
}
//printf("DONE");
fclose(f);
return a;
}
int validar ( char *valid){
int i = 0;
int a;
char *enter="\n" ;
printf("|%s|\n", valid);
char vender[][7] ={ "users","list","kick","prom","reprom","cancel","close"};
    int j = strlen(valid);
   // printf("|%c|",valid[j]);
    //printf("|%c|",valid[j]);

    if(valid[j-1]==*enter){
            //printf("aboo");
        j--;
    }

while(i < 11){
        int h = strlen(vender[i]);

a= strncmp(valid,vender[i],h);
//printf("\nO valor da comparacao e %d",a);
        if(j  == h){
if(a==0){

//printf("\ncomando:%s",vender[i]);
return i;
}
        }
i++;

}
return -1;

}

void validar_parametros(int com,int n_parametros){

if(com== 1|| com == 0 || com == 3 || com == 4|| com == 6){
if(n_parametros!=1)
printf("Numero de parametros invalido");}
else if( com == 2|| com ==5 ){
if(n_parametros!=2)
printf("Numero de parametros invalido");}




}


void comandos() {
fflush(stdin);
int i=0;
int com=15;
char string[60];
printf("Inserir comando: ");
scanf("%s",string);
char *token = strtok(string," ");
com = validar(token);
if(com==-1|| com == 15){
printf("Comando invalido: %d\n",com);

}else {
printf("Comando Válido\n");
//printf("Valor do com e %d\n",com);
}
while(token != NULL){
  token = strtok(NULL," ");
i++;
}
//printf("\nValor do i %d",i);
validar_parametros(com,i);
}
void mostraitens(item *p, int num){
int i;
//inf k;
//item *l;
//l=k.a.tres;
//printf("entrou aqui");
if(num==0){
printf("Nao ha itens restantes de outros leiloes");}
for(i=0;i<num;i++){
printf("\nItem: %d %s %s %d %d %d %s %s\n",p[i].item_id,p[i].nome_item,p[i].categoria,
p[i].valor_atual,p[i].buy_now,p[i].tempo, p[i].vendedor, p[i].licitador);
}
fflush(stdin);
getchar();

}
int fecharpromotores(){
	sair=1;
 union sigval value;
 printf("ALA");
  struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigaction(SIGUSR1, &sa, NULL);
// menu();
return 0;

}

void tratasinais(){
	
	inf u;
	u.tipostr=9;
	sair=1;
	int i;
	for(i=0;i<numusers;i++){
	fc=open(&fifos_cli[i],O_WRONLY);
	write(fc,&u,sizeof(inf));
	close(fc);}
close(fd);
close(fc);
unlink(FIFO_SRV);
printf("\nClosing program\n");	
exit(0);
}


void kickcliente(char *nome)
{   
    int a;
    char *token;
    inf p;
    int i;
	printf("O fifos cli tem %s\n",&fifo_cli[0]);
    for(i=0;i<numusers;i++)
    {  char * tokena= strtok(&fifos_cli[i],"_");
        tokena=strtok(NULL," ");
		strcpy(&token,&tokena);
		printf("O token e %s ",token);
        if(strcmp(token,nome)==0){
            a=1;
            break;
        }
    }
    if(a==1){ 
    char fifo[20]="cli_";
    strcat(fifo,token) ;
	printf("o fifo e %s",fifo);
    p.tipostr=4;
    fc=open(fifo,O_WRONLY);
	write(fc,&p,sizeof(inf));
	close(fc);
    for(;i<numusers;i++){
        strcpy(&fifos_cli[i],&fifos_cli[i++]);
		strcpy(&ativos[i].username,&ativos[i++].username);
		ativos[i].heart=ativos[i++].heart;
    }
    numusers--;
    }
    else{
        printf("Nome nao encontrado");
    }
}

int main(int argc, char* argv[]){
system("clear");
pthread_t tarefa[10];
setbuf(stdout,NULL);
 struct sigaction sa;
    sa.sa_handler = tratasinais;
    sigaction(SIGINT, &sa, NULL);

inf p,r;
item item[MAX_ITEMS];
pthread_t heartbeat;
pthread_create(&heartbeat,NULL,heart,NULL);
int check,nbytes;
int numitem,usrv,res;
fd_set fds;
numitem=openitens(item);
if(access(FIFO_SRV,F_OK)!=0){
mkfifo(FIFO_SRV,0666);
}
fd=open(FIFO_SRV,O_RDWR);
if(fd==-1){
printf("Erro na abertura do FIFO\n");
unlink(FIFO_SRV);
exit(1);
}
if(numitem==-1){
fprintf(stderr,"Erro a abrir os itens");
}

printf("Opening program");
//int check;
while(1){
		//getchar();
	//	fflush(stdin);
	    sleep(3);
		system("clear");
        printf("\nO que deseja fazer\n");
        printf("\n(1)Testar Comandos\n(2)Lancar o promotor\n(3)Ler os utilizado\n(4)Ler os itens\n(5)Sair\n(6)cancelar os proms\n");
        printf("Escolha o numero correspondente a sua opcao: ");
	
		FD_ZERO(&fds);
		FD_SET(0,&fds);		
		FD_SET(fd,&fds);
		res=select(fd+1,&fds,NULL,NULL,NULL);
		if(res==-1){
			printf("Erro no select");
		}
         if(res>0 && FD_ISSET(fd,&fds)){   
     	nbytes=read(fd,&r,sizeof(inf));
	//	printf("o tipo de struct e %d\n",r.tipostr);
		sprintf(fifo_cli,FIFO_CLI,r.username);
		//sell  *p=s.cmd.type2;
		if(r.tipostr==1){
			tipo1  y=r.a.um;
			printf("recebi do %s",r.username);
			printf("o num users enviado e %d\n",numusers);
			usuarios("teste.txt",r);
			
		}
		if(r.tipostr==2){
			printf("o que ele escreve foi %s",r.a.dois.palavra);
			fc=open(fifo_cli,O_WRONLY);
			p.tipostr=2;
			strcpy(p.a.dois.palavra,"ANDA LA");
			write(fc,&p,sizeof(inf));
			close(fc);
		}
		if(r.tipostr==5){
			int i=0;
			for(i=0;i<numusers;i++){
				printf("OH pa %s e ta %s\n\n",ativos[i].username,r.username);
				if(strcmp(ativos[i].username,r.username)==0) break;
			}
			ativos[i].heart=1;
			printf("O ativos %s ta com o heart a %d\n",ativos[i].username,ativos[i].heart);
		}
		}
		  if(res>0 && FD_ISSET(0,&fds)){ 
			fflush(stdin);
scanf("%d",&check);
printf("o check e %d",check);
switch(check){
 case 1:system("clear");
        comandos();
        break;
 case 2:system("clear");
		openprom(1,&tarefa);
        break;
 case 3:system("clear"); 
        //usuarios(FUSERS,r);
        break;
 case 4:system("clear");
        mostraitens(item,numitem);
		getchar();
        break;
 case 5:system("clear");
        tratasinais();
	return 0;
case 6:system ("clear");
	   openprom(2,&tarefa);
	break;
case 7:
        kickcliente("rod");
		getchar();
		break;
default:getchar();
		printf("Numero invalido");
	    break;
} 
}


}
}
