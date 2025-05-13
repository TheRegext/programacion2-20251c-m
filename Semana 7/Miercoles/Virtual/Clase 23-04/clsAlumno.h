#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED

#include "clsFecha.h"

class Alumno{
    private:
        int legajo;
        char nombre[30];
        char apellido[30];
        int dni;
        Fecha fechaNacimiento;
        Fecha fechaInscripcion;
        char email[40];
        char telefono[20];
        bool estado;
    public:
        int getLegajo();
        const char *getNombre();
        const char *getApellido();
        int getDni();
        Fecha getFechaNacimiento();
        Fecha getFechaInscripcion();
        const char *getEmail();
        const char *getTelefono();
        bool getEstado();
        void setLegajo(int);
        void setNombre(const char *);
        void setApellido(const char *);
        void setDni(int);
        void setFechaNacimiento(Fecha);
        void setFechaInscripcion(Fecha);
        void setEmail(const char *);
        void setTelefono(const char *);
        void setEstado(bool);
        void Cargar();
        void Mostrar();
};

#endif // CLSALUMNO_H_INCLUDED
