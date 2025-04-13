///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

using namespace std;

class Fecha{
private:
    int dia, mes,anio;
public:
    void Cargar();
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }

};

///vamos a probar si cambia

void Fecha::Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }

class Alumno{
 private:
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[30];
    Fecha fechaNacimiento; ///COMPOSICIÓN-> USAMOS UN OBJETO DE UNA CLASE COMO PROPIEAD DE OTRA CLASES
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
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Cargar();
    cout<<"CARRERA ";
    cin>>codigoCarrera;
}

void Alumno::Mostrar(){
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"EMAIL "<<email<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Mostrar();
    cout<<"CARRERA "<<codigoCarrera<<endl;
}

class ArchivoAlumnos{
private:
    char nombre[30];
    int tamanioRegistro;
public:
    ArchivoAlumnos(const char *n="alumnos.dat"){
        strcpy(nombre, n);
        tamanioRegistro=sizeof(Alumno);
    }
    int agregarRegistro();
    bool listarRegistros();


};

int ArchivoAlumnos::agregarRegistro(){
    Alumno obj;
    obj.Cargar();
    FILE *pAlumno;
    pAlumno=fopen(nombre,"ab");
    if(pAlumno==nullptr){
        return -1;
    }

    int escribio=fwrite(&obj, tamanioRegistro,1,pAlumno);

    fclose(pAlumno);
    return escribio;
}

bool ArchivoAlumnos::listarRegistros(){
    Alumno obj;
    FILE *pAlumno;
    pAlumno=fopen(nombre,"rb");

    if(pAlumno==nullptr){  ///NULL
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, tamanioRegistro,1,pAlumno)==1){
        obj.Mostrar();
        cout<<endl;
    }

    fclose(pAlumno);
    return true;
}

int main(){
    ArchivoAlumnos  archiAlu;

    if(archiAlu.agregarRegistro()!=1){
        cout<<"PROBLEMAS CON EL ARCHIVO"<<endl;
    }

    if(archiAlu.listarRegistros()==false){
        cout<<" NO SE PUDO LEER EL ARCHIVO"<<endl;
    }

    cout<<endl;
	system("pause");
	return 0;
}
