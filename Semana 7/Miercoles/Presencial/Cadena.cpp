#include <iostream>
#include <cstring>

using namespace std;

class Cadena{
    private:
        int tam;
        char *texto;
    public:
        Cadena(const char *t);
        ~Cadena();
        const char *getTexto();
        void setTexto(const char *t);
        void Concatenar(const char *t);
};


Cadena::Cadena(const char *t){
    tam = strlen(t);
    texto = new char[tam+1];
    if(texto == nullptr) exit(-1);
    strcpy(texto, t);
}

Cadena::~Cadena(){
    delete[] texto;
}

const char *Cadena::getTexto(){
    return texto;
}

void Cadena::setTexto(const char *t){
    delete[] texto;
    tam = strlen(t);
    texto = new char[tam + 1];
    if(texto == nullptr) exit(-1);
    strcpy(texto, t);
}

/**
DESARROLLA EL METODO CONCATENAR. EL MISMO DEBE RECIBIR UNA CADENA DE CARACTERES
Y AGREGARSELA AL FINAL DE LA CADENA EXISTENTE EN EL OBJETO.
*/

int main(){
    Cadena obj("HOLA");
    cout<<obj.getTexto()<<endl;
    obj.Concatenar(" MUNDO!");
    cout<<obj.getTexto()<<endl; ///HOLA MUNDO!
    return 0;
}
