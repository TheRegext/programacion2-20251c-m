///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


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
        void Cargar(){};
        void Mostrar(){};

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


};

int main(){
    /*Materia var1, vecMateria[5];
    var1.Cargar();
    var1.Mostrar();*/
    Materia reg;
    reg.setNumeroMateria(100);
    reg.setNombreMateria("PROGRAMACION II");

    cout<<reg.getNumeroMateria()<<endl;
    cout<<reg.getNombreMateria()<<endl;
	cout<<endl;
	system("pause");
	return 0;
}
