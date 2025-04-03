# include<iostream>
#include <string>
using namespace std;
/// Funciones y Variables
/// snake_case 
/// camelCase


/// PascalCase
class Fecha{
private:
   int _dia;
   int _mes;
   int _anio;
   
public:
   Fecha(){
      _dia = _mes = _anio = 0;
   }
   
   Fecha(int dia, int mes, int anio){
      setDia(dia);
      setMes(mes);
      setAnio(anio);         
   }
  
   void setDia(int dia){
      if(dia>=1 && dia <=31){
         _dia=dia;   
      }
   }
      
   void setMes(int mes){
      _mes=mes;
   }
      
   void setAnio(int anio){
      _anio=anio;
   }
   
   int getDia(){
      return _dia;
   }
      
   int getMes(){
      return _mes;
   }
      
   int getAnio(){
      return _anio;
   }
      
   string toString(){
      return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
   }
};

Fecha CargarFecha(){
   int dia, mes, anio;
   cout<<"DIA ";
   cin>>dia;
   cout<<"MES ";
   cin>>mes;
   cout<<"ANIO ";
   cin>>anio;
   
   return Fecha(dia, mes, anio);
}

void MostrarFecha(Fecha fecha){
   cout<<"DIA "<<fecha.getDia()<<endl;
   cout<<"MES "<<fecha.getMes()<<endl;
   cout<<"ANIO "<<fecha.getAnio()<<endl;
}

void MostrarFechaConFormato(Fecha fecha){
   cout<<fecha.toString()<<endl;
}


int main(){
   Fecha date(3,4,2025), otra;
   
   otra = CargarFecha();
   MostrarFecha(otra);
   
   MostrarFechaConFormato(date);
   
   cout<<endl;
   system("pause");
   return 0;
}
   
   
