#include "header.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "Animais.h"
#include "Terminal.h"
using namespace std;
using namespace term;
void addanimal(Animais& a,Reserva& b){
    b.addanimal(a.getPosX(),a.getPosY(),a.getSigla(),a);
}


int main() {

    Terminal &t = Terminal::instance();
    Window TL= Window(0,0,42,22);
    Window RT=Window(50,0,60,10);
    Window RD=Window(50,12,60,15);
    string  s,o;

    RT<<"Bem vindo a simulacao\n";

    Reserva a;
    Animais b(20,30,5,6,9,'u');
    Animais c(2,5,5,6,9,'u');
    addanimal(b,a);
    addanimal(c,a);
    // a.printreserva2(TL,0,0);




//   RD<<a.search(4,5);

    string comandos=" ",aux=" ";

    RT << "Deseja ler os dados de um ficheiro?(y/n)\n";
    int po;
    RT>>aux;
    if(aux=="y"){
        RT<<"Quer ver o ficheiro constantes?(y/n)";
        RT>>aux;
        if(aux=="y"){
            po=1;
            RT<< "Vou abrir o ficheiro e mostrar toda a informacao:\n";
            InfoFicheiro("Constantes.txt",RD,po); }
        RT<<"Deseja ver o ficheiro dos comandos)(y/n)";
        RT>>aux;
        if(aux=="y"){
            po=2;
            RT<< "Vou abrir o ficheiro e mostrar toda a informacao:\n";
            InfoFicheiro("Comandos.txt",RD,po); }




    }
    RT.getchar();
    RD.clear();
    int x=0,y=0;
    a.printreserva2(TL,0,0);
    do{
        RT.clear();
        RT<<"Para movimentar a reserva clique numa das setas\n";
        RT << "Introduza um comando: ";
        RT>>comandos;
      //  if (comandos=="exit") break;
        if(comandos=="KEY_UP") {
            if(x>0){
                x--;
                a.printreserva2(TL,x,y);
            }
        }
        else if(comandos=="KEY_DOWN"){
            if(x+10<a.getnumlinhas()){
                TL<<"AA";
                x++;
                a.printreserva2(TL,x,y);
            }
        }
        else if(comandos=="KEY_LEFT"){
            if(y>0){
                y--;
                a.printreserva2(TL,x,y);
            }
        }
        else if(comandos=="KEY_RIGHT"){
            if(y+20<a.getnumcolunas()){
                y++;
                a.printreserva2(TL,x,y);
            }
        }
        else{
            RD.clear();
            VerificaComandos(RD,comandos);}
        /*RT << "Deseja voltar a ver o menu dos comandos?(y/n)\n";
      RT>>auxmenu;
      if(auxmenu == "y"){
      menucomandos(t); }*/
    }while(comandos != "exit");


}
