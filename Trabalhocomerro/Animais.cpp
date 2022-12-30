//
// Created by rodri on 22/11/2022.
//

#include <cstring>
#include "Animais.h"
#include "Reserva.h"
Animais::Animais(int posX,int posY, char letra) {

    posx =posX;
    posy = posY;
    sig=letra;

    //std::cout<<a.pa();
            //rand()%(500-16 + 1) + 16;
   // t << "Criei o animal "<<Sigla<<"\n";
  //  t << "INTRODUZA ALGUMA COISA\n";
//    t >> teste;


}

int Animais::getID()  {
    return id;
}


int Animais::getPosX()  {
    return posx;
}

int Animais::getPosY()  {
    return posy;
}

char Animais::getSigla()  {
    return sig;
}



