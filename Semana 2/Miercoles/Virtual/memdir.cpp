///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

void cargarVector(int *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        v[i]=i+1;
    }

}
void mostrarVector(int *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        cout<<v[i]<<"\t";
    }

}

int main(){
    int *v;
    ///int v[10];
    v=new int[10];
    if(v==NULL){
        cout<<"NO HAY MEMORIA SUFICIENTE"<<endl;
        return -1;
    }
    cargarVector(v, 10);
    mostrarVector(v, 10);

    delete[]v;
	cout<<endl;
	system("pause");
	return 0;
}
