

class ListaEnlazada {
private:
    class Nodo {
    public:
        int info;
        Nodo *sig;
    };

    Nodo *inicio;
public:
    ListaEnlazada();
    ~ListaEnlazada();
    int cantidad();
    void insertar(int pos, int x);
    void borrar(int pos);
    void intercambiar(int pos1, int pos2);
    void imprimir();
    bool existe(int x);
    int extraer(int pos);
    int mayor();
    bool vacia();
    int posMayor();
    bool ordenada();
};