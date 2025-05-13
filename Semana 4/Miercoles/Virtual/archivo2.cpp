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
    void Cargar();
    void Mostrar();
};

void Alumno::Cargar(){
    cout<<"LEGAJO ";
    cin>>legajo;
    cout<<"NOMBRE ";
    cin>>nombre;
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
    Alumno obj;

    FILE *pAlumno;
    pAlumno=fopen("alumos.dat","rb");
    ///modos de apertura: wb-> si quiero crear un archivo vacío (write).
    ///modos de apertura: ab-> si quiero agregar un registro al archivo (append). Si no existe el archivo lo crea
    ///modos de apertura: rb-> si quiero leer los registros de un archivo (read). El archivo tiene que existir

    if(pAlumno==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    /*-int leyo;
    leyo=fread(&obj, sizeof obj,1,pAlumno);
    obj.Mostrar();
    cout<<"VALOR DE leyo "<<leyo<<endl;
    cout<<endl;

    leyo=fread(&obj, sizeof obj,1,pAlumno);
    obj.Mostrar();
    cout<<"VALOR DE leyo "<<leyo<<endl;
    cout<<endl;

    leyo=fread(&obj, sizeof obj,1,pAlumno);
    obj.Mostrar();
    cout<<"VALOR DE leyo "<<leyo<<endl;
    cout<<endl;
       */

    while(fread(&obj, sizeof obj,1,pAlumno)==1){
        obj.Mostrar();
        cout<<endl;
    }

    fclose(pAlumno);
    cout<<endl;
	system("pause");
	return 0;
}
