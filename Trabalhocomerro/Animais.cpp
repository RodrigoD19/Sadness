//
// Created by rodri on 22/11/2022.
//

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
Animais::Animais(std::string an , int x, int y) {
    std::string var[7] =  {"o","c"};
    Reserva r;
    if(var[2]==an){
        Animais d(30,100,35,6,9,'O');
        r.addanimal(x,y,'O',d);
    }

}
int Animais::getID() const {
    return id;
}


int Animais::getPosX() const {
    return posx;
}

int Animais::getPosY() const {
    return posy;
}

char Animais::getSigla() const {
    return sig;
}

void Animais::Animaiscreatal(char animal) {


}



/*void Animais::setPos( int x, int y)  {
    posx=x;
    posy=y;
}*/
