//
// Created by rodri on 22/11/2022.
//

#ifndef TRABALHOP_ANIMAIS_H
#define TRABALHOP_ANIMAIS_H
#include <iostream>
#include <string>
#include <vector>
#include "Alimentos.h"
#include "Terminal.h"
class Reserva;
using namespace term;
class Animais {
public:
    Animais(int posX,int posY,char letra);
    int getID() ;
    int ty(const Reserva& a);
    char getSigla() ;

    int getPosX() ;

    int getPosY() ;

private:
    char sig;
    int posx,posy;
    int id;
int saude;
int fome;
int peso;
int tvida;


//std::vector<Alimentos*> hist; Nao podemos usar

};


#endif //TRABALHOP_ANIMAIS_H
