#include <iostream>
#include <cstring>
#include "clsContador.h"
#include "clsAlumno.h"
#include "clsMateria.h"
#include "funciones.h"

using namespace std;

void explicacionArchivos(){
    FILE *p = fopen("Materias.dat", "ab");
    if(p == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }
    Materia obj;
//    obj.Cargar();
//    fwrite(&obj, sizeof obj, 1, p);
    while(fread(&obj, sizeof obj, 1, p)==1){
        obj.Mostrar();
    }
    fclose(p);
    /**
    (read) rb: es el modo de lectura, no crea archivos
    (append) ab: es un modo de escritura que siempre escribe
                al final de mi archivo. Si el archivo no existe
                lo crea.
    (write) wb: es un modo de escritura. Siempre crea un archivo
                vacío.
    */
}



/**
AGREGAR AL PROYECTO UNA CLASE ALUMNO CON LAS SIGUIENTES
PROPIEDADES:
-LEGAJO (INT)
-NOMBRE Y APELLIDO (CHAR[])
-DNI (INT)
-EMAIL (CHAR[])
-TELEFONO (CHAR[])

MODIFICAR EL PROGRAMA PARA QUE TENGA UN MENU PRINCIPAL
CUYAS OPCIONES LLAMEN A DOS SUBMENUES, UNO PARA MATERIAS
Y OTRO PARA ALUMNOS
*/

/**
AGREGARLE A LA CLASE ALUMNO UNA PROPIEDAD DOMICILIO CON LA SIGUIENTE INFORMACION:
-CALLE (nombre);
-ALTURA (numero);
-LOCALIDAD
-PARTIDO
-CODIGO POSTAL
*/

int main()
{
    Alumno obj;
    obj.Cargar();
    system("cls");
    Fecha aux = obj.getFechaNacimiento();
    aux.setAnio(2000);
    obj.setFechaNacimiento(aux);
    obj.Mostrar();
    return 0;
    menuPrincipal();
    return 0;
}

