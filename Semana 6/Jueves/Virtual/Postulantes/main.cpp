#include <iostream>
#include "Postulante.h"
#include "PostulanteArchivo.h"
#include "PostulanteIO.h"

using namespace std;

int main()
{
  PostulanteIO p;
  PostulanteArchivo pa;
  
  //p.cargar();
  
  //pa.guardar(p);
  
  
  int cantidad = pa.getCantidadRegistros();
  
  Postulante *vecPostulantes;
  vecPostulantes = new Postulante[cantidad];
  
  pa.leerTodo(vecPostulantes, cantidad);
  
  for(int i=0; i<cantidad; i++){
    cout << "-----------"<<endl;
    PostulanteIO(vecPostulantes[i]).mostrar();
    /// cout << vecPostulantes[i].getNombre() << " " << vecPostulantes[i].getApellido() << endl;
    
  }
  
  
    
    return 0;
}
