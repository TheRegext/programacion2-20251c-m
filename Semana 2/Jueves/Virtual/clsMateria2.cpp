///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:
#include<iostream>


using namespace std;


///CLASE: definición de las propiedades y el comportamiento (métodos) que van a tener los objetos de esa clase.
///Una clase es un MOLDE, un tipo de dato creado por el usuario programador

///OBJETO: una variable de una clase. Tiene las propiedades y el comportamiento definidos en su clase.
///Una instancia de una clase.

void soyUnaFuncionGlobal(){

}
/*
struct materia{
        int numeroMateria;
        string nombreMateria;
        int cantidadAlumnos;
        int cantidadProfesores;
};
 */
///ENCAPSULAMIENTO: mecanismo de las clases que impide que las propiedades puedan ser accedidas de manera directa

/**
  En la clase se define
     atributos y los  metodos identificador
    estructura y el comportamento nombre
    
  En objeto tiene
    Estado, realiza acciones (interface) y identidad
*/

class Materia{
    ///propiedades: aquellas cosas sobre las que es necesario guardar información, son distinguibles
    /// Son las variables de la clase
    private:
        int numeroMateria;
        string nombreMateria;
        int cantidadAlumnos;
        int cantidadProfesores;

    ///comportamiento. Métodos de la clase
    ///Son las funciones de la clase
    public:
        void Cargar(){
          cout << "Ingrese numero de materia: ";
          cin >> numeroMateria;
          
          cout << "Ingrese Nombre: ";
          cin >> nombreMateria;
          
          cout << "Ingrese cantidad de Alumnos:";
          cin >> cantidadAlumnos;
          
          cout << "Ingrese cantidad de Profesores:";
          cin >> cantidadProfesores;
        };
        
        void Mostrar(){
          cout << "Numero: " << numeroMateria << endl;
          cout << "Nombre: " << nombreMateria << endl;
          cout << "Cantidad Alumnos: " << cantidadAlumnos<< endl;
          cout << "Cantidad Profesores: " << cantidadProfesores << endl;
        };

        ///para escribir en una propiedad usamos los métodos set
        void setNumeroMateria(int nm){
            ///validaciones
            numeroMateria=nm;
        }
        void setNombreMateria(string nombre){
            ///validaciones
            nombreMateria=nombre;
        }
        ///para sacar hacia afuera el valor de las propiedades usamos los métodos get
        int getNumeroMateria(){return numeroMateria;}

        string getNombreMateria(){return nombreMateria;}
        
        int getCantidadAlumnos(){
          return cantidadAlumnos;
        }
};

int main(){
    Materia materias[10];
    
    for(int i=0; i<10; i++){
      materias[i].Cargar();
    }
    
    for(int i=0; i<10; i++){
        if(materias[i].getCantidadAlumnos() > 10){
          materias[i].Mostrar();    
        }
      
    }
    
  
    /*Materia var1, vecMateria[5];
    var1.Cargar();
    var1.Mostrar();*//*
    
    
    Materia reg, reg2;
    reg.Cargar();
    reg2.Cargar();
    
    reg.Mostrar();
    reg2.Mostrar();*/
    
    /*
    reg.setNumeroMateria(100);
    reg.setNombreMateria("PROGRAMACION II");

    cout<<reg.getNumeroMateria()<<endl;
    cout<<reg.getNombreMateria()<<endl;
    */
	cout<<endl;
	system("pause");
	return 0;
}
