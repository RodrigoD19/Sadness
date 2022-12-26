#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "header.h"
int fd,fc;
char fifo_cli[50];
int vivo,sair;
void * heart(void *data){
        char*d=(char*)data;
        inf p;
        strcpy(p.username,d);
while(1){
        sleep(10);
        p.tipostr=5;
        
        write(fd,&p,sizeof(inf));
}


}
int validar ( char *valid){
int i = 0;
int a;
char *enter="\n" ;
printf("|%s|\n", valid);
char vender[][7] ={ "sell","list","licat","lisel","lival","litime","time","buy","cash","add","exit"};
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

if(com==0){ if(n_parametros!=6 )
printf("Numero de paramteros invalido");}
else if(com== 1|| com == 6 || com == 8 || com == 10){
if(n_parametros!=1)
printf("Numero de parametros invalido");}
else if( com == 2 || com == 3 || com == 4 || com ==5 || com == 9){
if(n_parametros!=2)
printf("Numero de parametros invalido");}
else if(com == 7){
if(n_parametros!=3)
printf("Numero de parametros invalido");}




}
void tratasinais(){
close(fd);
close(fc);
unlink(fifo_cli);
printf("Closing program");	
exit(0);
}
int main(int argc, char *argv[]) {
if(argc!=3){
printf("Numero de argumentos invalido\n");
exit(-1);
}
system("clear");
signal(SIGINT,tratasinais);
setbuf(stdout,NULL);
inf p,r;
fd_set fds;
pthread_t heartbeat;
pthread_create(&heartbeat,NULL,heart,argv[1]);
strcpy(p.username,argv[1]);
strcpy(p.a.um.pass,argv[2]);
p.a.um.pid=getpid();
//rintf("o username %s e o argv[1] e %s",p.username,argv[1]);
int nbytes;
char cmd[50];
setbuf(stdout,NULL);
sprintf(fifo_cli,FIFO_CLI,argv[1]);
if(access(fifo_cli,F_OK)!=0){
mkfifo(fifo_cli,0666);
}
fd=open(FIFO_SRV,O_WRONLY);
if(fd == -1){
printf("Erro na abertura do servidor\n");
unlink(fifo_cli);
exit(1);
}
fc=open(fifo_cli,O_RDWR);
if(fc==-1){
printf("Erro na abertura do cliente\n");
unlink(fifo_cli);
exit(1);
}
int res;
p.tipostr=1;
write(fd,&p,sizeof(inf));
read(fc,&r,sizeof(inf));
printf("%s",r.a.um.msg);
if(strcmp(r.a.um.msg,"User Invalido")==0||strcmp(r.a.um.msg,"Servidor cheio")==0){
        unlink(fifo_cli);
        exit(0);
}
close(fc);

while(1){      
        
                fc=open(fifo_cli,O_RDWR);
                FD_ZERO(&fds);
		FD_SET(0,&fds);		
		FD_SET(fc,&fds);
                
                 printf("\npalavras para o server:");
                //fflush(stdin);
         
                res=select(fc+1,&fds,NULL,NULL,NULL);
                if(res==-1){
			printf("Erro no select");}
		
        else if(res>0 && FD_ISSET(fc,&fds)){
                read(fc,&r,sizeof(inf));
   if(r.tipostr==9){
        close(fd);
        close(fc);
        unlink(fifo_cli);
        printf("\no servidor foi encerrado\n");
        exit(0);
} if(r.tipostr==2){
        printf("recebi isto do server %s\n",r.a.dois.palavra);

}
if(r.tipostr==3){
        printf("recebi isto do server %s\n",r.a.dois.palavra);

}
if(r.tipostr==4){
        printf("Cliente expulso pelo servidor\n");
        tratasinais();
}
}
else if(res>0&&FD_ISSET(0,&fds)){
             
             fgets(&p.a.dois.palavra,20,stdin);
             //printf("o que foi escrito e %s",cmdo);
             p.tipostr=2;
             write(fd,&p,sizeof(inf));
}


/*
int i=0;
int com=15;
char string[60];
printf("AA: ");
fgets(string, 60,stdin);
char *token = strtok(string," ");
com = validar(token);
if(com==-1|| com == 15){
printf("Comando invalido: %d\n",com);

}else {
printf("Comando válido");
printf("Valor do com e %d\n",com);}
while(token != NULL){
  token = strtok(NULL," ");
i++;
}
//printf("\nValor do i %d",i);
validar_parametros(com,i);

*/}
}
