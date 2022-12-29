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
    ncol=100;
    nlinhas=100;
    c= new char **[100];
    for(int i=0;i<100;i++){
        c[i]=new char*[100];
        for(int j=0;j<100;j++){
            c[i][j]=new char[3];
            c[i][j]="-";
        }
    }
    /*c[0][0]="A";
    c[8][10]="BA";
    c[10][7]="C";
    c[99][99]="R";*/
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

char Reserva::printreserva(term::Window& tl,int x,int y) {
    tl.clear();
    for(int i=x;i<x+10;i++){
        for(int j=y;j<y+20;j++){
            tl<<c[i][j]<<" ";
        }
        tl<<"\n";
    }

    return 0;
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
    char *p= new char[1];
    strcpy(p,&sig);
    c[x][y]=p;
    an.push_back(&a);
    delete p;
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
    //  int **p=new int * [2];
    //  p[0]=new int[nanimais+1];//new int [animais+alimentos+1]
    //  p[1]=new int [nanimais+1];
    // char *a=new char[nanimais];
    //  askpositions(p,a);
    for(int i=x;i<x+10;i++){
        for(int j=y;j<y+20;j++){
            for(int f=0;f<nanimais;f++){//nanimais+ nalimentos
                if(i==an[f]->getPosX()&&j==an[f]->getPosY()){
                    tl<<an[f]->getSigla();
                    it=1;
                }
                /*if(i==al[f]->getPosX()&&j==al[f]->getPosY()){
                    tl<<al[f]->getSigla();
                    it=1;
                }*/
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

    //delete []p[0];
    //delete []p[1];
    //delete []p;
    //delete[]a;
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





