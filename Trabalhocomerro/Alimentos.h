//
// Created by rodri on 22/11/2022.
//

#ifndef TRABALHOP_ALIMENTOS_H
#define TRABALHOP_ALIMENTOS_H
#include <iostream>
class Alimentos{
std::string tipo;
std::string cheiro;
int validade;
int tox;
int nut;
int posx,posy;
int id;
public:
    Alimentos() {
std::cout<<"A criar alimentos";
    }

    ~Alimentos() {

    }

};


#endif //TRABALHOP_ALIMENTOS_H
