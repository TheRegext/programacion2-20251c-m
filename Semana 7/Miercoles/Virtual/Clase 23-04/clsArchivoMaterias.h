#ifndef CLSARCHIVOMATERIAS_H_INCLUDED
#define CLSARCHIVOMATERIAS_H_INCLUDED

#include "clsMateria.h"

class ArchivoMaterias{
    private:
        char nombre[30];
    public:
        ArchivoMaterias(const char *n="Materias.dat");
        Materia leerRegistro(int);
        bool grabarRegistro(Materia);
        bool modificarRegistro(Materia, int);
        int contarRegistros();
        int buscarRegistro(int);
        void limpiar();
};

#endif // CLSARCHIVOMATERIAS_H_INCLUDED
