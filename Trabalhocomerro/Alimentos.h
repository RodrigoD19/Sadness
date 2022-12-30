//
// Created by rodri on 22/11/2022.
//

#ifndef TRABALHOP_ALIMENTOS_H
#define TRABALHOP_ALIMENTOS_H
#include <iostream>
class Alimentos{
char tipo;
std::string cheiro;
int validade;
int tox;
int nut;
int posx,posy;
int id;
public:
    Alimentos(int posX,int posY,char p);
    int getPosX();
    int getPosY();
    char gettipo();


    ~Alimentos() ;

};




#endif //TRABALHOP_ALIMENTOS_H
