#pragma once
#include <string>
#include "Postulante.h"
#include "Archivo.h"
///  using namespace std; /// very mal!!!

class PostulanteArchivo: public Archivo{
  public:
    PostulanteArchivo(std::string nombreArchivo = "postulantes.dat");
    bool guardar(Postulante registro);
    Postulante leer(int posicion);
    void leerTodo(Postulante resgistros[], int cantidad);
    int buscar(int id);
    int getCantidadRegistros();
  protected:
    
  private:

};
