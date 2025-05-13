#include <iostream>
#include <cstring>
#include "clsMateria.h"
#include "clsAlumno.h"
#include "funciones.h"

using namespace std;

int Alumno::getLegajo(){
    return legajo;
}
const char *Alumno::getNombre(){
    return nombre;
}
const char *Alumno::getApellido(){
    return apellido;
}
int Alumno::getDni(){
    return dni;
}
Fecha Alumno::getFechaNacimiento(){
    return fechaNacimiento;
}
Fecha Alumno::getFechaInscripcion(){
    return fechaInscripcion;
}
const char *Alumno::getEmail(){
    return email;
}
const char *Alumno::getTelefono(){
    return telefono;
}
void Alumno::setLegajo(int l){
    legajo = l;
}
void Alumno::setNombre(const char *n){
    strcpy(nombre, n);
}
void Alumno::setApellido(const char *a){
    strcpy(apellido, a);
}
void Alumno::setDni(int d){
    dni = d;
}
void Alumno::setFechaNacimiento(Fecha fN){
    fechaNacimiento = fN;
}
void Alumno::setFechaInscripcion(Fecha fI){
    fechaInscripcion = fI;
}
void Alumno::setEmail(const char *e){
    strcpy(email, e);
}
void Alumno::setTelefono(const char *t){
    strcpy(telefono, t);
}
void Alumno::setEstado(bool e){
    estado = e;
}
bool Alumno::getEstado(){
    return estado;
}
void Alumno::Cargar(){
    cout<<"INGRESE EL LEGAJO DEL ALUMNO: ";
    cin>>legajo;
    cout<<"INGRESE EL NOMBRE DEL ALUMNO: ";
    cargarCadena(nombre, 29);
    cout<<"INGRESE EL APELLIDO DEL ALUMNO: ";
    cargarCadena(apellido, 29);
    cout<<"INGRESE EL DNI DEL ALUMNO: ";
    cin>>dni;
    cout<<"INGRESE LA FECHA DE NACIMIENTO:"<<endl;
    fechaNacimiento.Cargar();
    cout<<"INGRESE LA FECHA DE INSCRIPCION:"<<endl;
    fechaInscripcion.Cargar();
    cout<<"INGRESE EL EMAIL DEL ALUMNO: ";
    cargarCadena(email, 39);
    cout<<"INGRESE EL TELEFONO DEL ALUMNO: ";
    cargarCadena(telefono, 19);
    estado = true;
}
void Alumno::Mostrar(){
    cout<<"LEGAJO: "<<legajo<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<"FECHA DE INSCRIPCION: ";
    fechaInscripcion.Mostrar();
    cout<<"EMAIL: "<<email<<endl;
    cout<<"TELEFONO: "<<telefono<<endl<<endl;
}
