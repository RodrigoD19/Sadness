//
// Created by rodri on 22/11/2022.
//

#ifndef TRABALHOP_RESERVA_H
#define TRABALHOP_RESERVA_H
#include "Animais.h"
#include "Terminal.h"
class Reserva {
    char ***c;
 int nlinhas, ncol;
 int nanimais, nalimentos;
std::vector<Alimentos*>al;
std::vector<Animais*>an;
public:
    Reserva();
    ~Reserva();
    int getnumlinhas();
    int getnumcolunas();
    int addanimal(int x,int y,char sig, Window &t);
    int addalimento(int x,int y,char sig, Window &t);
    int killanimal();
    char printreserva2(term::Window& tl,int x,int y);
    int askpositions(int **a,char *b);


};


#endif //TRABALHOP_RESERVA_H
