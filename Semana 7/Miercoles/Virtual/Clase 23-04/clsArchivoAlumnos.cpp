#include <iostream>
#include <cstring>
#include "clsArchivoAlumnos.h"
#include "clsAlumno.h"

ArchivoAlumnos::ArchivoAlumnos(const char *n){
    strcpy(nombre, n);
}

Alumno ArchivoAlumnos::leerRegistro(int pos){
    Alumno obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        obj.setLegajo(-2);
        return obj;
    }
    obj.setLegajo(-1);
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoAlumnos::grabarRegistro(Alumno obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoAlumnos::modificarRegistro(Alumno obj, int pos){
    FILE *p;
    p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoAlumnos::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Alumno);
}

int ArchivoAlumnos::buscarRegistro(int leg){
    Alumno obj;
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getLegajo() == leg){
            return i;
        }
    }
    return -1;
}
