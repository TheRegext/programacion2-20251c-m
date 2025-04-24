#include <string>
#include <cstring>
#include "Postulante.h"

using namespace std;

Postulante::Postulante(){
    _id = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    _edad = 0;
    strcpy(_puesto, "");
    _experiencia = 0;
    _contratado= false;
}

Postulante::Postulante(int id, string nombre, string apellido, int edad, string puesto, int experiencia, bool contratado){
  setId(id);
  setNombre(nombre);
  setApellido(apellido);
  setEdad(edad);
  setPuesto(puesto);
  setExperiencia(experiencia);
  setContratado(contratado);
}

// GETTERS
int Postulante::getId(){
    return _id;
}

string Postulante::getNombre(){
    return _nombre;
}

string Postulante::getApellido(){
    return _apellido;
}

int Postulante::getEdad(){
    return _edad;
}

string Postulante::getPuesto(){
    return _puesto;
}

int Postulante::getExperiencia(){
    return _experiencia;
}

bool Postulante::getContratado(){
    return _contratado;
}

// SETTERS
void Postulante::setId(int i){
    _id = i;
}

void Postulante::setNombre(string nombre){
  if(nombre.size() < 25){
    strcpy(_nombre, nombre.c_str());
  }
}

void Postulante::setApellido(string  apellido){
  if(apellido.size() < 25){
    strcpy(_apellido, apellido.c_str());
  }
}

void Postulante::setEdad(int edad){
  if(edad >= 0){
    _edad = edad;
    }
}

void Postulante::setPuesto(string puesto){
  if(puesto.size() < 50){
    strcpy(_puesto, puesto.c_str());
  }
}

void Postulante::setExperiencia(int experiencia){
  if(experiencia >= 0){
    _experiencia = experiencia;
  }
}

void Postulante::setContratado(bool contratado){
    _contratado = contratado;
}
