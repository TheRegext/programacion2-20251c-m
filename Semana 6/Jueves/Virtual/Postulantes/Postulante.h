#pragma once
#include <string>

class Postulante
{
public:
  Postulante();
  Postulante(int id, std::string nombre, std::string apellido, int edad, std::string puesto, int experiencia, bool contratado);

  int getId();
  std::string getNombre();
  std::string getApellido() ;
  int getEdad();
  std::string getPuesto();
  int getExperiencia() ;
  bool getContratado();

  void setId(int id);
  void setNombre(std::string nombre);
  void setApellido(std::string apellido);
  void setEdad(int edad);
  void setPuesto(std::string puesto);
  void setExperiencia(int experiencia);
  void setContratado(bool contratado);
  
private:
  int _id;
  char _nombre[25];
  char _apellido[25];
  int _edad;
  char _puesto[50];
  int _experiencia;
  bool _contratado;
};
