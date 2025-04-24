///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

///A partir de este fuente:
    /// Generar un proyecto con un menú (Agregar registros, listar registros y salir)
    ///Cada clase debe definirse en un .h distinto, y el desarrollo de sus métodos
    ///hacerse en un cpp distinto
///Completar los métodos faltantes de las clases
///Ver lo que devuelven los métodos para dar los mensajes que correspondan


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

void Fecha::Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }

///fin de la clase Fechar

class Alumno{
 private:
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[30];
    Fecha fechaNacimiento; ///COMPOSICIÓN-> USAMOS UN OBJETO DE UNA CLASE COMO PROPIEAD DE OTRA CLASES
    int codigoCarrera;
 public:
    void Cargar(int leg);
    void Mostrar();
    int getLegajo(){return legajo;}
};


void Alumno::Cargar(int leg=0){
    if(leg==0){
    cout<<"LEGAJO ";
    cin>>legajo;
    ///
    }
    else{
        legajo=leg;
    }
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
    int buscarAlumno(int leg);///busca si hay un alumno en el archivo con el legajo que recibe
                              /// si lo encuentra devuelve la posición del registro en el archivo
                            ///si no le encuentra devuelve -1
};

int ArchivoAlumnos::buscarAlumno(int leg){///
    Alumno obj;
    FILE *pAlumno;
    pAlumno=fopen(nombre,"rb");

    if(pAlumno==nullptr){  ///NULL
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, tamanioRegistro,1,pAlumno)==1){
       if(obj.getLegajo()==leg){
            return pos;
       }
       pos++;
    }

    fclose(pAlumno);
    return -1;
}

int ArchivoAlumnos::agregarRegistro(){
    Alumno obj;
    /// Que no se repita el legajo.
    int leg;
    cout<<"INGRESAR LEGAJO ";
    cin>>leg;
    int encontro=buscarAlumno(leg);
    if(encontro!=-1){
        cout<<"YA EXISTE EL LEGAJO"<<endl;
        return -2;
    }
    obj.Cargar(leg);
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
    system("pause");
    if(archiAlu.listarRegistros()==false){
        cout<<" NO SE PUDO LEER EL ARCHIVO"<<endl;
    }

    cout<<endl;
	system("pause");
	return 0;
}
