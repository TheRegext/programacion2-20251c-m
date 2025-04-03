///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
    Cadena(const char *inicio){///vamos a usarlo para pedir memoria
        tam=strlen(inicio)+1;
        p=new char[tam];
        if(p==nullptr){ ///NULL
            cout<<"NO SE PUDO ASIGNAR MEMORIA"<<endl;
            return;
        }
        strcpy(p,inicio);    ///copio en el vector dinámico, la cadena que recibí
    }

    void Mostrar(){
        cout<<p<<endl;
    }

    ~Cadena(){///devolver la memoria que pedimos
        delete []p;
    }

};

int main(){
    char palabra[]="POO";
    cout<<strlen(palabra)<<endl;
    system("pause");
    Cadena texto("hola a todos los que me conocen");
    texto.Mostrar();
	cout<<endl;
	system("pause");
	return 0;
}

///Agregar un método agregarCaracter(char letra), que le agregue
///a la cadena existente un caracter al final.
/// Cadena obj("todo");
/// obj.agregarCaracter('s');
/// obj.Mostrar()///-> se tienen que ver en pantalla la cadena todos

///Agregar otro método que se llame aMayusculas(), que ponga todas las
///letras de la cadena en mayúsculas (ver relación entre may y min en ASCII)

///Agregar otro método que se llame aMinusculas()
