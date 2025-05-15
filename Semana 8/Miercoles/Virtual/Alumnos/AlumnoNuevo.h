#ifndef ALUMNONUEVO_H_INCLUDED
#define ALUMNONUEVO_H_INCLUDED

class AlumnoNuevo{
    private:
        int legajo;
        Fecha fechaNacimiento;
    public:
        void setLegajo(int l){legajo=l;}
        void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
        void Mostrar();
        void operator=(Alumno obj);

 };

 void AlumnoNuevo::Mostrar(){
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Mostrar();
    cout<<endl;
}

void AlumnoNuevo::operator=(Alumno obj){
    setLegajo(obj.getLegajo());
    setFechaNacimiento(obj.getFechaNacimiento());
}

#endif // ALUMNONUEVO_H_INCLUDED
