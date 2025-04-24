#pragma once
#include <string>

class Archivo{
  public:
  Archivo(std::string nombreArchivo);
  
  protected:
    bool abrirLectura();
    bool abrirEscritura();
    void cerrar();
    
    FILE *_pFile;
  private:
    bool abrir(std::string modo);
    std::string _nombreArchivo;
    
};
