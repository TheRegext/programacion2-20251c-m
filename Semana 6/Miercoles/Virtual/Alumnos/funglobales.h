#ifndef FUNGLOBALES_H_INCLUDED
#define FUNGLOBALES_H_INCLUDED

bool altaAlumnos();
bool bajaLogica();


///fin de los prototipos

bool altaAlumnos(){
    Alumno reg;
    ArchivoAlumnos archiAlumnos("alumnos.dat");
    int leg;
    cout<<"INGRESAR LEGAJO ";
    cin>>leg;
    int encontro=archiAlumnos.buscarAlumno(leg);
    if(encontro>=0){
        cout<<"EL LEGAJO YA EXISTE "<<endl;
        return false;
    }
    reg.Cargar(leg);
    if(archiAlumnos.agregarRegistro(reg)==1) return true;
    return false;
}

bool bajaLogica(){
    Alumno reg;
    ArchivoAlumnos archiAlumnos("alumnos.dat");
    int leg;
    cout<<"INGRESAR LEGAJO ";
    cin>>leg;
    int encontro=archiAlumnos.buscarAlumno(leg);
    if(encontro<0){
        cout<<"EL LEGAJO NO EXISTE "<<endl;
        return false;
    }
    reg=archiAlumnos.leerRegistro(encontro);
    reg.setEstado(false);
    if(archiAlumnos.modificarRegistro(reg,encontro)==1) return true;
    return false;
}
#endif // FUNGLOBALES_H_INCLUDED
