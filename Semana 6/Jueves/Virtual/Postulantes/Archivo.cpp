#include <iostream>
#include "Archivo.h"
using namespace std;

Archivo::Archivo(std::string nombreArchivo)
:_nombreArchivo(nombreArchivo) {
  _pFile = nullptr;
}

bool Archivo::abrir(string modo){
  _pFile = fopen(_nombreArchivo.c_str(), modo.c_str());
    
    if(_pFile == nullptr){
      return false;    
    }
    
    return true;
}

bool Archivo::abrirLectura(){
    return abrir("rb");
}

bool Archivo::abrirEscritura(){
    return abrir("ab");
}

void Archivo::cerrar(){
  if(_pFile != nullptr){
    fclose(_pFile);  
  }
}



