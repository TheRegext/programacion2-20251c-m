#include <iostream>
#include <cstring>
#include "clsArchivoMaterias.h"
#include "clsMateria.h"

ArchivoMaterias::ArchivoMaterias(const char *n){
    strcpy(nombre, n);
}

Materia ArchivoMaterias::leerRegistro(int pos){
    Materia obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        obj.setNumero(-2);
        return obj;
    }
    obj.setNumero(-1);
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoMaterias::grabarRegistro(Materia obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoMaterias::modificarRegistro(Materia obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr) return false;
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoMaterias::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Materia);
}

int ArchivoMaterias::buscarRegistro(int num){
    /**ESTE METODO RECIBE UN NUMERO DE MATERIA Y
        DEVUELVE LA POSICION DEL REGISTRO QUE TIENE
        ESE NUMERO DE MATERIA. SI NO HAY NINGUNO, DEVUELVE -1.
        */
    Materia obj;
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getNumero() == num){
            return i;
        }
    }
    return -1;
}

void ArchivoMaterias::limpiar(){
    FILE *p = fopen(nombre, "wb");
    if(p == nullptr) return;
    fclose(p);
}
