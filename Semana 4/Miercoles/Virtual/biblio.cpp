#include <iostream>
#include <cstring>

using namespace std;

/*Una biblioteca lleva el registro de los socios, los libros que tiene y los préstamos de libros que realiza a los socios.
Por cada uno de los socios registra el DNI, el nombre, el apellido, un número de teléfono, un email y la fecha de nacimiento. 
Por razones administrativas a cada una de las personas que se asocia se le asigna además un número único que lo identifica como socio.
Para cada libro se registra el número ISBN, el nombre del libro, el nombre del autor, la fecha de publicación, y la cantidad de ejemplares de ese libro que tiene la biblioteca.
 El número ISBN (International Standard Book Number) es un código numérico que identifica de forma única a cada libro publicado.
En cuanto a cada uno de los préstamos, a la Biblioteca le interesa saber cuál es el libro que se prestó, a qué socio se lo prestó, 
cuál fue el día del préstamo y cuál fue la fecha de devolución.

A partir de la descripción se pide:
- Definir cuáles son los objetos que se necesitan para registrar la información de la biblioteca.
- Para cada uno de los objetos, definir cuáles son las propiedades necesarias.
- Definir el tipo de dato que corresponda para representar cada propiedad.
- Desarrollar las clases necesarias
- Definir los archivos (nombre y campos)


//Objetos y clases
Socios
Libros
Préstamos
Fecha


//Archivos:
    - Archivo socios
    - Archivo libros
    - Archivo préstamos


Pregunta para resolver en casa:
    - Cuando quiera leer el archivo de préstamos, cómo harían para obtener el nombre del cliente y el nombre del libro? 

*/

class Fecha{
    private:
        int dia;
        int mes;
        int anio;

};

class Socio{
    private:
        char dni [8];
        char nombre [30];
        char apellido [50];
        char telefono [15];
        char mail [50];
        Fecha fechaNac;
        int nroSocio;
};

class Libro{
    private:
        int isbn;
        char nombreLibro [50];
        char nombreAutor [50];
        Fecha fechaPub;
        int cantEjemplares;
};

class Prestamo{
    private:
        int isbnLibro;
        int nroSocio;
        Fecha fechaPrestamo;
        Fecha fechaDevolucion;
};

int main (){

  system ("pause");
  return 0;
}