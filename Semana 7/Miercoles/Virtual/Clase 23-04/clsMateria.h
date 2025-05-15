#ifndef CLSMATERIA_H_INCLUDED
#define CLSMATERIA_H_INCLUDED

class Materia{
    private:
        int numero;
        char nombre[50];
        int cantidadAlumnos;
        int cantidadDocentes;
        bool estado;
    public:
        Materia(int num = 0, const char *nom = "SIN NOMBRE", int cA = 0, int cD = 0);
        ~Materia();
        void setNumero(int n);
        int getNumero();
        void setCantidadAlumnos(int cA);
        int getCantidadAlumnos();
        void setCantidadDocentes(int cD);
        int getCantidadDocentes();
        void setNombre(const char *n);
        const char *getNombre();
        void setEstado(bool);
        bool getEstado();
        void Cargar();
        void Mostrar();
};


#endif // CLSMATERIA_H_INCLUDED
