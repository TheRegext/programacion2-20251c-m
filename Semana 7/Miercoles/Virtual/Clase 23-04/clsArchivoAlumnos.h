#ifndef CLSARCHIVOALUMNOS_H_INCLUDED
#define CLSARCHIVOALUMNOS_H_INCLUDED

#include "clsAlumno.h"

class ArchivoAlumnos{
    private:
        char nombre[30];
    public:
        ArchivoAlumnos(const char *n="Alumnos.dat");
        Alumno leerRegistro(int);
        bool grabarRegistro(Alumno);
        bool modificarRegistro(Alumno, int);
        int contarRegistros();
        int buscarRegistro(int);
};

#endif // CLSARCHIVOALUMNOS_H_INCLUDED
