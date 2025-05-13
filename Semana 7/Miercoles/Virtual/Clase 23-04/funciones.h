#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarCadena(char *palabra, int tamano);
void menuPrincipal();
void menuAlumnos();
void menuMaterias();
void agregarMateria();
bool grabarMateria(Materia);
void listarMaterias();
void buscarPorNumero();
void buscarPorNombre();
void altaAlumno();
bool grabarAlumno(Alumno);
void listarAlumnos();
void modificarEmail();
void buscarAlumnoPorLegajo();
void buscarAlumnoPorNombre();
void mostrarMateriaPorPosicion();
void modificarCantidadAlumnos();
void bajaMateria();
void bajaFisicaMateria();

#endif // FUNCIONES_H_INCLUDED
