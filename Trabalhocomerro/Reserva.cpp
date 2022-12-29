//
// Created by rodri on 22/11/2022.
//o

#include "Reserva.h"
#include <string>
#include <cstring>
#include <sstream>

Reserva::Reserva() {
     int randomCol,randomLin;
    randomCol = rand()%(500-16 + 1) + 16;//Vai gerar um numero aleatorio entre 16-500
    randomLin = rand()%(500-16 + 1) + 16;
    ncol=randomCol;
    nlinhas=randomLin;
}

Reserva::~Reserva() {
    std::cout<<"\nReserva Destruida\n";

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            delete []c[i][j];
        }delete [] c[i];
    }

    delete [] c;
}



int Reserva::getnumlinhas() {
    return nlinhas;
}

int Reserva::getnumcolunas() {
    return ncol;
}

int Reserva::addanimal(int x, int y,char sig,Animais& a) {
  if(x>nlinhas||y>ncol){return -1;}
    nanimais++;
    an.push_back(new Animais (x,y,sig));
  //  t<<"Adicionei o animal com a letra"<< an[0]->getSigla();
    return 0;
}



char  Reserva::search(int x, int y) {
    int na=0;
    char a;
    for(int i=0;i<nanimais;i++){
        if(an[i]->getPosX()==x&&an[i]->getPosY()==y){
            a=an[i]->getSigla();
        }
    }


    return a;
}

char Reserva::printreserva2(Window &tl, int x, int y)
{   int it=0;
    tl.clear();
    int nit;
    if(nanimais>nalimentos){nit=nanimais;}
    else
    {
        nit=nalimentos;
    }
    for(int i=x;i<x+10;i++){
        for(int j=y;j<y+20;j++){
        for(int f=0;f<nit;f++){//nanimais+ nalimentos

            if(i==an[f]->getPosX()&&j==an[f]->getPosY()){
            //    tl<<"TA aqui";
                tl<<an[f]->getSigla();
                it=1;
            }
            if(i==al[f]->getPosX()&&j==al[f]->getPosY()){
                tl<<al[f]->gettipo();
                it=1;}

        }
        if(it==0){
            tl<<"- " ;}
        else{
        it=0;
        tl<<" ";
        }
        }
        tl<<"\n";
    }

}

int Reserva::addalimento(int x, int y, char sig, Window &t) {
    if(x>nlinhas||y>ncol){return -1;}
    nalimentos++;
    al.push_back(new Alimentos(x,y,sig));
    return 0;
}

int Reserva::askpositions(int **a,char *b) {
    int px,py;
    char s;
    for(int i=0;i<nanimais;i++){//i<nanimais+nalimentos
        a[0][i]=an[i]->getPosX();
        a[1][i]=an[i]->getPosY();
        b[i]=an[i]->getSigla();
    }

    return 0;
}





