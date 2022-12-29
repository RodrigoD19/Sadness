//
// Created by rodri on 22/11/2022.
//

#ifndef TRABALHOP_ANIMAIS_H
#define TRABALHOP_ANIMAIS_H
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Alimentos.h"
#include "Terminal.h"
using namespace term;

class Animais {
public:
    Animais(int Vida,int Fome, int TVidaa,int Peso, int ID, char animal);
    void Animaiscreatal(char animal);
    Animais(std::string animal , int x, int y);
    int getID() const;

    char getSigla() const;

    int getPosX() const;

    int getPosY() const;

    //void setPos( int x, int y) ;


private:
    char sig;
    int posx,posy;
    int id;
int saude;
int fome;
int peso;
int tvida;
Alimentos pref;

//std::vector<Alimentos*> hist; Nao podemos usar

};


class ovelha: public Animais{
public:
    ovelha();
    ~ovelha();

    int saude  ;
    int fome  ;
    int peso;
    int tvida;
};
class lobo: public Animais{
public:
    lobo();
    ~lobo();
};
class coelho: public Animais{
public:
    coelho();
    ~coelho();
};
class canguro: public Animais{
public:
    canguro();
    ~canguro();
};




#endif //TRABALHOP_ANIMAIS_H
