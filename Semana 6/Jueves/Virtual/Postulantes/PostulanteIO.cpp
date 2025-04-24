#include <iostream>
#include "PostulanteIO.h"
using namespace std;

PostulanteIO::PostulanteIO()
: Postulante(){
  
}

PostulanteIO::PostulanteIO(Postulante postulante)
: Postulante(postulante){
  
}

void PostulanteIO::cargar(){
  int id, edad, experiencia;
  bool contratado;
  string nombre, apellido, puesto;
  
  cout << "ID: ";
  cin >> id;
  
  cout << "Nombre: ";
  cin.ignore();
  getline(cin, nombre);
  
  cout << "Apellido: ";
  getline(cin, apellido);
  
  cout << "Edad: ";
  cin >> edad;
  
  cout << "Puesto: ";
  cin.ignore();
  getline(cin, puesto);
  
  cout << "Experiencia: ";
  cin >> experiencia;
  
  cout << "Contratado: ";
  cin >> contratado;
  
  setId(id);
  setNombre(nombre);
  setApellido(apellido);
  setEdad(edad);
  setPuesto(puesto);
  setExperiencia(experiencia);
  setContratado(contratado);
}

void PostulanteIO::mostrar(){
  cout << "ID: " << getId() << endl;
  cout << "Nombre: "<< getNombre() << endl;
  cout << "Apellido: " << getApellido() << endl;
  cout << "Edad: " << getEdad() << endl;
  cout << "Puesto: " << getPuesto() <<endl;
  cout << "Experiencia: " << getExperiencia() <<endl;
  cout << "Contratado: " << getContratado() << endl;
}
