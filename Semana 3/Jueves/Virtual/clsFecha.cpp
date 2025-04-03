///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

///ENCAPSULAMIENTO: las clases permiten el acceso a las propiedades sólo por medio de
///métodos definidos en la propia clase

class Fecha{
    private:
        int dia, mes, anio;
    public:
        void Cargar();///para asignarle valor a las propiedades
        void Mostrar();
        void MostrarH();
        ///set-> para modificar el valor de las propiedades
        void setDia(int d){dia=d;}///validar que d esté entre 1 y 31
        void setMes(int d){mes=d;}///validar que d esté entre 1 y 12
        void setAnio(int d){anio=d;}///validar que sea positivo

        ///get-> para sacar hacia afuera el valor de las propiedades
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

void Fecha::Cargar(){
    cout<<"DIA ";
    cin>>dia;
    cout<<"MES ";
    cin>>mes;
    cout<<"ANIO ";
    cin>>anio;
}

void Fecha::Mostrar(){
    cout<<"DIA "<<dia<<endl;
    cout<<"MES "<<mes<<endl;
    cout<<"ANIO "<<anio<<endl;
}

void Fecha::MostrarH(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main(){
    Fecha date, otra;
    date.Cargar();
    otra.Cargar();
    ///comparar para saber si las fechas pertenecen al mismo año
    if(date.getAnio()==otra.getAnio()){
        cout<<"LAS FECHAS SON DEL MISMO ANIO";
    }
    else{
        cout<<"LAS FECHAS NO SON DEL MISMO ANIO";
    }
	cout<<endl;
	system("pause");
	return 0;
}
