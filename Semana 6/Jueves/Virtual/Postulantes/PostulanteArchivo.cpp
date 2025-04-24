#include <iostream>
#include "PostulanteArchivo.h"

using namespace std;

PostulanteArchivo::PostulanteArchivo(string nombreArchivo)
/// es la forma en que se inicializan (llaman a los constructores)
/// de las composiciones
: Archivo(nombreArchivo)
{
}


bool PostulanteArchivo::guardar(Postulante registro){
  bool result;

  if(!abrirEscritura()){
    return false;  
  }
  
  result = fwrite(&registro, sizeof(Postulante), 1, _pFile);
  
  cerrar();
  
  return result;
}
Postulante PostulanteArchivo::leer(int posicion){
}

void PostulanteArchivo::leerTodo(Postulante resgistros[], int cantidad){
  if(!abrirLectura()){
    return;  
  }
  
  fread(resgistros, sizeof(Postulante), cantidad, _pFile);
  
  cerrar();
}

int PostulanteArchivo::getCantidadRegistros(){
  int cantidadRegistros; 
  
  if(!abrirLectura()){
    return 0;  
  }
  
  fseek(_pFile, 0, SEEK_END);
  
  cantidadRegistros = ftell(_pFile) / sizeof(Postulante);

  cerrar();

  return cantidadRegistros;
}

int PostulanteArchivo::buscar(int id){
}
