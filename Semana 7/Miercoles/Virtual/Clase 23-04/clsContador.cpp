#include <iostream>
#include "clsContador.h"

using namespace std;

void Contador::incrementar(){
    valor++;
}
void Contador::decrementar(){
    valor--;
}
void Contador::mostrar(){
    cout<<valor<<endl;
}
int Contador::getValor(){
    return valor;
}
void Contador::setValor(int v){
    valor = v;
}

Contador::Contador(int v){
    valor = v;
    valorInicial = v;
}
void Contador::reiniciar(){
    valor = valorInicial;
}
