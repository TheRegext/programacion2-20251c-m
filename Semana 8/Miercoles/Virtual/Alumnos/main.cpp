#include <iostream>
#include <cstring>
using namespace std;

#include "Fecha.h"
#include "Alumno.h"
#include "ArchivoAlumnos.h"
#include "AlumnoNuevo.h"
#include "ArchivoAluNuevo.h"
#include "funglobales.h"
#include "menuAlumnos.h"
#include "menuMantenimiento.h"
#include "menuReportes.h"
#include "menuDocentes.h"

int main(){
    int opc;
    while(true){
        system("cls");
        cout << "******MENU PRINCIPAL******" << endl;
        cout << "1. ALUMNOS" << endl;
        cout << "2. DOCENTES" << endl;
        cout << "3. REPORTES " << endl;
        cout << "4. MANTENIMIENTO" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: menuAlumnos();
                    break;
            case 2: menuDocentes();
                    break;
            case 3: menuReportes();
                    break;
            case 4: menuMantenimiento();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return 0;
}
