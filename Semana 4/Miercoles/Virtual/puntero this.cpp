///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

class Alumno{
 private:
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[30];
    int edad;
    int codigoCarrera;
 public:
    Alumno(int legajo=0, int edad=0){
        this->legajo=legajo;
        this->edad=edad;
    }
    void Cargar();
    void Mostrar();
    void verDireccion(){
        cout<<this<<endl;
        ///this es un puntero (oculto) que contiene la dirección del objeto que llama al método
        ///(*this).Mostrar();
        ///this->Mostrar();
    }
};

void Alumno::Cargar(){
    cout<<"LEGAJO ";
    cin>>this->legajo;
    cout<<"NOMBRE ";
    cin>>this->nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"EMAIL ";
    cin>>email;
    cout<<"EDAD ";
    cin>>edad;
    cout<<"CARRERA ";
    cin>>codigoCarrera;
}

void Alumno::Mostrar(){
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"EMAIL "<<email<<endl;
    cout<<"EDAD "<<edad<<endl;
    cout<<"CARRERA "<<codigoCarrera<<endl;
}

int main(){
    Alumno obj, otro;
    ///obj.Cargar();
    obj.Mostrar();
    /*otro.Cargar();
    cout<<&obj<<endl;
    obj.verDireccion();
    ///cout<<this<<endl; sólo existe dentro de las clases
    cout<<endl;
    cout<<&otro<<endl;
    otro.verDireccion();*/
    cout<<endl;
	system("pause");
	return 0;
}
