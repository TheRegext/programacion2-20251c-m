///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>

///SOBRECARGA DE FUNCIONES  permite tener funciones distintas con el mismo nombre
///Se tiene que diferenciar por los parámetros que reciba

using namespace std;

///ENCAPSULAMIENTO: las clases permiten el acceso a las propiedades sólo por medio de
///métodos definidos en la propia clase

class Fecha{
    private:
        int dia, mes, anio;
    public:
        ///CONSTRUCTOR
            /// MÉTODO
                    ///se llama igual que la clase
                    ///no devuelve nada
                    ///se ejecuta de manera automática cuando el objeto nace
        /*Fecha(){
            dia=0;
            mes=0;
            anio=0;
        } */

        Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
        }

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
///FIN DE LA CLASE FECHA

///FUNCIONES GLOBALES



int main(){
    Fecha date(3,4,2025), otra;
    date.Mostrar();
    otra.Mostrar();
 	cout<<endl;
	system("pause");
	return 0;
}

