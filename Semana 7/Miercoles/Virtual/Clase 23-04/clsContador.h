#ifndef CLSCONTADOR_H_INCLUDED
#define CLSCONTADOR_H_INCLUDED

class Contador{
    private:
        int valor;
        int valorInicial;
    public:
        void incrementar();
        void decrementar();
        void mostrar();
        int getValor();
        void setValor(int v);
        Contador(int v=0);
        void reiniciar();
};

#endif // CLSCONTADOR_H_INCLUDED
