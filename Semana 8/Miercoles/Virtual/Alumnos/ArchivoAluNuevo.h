#ifndef ARCHIVOALUNUEVO_H_INCLUDED
#define ARCHIVOALUNUEVO_H_INCLUDED

class ArchivoAlumnoNuevo{
private:
    char nombre[30];
    int tamanioRegistro;
public:
    ArchivoAlumnoNuevo(const char *n="alu_nuevo.dat"){
        strcpy(nombre, n);
        tamanioRegistro=sizeof(AlumnoNuevo);
    }
    bool generarNuevo();
    int agregarRegistro(AlumnoNuevo reg);

    bool listarRegistros();

    AlumnoNuevo leerRegistro(int pos);

    int contarRegistros();

};



int ArchivoAlumnoNuevo::agregarRegistro(AlumnoNuevo reg){

    FILE *p;
    p=fopen(nombre,"ab");
    if(p==nullptr){
        return -1;
    }

    int escribio=fwrite(&reg, tamanioRegistro,1,p);

    fclose(p);
    return escribio;
}



bool ArchivoAlumnoNuevo::listarRegistros(){
    AlumnoNuevo obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, tamanioRegistro,1,p)==1){
        obj.Mostrar();
        cout<<endl;
    }

    fclose(p);
    return true;
}

AlumnoNuevo ArchivoAlumnoNuevo::leerRegistro(int pos){
    AlumnoNuevo obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(p,pos*tamanioRegistro,0);
    fread(&obj, tamanioRegistro,1,p);

    fclose(p);
    return obj;

}



int ArchivoAlumnoNuevo::contarRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int tam=ftell(p);

    fclose(p);
    int cantReg;
    cantReg=tam/tamanioRegistro;
    return cantReg;
}

bool ArchivoAlumnoNuevo::generarNuevo(){
    FILE *p;
    p=fopen(nombre,"wb");
    if(p==nullptr)return false;
    fclose(p);
    return true;
}


#endif // ARCHIVOALUNUEVO_H_INCLUDED
