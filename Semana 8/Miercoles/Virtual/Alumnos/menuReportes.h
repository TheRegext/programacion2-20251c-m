#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

void alumnosPorCarrera();
int buscarCarreraMaxNumero();
void generarArchivoAlumnosPorAnio();
void generarArchivAnioCorto();

void menuReportes(){
    ArchivoAlumnos archiAlumnos("alumnos.dat");
    int opc;
    while(true){
        system("cls");
        cout << "******MENU REPORTES******" << endl;
        cout << "1. CANTIDAD DE ALUMNOS POR CARRERA" << endl;
        cout << "2. CARRERA CON MAS ALUMNOS" << endl;///HACER
        cout << "3. GENERAR UN ARCHIVO CON LOS ALUMNOS QUE NACIERON EN UN ANIO QUE SE INGRESA POR TECLADO " << endl;
        cout << "4. ARCHIVO NUEVO DE ALUMNOS DE UN ANIO PERO CON FORMATO CORTO: LEGAJO Y FECHA DE NACIMIENTO" << endl;
        cout << "5. MOSTRAR CANTIDAD DE REGISTROS"<<endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: alumnosPorCarrera();
                    break;
            case 2:
                    break;
            case 3: generarArchivoAlumnosPorAnio();
                    break;
            case 4: generarArchivAnioCorto();
                    break;
            case 5:
            case 0: return;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return;
}

/*void alumnosPorCarrera(){
    ///Cantidad de alumnos ACTIVOS
    ///Yo se, porque me dice el enunciado que hay 10 carreras, identificadas del 1 al 10
    int vAlumnos[10]={0};
    Alumno reg;
    ArchivoAlumnos archiAlu;
    int cantReg=archiAlu.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiAlu.leerRegistro(i);
        if(reg.getEstado()) vAlumnos[reg.getCodigoCarrera()-1]++;
    }
    for(int i=0;i<10;i++){
        cout<<"LA CARRERA "<<i+1<<" TIENE "<<vAlumnos[i]<<" ALUMNOS"<<endl;
    }
}
 */

int buscarCarreraMaxNumero(){///en este caso usamos memoria dinámica porque no sabemos la cantidad de carreras
    Alumno reg;
    ArchivoAlumnos archiAlu;
    int numeroMax=0;
    int cantReg=archiAlu.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiAlu.leerRegistro(i);
        if(reg.getEstado()){
                if(reg.getCodigoCarrera()>numeroMax) numeroMax=reg.getCodigoCarrera();
        }
    }
    return numeroMax;
}

void alumnosPorCarrera(){
    ///Cantidad de alumnos ACTIVOS
    ///No se cuántas carreras hay. Sólo se que están identificadas con número del 1 en adelante
    int *vAlumnos;
    int carreraMax=buscarCarreraMaxNumero();
    vAlumnos=new int[carreraMax];
    if(vAlumnos==nullptr){
        cout<<"ERROR DE MEMORIA "<<endl;
        return;
    }

    for(int i=0;i<carreraMax;i++) vAlumnos[i]=0;

    Alumno reg;
    ArchivoAlumnos archiAlu;
    int cantReg=archiAlu.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiAlu.leerRegistro(i);
        if(reg.getEstado()) vAlumnos[reg.getCodigoCarrera()-1]++;
    }

    for(int i=0;i<carreraMax;i++){
        cout<<"LA CARRERA "<<i+1<<" TIENE "<<vAlumnos[i]<<" ALUMNOS"<<endl;
    }
    delete []vAlumnos;
}

void generarArchivoAlumnosPorAnio(){///el formato de los registros tiene que ser el mismo que el formato de alumnos
    int anio;

    Alumno reg;
    ArchivoAlumnos archiAlu;

    ArchivoAlumnos archiNuevo("alu_anio.dat");

    archiNuevo.generarNuevo();

    cout<<"INGRESE EL ANIO PARA GENERAR EL NUEVO ARCHIVO ";
    cin>>anio;

    int cantReg=archiAlu.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiAlu.leerRegistro(i);
        if(reg.getEstado()) {
                if(reg.getFechaNacimiento().getAnio()==anio){
                    archiNuevo.agregarRegistro(reg);
                }

        }
    }

    archiNuevo.listarRegistros();

}

void generarArchivAnioCorto(){
    int anio;

    Alumno reg;
    ArchivoAlumnos archiAlu;

    ArchivoAlumnoNuevo archiNuevo("alu_anio.dat");
    AlumnoNuevo aux;

    archiNuevo.generarNuevo();

    cout<<"INGRESE EL ANIO PARA GENERAR EL NUEVO ARCHIVO ";
    cin>>anio;

    int cantReg=archiAlu.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiAlu.leerRegistro(i);
        if(reg.getEstado()) {
                if(reg.getFechaNacimiento().getAnio()==anio){
                    ///aux.setLegajo(reg.getLegajo());
                    ///aux.setFechaNacimiento(reg.getFechaNacimiento());
                    aux=reg; ///sobrecarga del = en AlumnoNuevo
                    archiNuevo.agregarRegistro(aux);
                }

        }
    }

    archiNuevo.listarRegistros();



}





#endif // MENUREPORTES_H_INCLUDED
