#include <iostream>
using namespace std;


class Animal{
private:
   string _nombre;
   int _edad;
protected: // casos puntuales
   void saludar(){
      cout << "Soy " << _nombre << endl;
   }
public:
   void setNombre(string nombre){
      _nombre = nombre;
   }
      
   string getNombre(){
      return _nombre;
   }
         
   void setEdad(int edad){
      if(edad >= 0){
         _edad = edad;
      }
   }

   int getEdad(){
      return _edad;
   }
};

class Perro: public Animal{
private:
   
public:
   void ladrar(){
      _edad = -10;
      saludar();
      cout << "Guau!!" << endl;
   }
};

class Gato: public Animal{
private:

public:
         
   void maullar(){
      saludar();
      cout << "Miau!!" << endl;
   }
};



int main() {
   Perro p;
   Gato g;
   p.setNombre("Firulais");
   p.setEdad(10);
   
   cout << p.getNombre() << endl;
   p.ladrar();
	
   g.setNombre("Michi");
   g.setEdad(2);
   
   cout << g.getNombre() << endl;
   g.maullar();
   
	return 0;
}

