#include <iostream>
#include <cstring>
using namespace std;

#include "Fecha.h"
#include "Alumno.h"
#include "ArchivoAlumnos.h"
#include "funglobales.h"

int main(){
    ArchivoAlumnos archiAlumnos("alumnos.dat");
    int opc;
    while(true){
        system("cls");
        cout << "******ABML ALUMNOS******" << endl;
        cout << "1. ALTA" << endl;
        cout << "2. BAJA" << endl;
        cout << "3. MODIFICAR APELLIDO " << endl;
        cout << "4. LISTADO" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(altaAlumnos()==true){
                        cout<<"REGISTRO AGREGADO";
                    }
                    else{
                        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
                    }
                    cout<<endl;
                    break;
            case 2: if(bajaLogica()==true){
                        cout<<"REGISTRO BORRADO"<<endl;
                    }
                    else{
                        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
                    }
                    break;
            case 3:
                    break;
            case 4:  if(archiAlumnos.listarRegistros()==false){
                        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
                    }
                    cout<<endl;
                    break;
            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return 0;
}
