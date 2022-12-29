//
// Created by rodri on 22/11/2022.
//

#ifndef TRABALHOP_HEADER_H
#define TRABALHOP_HEADER_H
#include <string>
#include <fstream>
#include "curses.h"
#include "Terminal.h"
#include "Reserva.h"
using namespace std;


bool InfoFicheiro(const string &fPath,term::Window& t,int po);
int VerificaComandos(term::Window& t,const string& comandos);

#endif //TRABALHOP_HEADER_H
