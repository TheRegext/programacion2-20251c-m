#include <iostream>
#include <cstring>
#include "clsMateria.h"
#include "clsAlumno.h"
#include "clsArchivoMaterias.h"
#include "clsArchivoAlumnos.h"
#include "funciones.h"

using namespace std;

void menuPrincipal(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"==================="<<endl;
        cout<<"1 - MENU MATERIAS"<<endl;
        cout<<"2 - MENU ALUMNOS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"==================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuMaterias();
                break;
            case 2:
                menuAlumnos();
                break;
            case 0:
                return;
        }
    }
}

void menuMaterias(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU MATERIAS"<<endl;
        cout<<"=============================="<<endl;
        cout<<"1 - CARGAR MATERIA"<<endl;
        cout<<"2 - MOSTRAR MATERIAS"<<endl;
        cout<<"3 - MODIFICAR CANTIDAD DE ALUMNOS"<<endl;
        cout<<"4 - BAJA LOGICA"<<endl;
        cout<<"5 - BUSCAR MATERIA POR NUMERO"<<endl;
        cout<<"6 - BUSCAR MATERIA POR NOMBRE"<<endl;
        cout<<"7 - BAJA FISICA"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarMateria();
                break;
            case 2:
                listarMaterias();
                break;
            case 3:
                modificarCantidadAlumnos();
                break;
            case 4:
                bajaMateria();
                break;
            case 5:
                buscarPorNumero();
                break;
            case 6:
                buscarPorNombre();
                break;
            case 7:
                bajaFisicaMateria();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void menuAlumnos(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU ALUMNOS"<<endl;
        cout<<"============================="<<endl;
        cout<<"1 - CARGAR ALUMNO"<<endl;
        cout<<"2 - MOSTRAR ALUMNOS"<<endl;
        cout<<"3 - MODIFICAR EMAIL"<<endl;
        cout<<"4 - BAJA LOGICA"<<endl;
        cout<<"5 - BUSCAR ALUMNO POR LEGAJO"<<endl;
        cout<<"6 - BUSCAR ALUMNO POR NOMBRE"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"============================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                altaAlumno();
                break;
            case 2:
                listarAlumnos();
                break;
            case 3:
                modificarEmail();
                break;
            case 4:
                break;
            case 5:
                buscarAlumnoPorLegajo();
                break;
            case 6:
                buscarAlumnoPorNombre();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

bool grabarMateria(Materia obj){
    FILE *p = fopen("Materias.dat", "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

void agregarMateria(){
    Materia obj;
    obj.Cargar();
    ArchivoMaterias arc;
    arc.grabarRegistro(obj);
}

void altaAlumno(){
    Alumno obj;
    obj.Cargar();
    ArchivoAlumnos arc;
    arc.grabarRegistro(obj);
}

void listarMaterias(){
    ArchivoMaterias arcMat;
    Materia obj;
    int cantReg = arcMat.contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = arcMat.leerRegistro(i);
        if(obj.getEstado()==true){
            obj.Mostrar();
        }
    }
}

void listarAlumnos(){
    ArchivoAlumnos arcAlu;
    Alumno obj;
    int cantReg = arcAlu.contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = arcAlu.leerRegistro(i);
        obj.Mostrar();
    }
}

void mostrarMateriaPorPosicion(){
    cout<<"INGRESE LA POSICION DEL REGISTRO A BUSCAR: ";
    int pos;
    cin>>pos;
    ArchivoMaterias arcMat;
    Materia reg = arcMat.leerRegistro(pos);
    if(reg.getNumero()<=0){
        cout<<"LA POSICION INGRESADA NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    reg.Mostrar();
}

void buscarPorNumero(){
    cout<<"INGRESE EL NUMERO DE MATERIA A BUSCAR: ";
    int num;
    cin>>num;
    ArchivoMaterias arc("Materias.dat");
    int pos = arc.buscarRegistro(num);
    if(pos < 0){
        cout<<"NO HAY UNA MATERIA CON ESE NUMERO EN EL ARCHIVO"<<endl;
        return;
    }
    Materia obj = arc.leerRegistro(pos);
    obj.Mostrar();
}

void buscarPorNombre(){
    cout<<"INGRESE EL NOMBRE DE LA MATERIA A BUSCAR: ";
    char nombre[50];
    cargarCadena(nombre, 49);
    ArchivoMaterias arcMat;
    int cantReg = arcMat.contarRegistros();
    Materia obj;
    for(int i=0; i<cantReg; i++){
        obj = arcMat.leerRegistro(i);
        if(strcmp(obj.getNombre(), nombre) == 0){
            obj.Mostrar();
            return;
        }
    }
    cout<<"NO HAY UNA MATERIA CON ESE NOMBRE EN EL ARCHIVO"<<endl;
}

void modificarEmail(){
    int legajo;
    cout<<"INGRESE EL LEGAJO DEL ALUMNO A MODIFICAR: ";
    cin>>legajo;
    ArchivoAlumnos arcAlu;
    int pos = arcAlu.buscarRegistro(legajo);
    if(pos<0){
        cout<<"NO EXISTE UN ALUMNO CON ESE LEGAJO EN EL ARCHIVO"<<endl;
        return;
    }
    Alumno obj;
    obj = arcAlu.leerRegistro(pos);
    char email[40];
    cout<<"INGRESE EL NUEVO EMAIL DEL ALUMNO: ";
    cargarCadena(email, 39);
    obj.setEmail(email);
    arcAlu.modificarRegistro(obj, pos);
}

void buscarAlumnoPorLegajo(){
}
void buscarAlumnoPorNombre(){
}

void modificarCantidadAlumnos(){
    cout<<"INGRESE EL NUMERO DE LA MATERIA: ";
    int num;
    cin>>num;
    ArchivoMaterias arcMat;
    int pos = arcMat.buscarRegistro(num);
    if(pos < 0){
        cout<<"EL NUMERO DE MATERIA INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Materia obj;
    obj = arcMat.leerRegistro(pos);
    int cantAlumnos;
    cout<<"INGRESE LA NUEVA CANTIDAD DE ALUMNOS: ";
    cin>>cantAlumnos;
    obj.setCantidadAlumnos(cantAlumnos);
    arcMat.modificarRegistro(obj, pos);
}

void bajaMateria(){
    cout<<"INGRESE EL NUMERO DE LA MATERIA A DAR DE BAJA: ";
    int num;
    cin>>num;
    ArchivoMaterias arcMat;
    int pos = arcMat.buscarRegistro(num);
    if(pos < 0){
        cout<<"NO EXISTE UNA MATERIA CON ESE NUMERO EN EL ARCHIVO"<<endl;
        return;
    }
    Materia obj;
    obj = arcMat.leerRegistro(pos);
    obj.setEstado(false);
    arcMat.modificarRegistro(obj, pos);
}

void bajaFisicaMateria(){
    ArchivoMaterias arcMat("Materias.dat");
    ArchivoMaterias arcAux("Materias.aux");
    Materia obj;
    int cantReg = arcMat.contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = arcMat.leerRegistro(i);
        arcAux.grabarRegistro(obj);
    }
    arcMat.limpiar();
    for(int i=0; i<cantReg; i++){
        obj = arcAux.leerRegistro(i);
        if(obj.getEstado() == true){
            arcMat.grabarRegistro(obj);
        }
    }
}
