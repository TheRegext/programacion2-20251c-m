#pragma once
#include "Postulante.h"

class PostulanteIO: public Postulante{
public:
  PostulanteIO();
  PostulanteIO(Postulante postulante);
  void cargar();
  void mostrar();
};
