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
    char printreserva(term::Window& tl,int x,int y);
    int addanimal(int x,int y,char sig,Animais& a);
    int killanimal();
    char printreserva2(term::Window& tl,int x,int y);
    int askpositions(int **a,char *b);
    char search(int x,int y);

};


#endif //TRABALHOP_RESERVA_H
