#include <iostream>
#include <cstring>
#include "clsMateria.h"
#include "clsAlumno.h"
#include "funciones.h"

using namespace std;


void Materia::setNumero(int n){
    numero = n;
}
int Materia::getNumero(){
    return numero;
}
void Materia::setCantidadAlumnos(int cA){
    cantidadAlumnos = cA;
}
int Materia::getCantidadAlumnos(){
    return cantidadAlumnos;
}
void Materia::setCantidadDocentes(int cD){
    cantidadDocentes = cD;
}
int Materia::getCantidadDocentes(){
    return cantidadDocentes;
}
void Materia::setNombre(const char *n){
    strcpy(nombre, n);
}
const char *Materia::getNombre(){
    return nombre;
}

void Materia::setEstado(bool e){
    estado = e;
}

bool Materia::getEstado(){
    return estado;
}

void Materia::Cargar(){
    cout<<"NUMERO DE MATERIA: ";
    cin>>numero;
    cout<<"NOMBRE DE LA MATERIA: ";
    cargarCadena(nombre, 49);
    cout<<"CANTIDAD DE ALUMNOS: ";
    cin>>cantidadAlumnos;
    cout<<"CANTIDAD DE DOCENTES: ";
    cin>>cantidadDocentes;
    estado = true;
}

void Materia::Mostrar(){
        cout<<"NUMERO DE MATERIA: "<<numero<<endl;
        cout<<"NOMBRE DE LA MATERIA: "<<nombre<<endl;
        cout<<"CANTIDAD DE ALUMNOS: "<<cantidadAlumnos<<endl;
        cout<<"CANTIDAD DE DOCENTES: "<<cantidadDocentes<<endl<<endl;
}


Materia::Materia(int num, const char *nom, int cA, int cD){
    numero = num;
    strcpy(nombre, nom);
    cantidadAlumnos=cA;
    cantidadDocentes=cD;
}

Materia::~Materia(){

}
