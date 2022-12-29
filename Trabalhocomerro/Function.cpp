//
// Created by rodri on 22/11/2022.
//

#include "header.h"
#include "Animais.h"
#include <iostream>
#include <sstream>
#include <cstdlib>



using namespace std;

bool InfoFicheiro(const std::string &fPath,term::Window& t,int po){
    t.clear();
    // t<<fPath<<"\n";
    ifstream ficheiro(fPath, ios::in);
    string linha,nome;
    int saude, peso,tempo_vida;



    if(ficheiro.is_open()){//Se o ficheiro foi aberto corretamente, então...
        while(getline(ficheiro,linha)) {
            if(po==1){
                istringstream uwu (linha);
                t <<"Comando no ficheiro: "<<linha<<"\n";
                if(linha.empty()){
                    t<<"Nao ha mais comandos";
                    break;
                }
                if(linha[0]=='S') {
                    //Caso o comando seja S => Seja um comando para a saude inicial dos animais
                    uwu >> nome;
                    uwu >> saude;
                    if (saude <= 1) {
                        t << "saude do animal invalida!\n\n";
                    }
                    else {
                        if (nome == "SCoelho") {
                            t << "vou adicionar o valor " << saude << " como vida do coelho\n";
                        } else if (nome=="SOvelha") {
                            t << "vou adicionar o valor " << saude << " como vida do Ovelha\n";
                        } else if (nome == "SLobo") {
                            t << "vou adicionar o valor " << saude << " como vida do Lobo\n";
                        } else if (nome == "SCanguru") {
                            t << "vou adicionar o valor " << saude << " como vida do Canguru\n";
                        }
                            //Caso nao seja nehum dos animais acima referidos
                        else {
                            t << "animal nao encontrado na reserva\n\n";
                        }
                    }
                }
                else if(linha[0]=='P'){
                    //Caso o comando seja P => Seja um comando para o peso inicial dos animais
                    uwu >> nome;
                    uwu >> peso;
                    // cout<<"NEVER GONNA GIVE YOU UP!"<<endl;
                    if(peso <= 1){
                        t << "peso do animal invalido\n\n";
                    }
                    else{
                        if(nome=="PCoelho"){
                            t << "vou adicionar o valor "<<peso<<" como peso do coelho\n";
                        }
                        else if(nome=="POvelha"){
                            t << "vou adicionar o valor "<<peso<<" como peso do ovelha\n";
                        }
                        else if(nome=="PLobo"){
                            t << "vou adicionar o valor "<<peso<<" como peso do lobo\n";
                        }
                        else if(nome=="PCanguru"){
                            t << "vou adicionar o valor "<<peso<<" como peso do canguru\n";
                        }
                        else{
                            //Caso nao seja nehum dos animais acima referidos
                            t << "Erro, animal nao encontrado na reserva\n\n";
                        }
                    }
                }
                else if(linha[0]=='V') {
                    //Caso o comando seja V => Seja um comando para o tempo de vida dos animais
                    uwu >> nome;
                    uwu >> tempo_vida;
                    if (tempo_vida <= 1) {
                        t << "peso do animal invalido\n\n";
                    }
                    else{
                        if (nome == "VCoelho") {
                            t << "vou adicionar o valor " << tempo_vida << " como tempo de vida do coelho\n";
                        } else if (nome == "VOvelha") {
                            t << "vou adicionar o valor " << tempo_vida << " como tempo de vida do ovelha\n";
                        } else if (nome == "VLobo") {
                            t << "vou adicionar o valor " << tempo_vida << " como tempo de vida do lobo\n";
                        } else if (nome == "VCanguru") {
                            t << "vou adicionar o valor " << tempo_vida << " como tempo de vida do canguru\n";
                        }
                            //Caso nao seja nehum dos animais acima referidos
                        else {
                            t << "Erro, animal nao encontrado na reserva\n\n";
                        }
                    }
                }
                else{
                    //Caso nao seja um comando de status inicial de um animal, entao
                    t << "Comando invalido no ficheiro.\n";
                }

                if(uwu.fail()){//Verificação para caso o stringstream falhe na copia da informação
                    uwu.clear();
                    nome="";
                    saude=peso=tempo_vida= -1;
                }} else{ VerificaComandos(t,linha);}
            t<<"\nPrima enter para ver o proximo comando";
            t.getchar();
            t.clear();
        }
    }
    else {
        t << "Erro na abertura do ficheiro\n";
        return false;
    }
}


int VerificaComandoUtilizador(const string FirstWord){
    int i;
    string var[18] ={"animal","killid","kill","food","feed","feedid","nofood","empty","see","info","n","anim","visanim","store","restore","load","slide","exit"};
    while ( i < 18){
        //cout << "Alface"<< endl;
        if(FirstWord.compare(var[i])==0) {

            return i + 1;
        }
        i++;
    }

    return -1;//Caso o comando n seja um dos comandos disponiveis

}
int isNumber(const string& Word){

    for (char const &ch : Word) {
        if (std::isdigit(ch) == 0)
            return 0;
    }
    return 1;

}

int VerificaComandos(term::Window& t,const string& comandos){

    int verify,coloalea,linhalea ,v2,v3,v4,v5,va,x,y;
    string First,Second,Third,Fourth,Fifth,Auxiliar;
    coloalea = rand()%(500-16 + 1) + 16;
    linhalea = rand()%(500-16 + 1) + 16;

    istringstream  ua(comandos);

    ua >> First;ua >> Second;ua >> Third;ua >> Fourth;ua >> Fifth;ua     >> Auxiliar;

    verify= VerificaComandoUtilizador(First);
    v2= isNumber(Second);
    v3= isNumber(Third);
    v4= isNumber(Fourth);
    v5= isNumber(Fifth);


   switch (verify){
        case -1: t<<"comando invalido";
            return -1;
        case 1:{
            if(v2==1 || (v2 == 0 && (v3!=1 || v4!=1)) ){t<<"possuis valores mal posicionados";break;}
            if(Fourth != "" && Fifth == ""){
                t << "acabou de acrescentar um animal do genero "<<Second<<" na linha "<<Third<<" coluna "<<Fourth ;
                x=stoi(Third);
                y=stoi(Fourth);
                //Animais a(Second,x,y,R);
                break;
            }
            if(Third == "" && Second != ""){
                t << "acabou de acrescentar um animal do genero "<<Second<<" na linha "<<coloalea<<" coluna "<<linhalea<<"de forma aleatoria";
                break;
            }
            else{
                t << "Erro ao criar um animal na reserva" ;
                break;
            }
        }
        case 2:{
            if(v2 !=1){t<< "possuis valores mal posicionados";break;}
            if(Second != ""){
                t << "Vou eliminar o animal com o id"<<Second ;
                 break;
            }
            else {
                t << "Erro ao tentar matar animal he is a god and cannot be killed" ;
                break;
            }
        }
        case 3:{
            if(v2!=1 || v3!=1){t<< "possuis valores  mal posicionados";break;}
            if(Third!=""){
                t << "Irei eliminar o animal na linha "<<Second<<"  coluna "<<Third ;
                break;
            }
            else {
                t << "Erro ao tentar matar animal he is a god and cannot be killed" ;
                break;
            }
        }
        case 4:{
            if(v2!=0 || (v3!=1 && v4!=1)){t<< "possuis valores mal posicionados";break;}
            if(Third=="" && Second !=""){
                t << "Adicionando alimento aleatoriamente na linha "<<linhalea<<" coluna"<< coloalea ;
                break;

            }
            if( Fourth!="" && Fifth==""){
                t << "Adicionando alimento na linha "<<Third<<" coluna"<< Fourth ;
                break;
            }
            else{
                t<< "Erro ao tentar adicionar comida";
                break;
            }
        }
        case 5:{
            if(v2!=1 || v3!=1 || v4!= 1 || v5!=1){t<< "possuis valores mal posicionados";break;}
            if(Auxiliar=="" && Fifth!="" ){
                t<< "Alimentando o animal na linha "<< Second<< " coluna " << Third << " que possuem " << Fourth<< " pontos nutritivos e "<< Fifth << "de toxicidade";
                break;
            }
            else{
                t << "Erro ao alimentar o animal " ;
                break;
            }
        }
        case 6:{
            if(v2!=1 || v3!=1 || v4!= 1 ){t<< "possuis valores mal posicionados";break;}
            if(Fourth!="" && Fifth=="" ){
                t<< "Alimentando o animal com "<< Second<< "de id que possuem" << Third<< "pontos nutritivos e "<< Fourth << "de toxicidade";
                break;
            }
            else{
                t << "Erro ao alimentar o animal " ;
                break;
            }
        }
        case 7:{
            if(v2!=1 || v3!= 1){t<< "possuis valores mal posicionados";break;}
            if(Third!="" && Fourth== ""){
                t << "Removendo a comida na linha "<<Second<< " coluna "<<Third  ;
                break;
            }
            if(Second!="" && Third== ""){
                t << "Removendo a comida com id "<< Second ;
                break;
            }
            else{
                t << "Erro ao remover alimentar o animal " ;
                break;
            }
        }
        case 8:{
            if(v2!=1 || v3!= 1){t<< "possuis valores mal posicionados";break;}
            if(Fourth=="" && Third!=""){
                t << "Acabou de eliminar o que estava na linha"<< Second << " coluna " << Third  ;
                break;
            }
            else{
                t << "Erro ao eliminar na reserva " ;
                break;
            }
        }
        case 9:{
            if(v2!=1 || v3!= 1){t<< "possuis valores mal posicionados";break;}
            if(Fourth=="" && Third!=""){
                t << "Adquirindo informacao sobre a linha"<< Second << " coluna " << Third  ;
                break;
            }
            else{
                t << "Erro ao obter informacao " ;
                break;
            }
        }
        case 10:{
            if(v2!=1 ){t<< "possuis valores mal posicionados";break;}
            if(Second!="" && Third==""){
                t << "Adquirindo informacao sobre o id"<< Second  ;
                break;
            }
            else{
                t << "Erro ao obter informacao " ;
                break;
            }
        }
        case 11 :{
            if(v2!=1 || v3!= 1){t<< "possuis valores mal posicionados";break;}
            if(Second != "" && Third == ""){
                t << "Ira avançar "<<Second<< " instantes" ;
                break;
            }
            if(Third != "" && Fourth == ""){
                t << "Ira avançar "<<Second<< " instantes  com um intervalo  de "<<Third ;
                break;
            }
            if(First != "" && Second == ""){
                t << "Ira avançar 1 instancia" ;
                break;
            }
            else{
                t << "Erro ao tentar avancar"  ;
                break;
            }

        }
        case 12:{
            if(First!="" && Second==""){
                t << "Abrindo lista de informacoes sobre todos os animais na reserva "  ;
                break;
            }
            else{
                t << "Erro de sintaxe invalido (numero de parametros errado)"  ;
                break;
            }
        }
        case 13:{
            if(First!="" && Second==""){
                t << "Abrindo lista de informacoes sobre todos os animais visiveis na reserva  "  ;
                break;
            }
            else{
                t << "Erro de sintaxe invalido (numero de parametros errado)"  ;
                break;
            }

        }
        case 14:{
            if(v2!=0){t<< "possuis valores mal posicionados";break;}
            if(Second!= "" && Third ==""){
                t << "Guardando reserva "  ;
                break;
            }

        }
        case 15:{
            if(v2!=0){t<< "possuis valores mal posicionados";break;}
            if(Second!= "" && Third ==""){
                t << "Restaurando reserva ..." ;
                break;
            }
        }
        case 16:{
            if(v2!=0){t<< "possuis valores mal posicionados";break;}
            if(Second!= "" && Third ==""){
                t << "A usar reserva guardada"  ;
                break;
            }
        }
        case 17:{
            if(v2!=0 || v3!=1 || v4!= 1){t<< "possuis valores mal posicionados";break;}
            if(Second!= "" && Fifth ==""){
                t << "Movendo  "<< Third<< " linhas e "<< Fourth <<" colunas com orientacao " << Second  ;
                break;
            }
        }
        case 18:{
            t << "A sair...";
            break;
        }
    }
    return 0;
}


