

class ListaEnlazada {
private:
    class Nodo {
    public:
        int info;
        std::string titulo;
        std::string genero;
        std::string autor;
        Nodo *sig;
    };

    Nodo *inicio;
public:
    ListaEnlazada();
    ~ListaEnlazada();
    int cantidad();
    void insertar(int pos, int x,std::string a,std::string b,std::string c);
    void borrar(int pos);
    void intercambiar(int pos1, int pos2);
    void imprimir();
    bool existe(std::string b);// b = titulo del libro
    //Estos metodos como tal no se usan en el programa pero podiran usarse para
    //agregar funciones al programa como ver si la lista esta vacia o para ver cual 
    //es el ultimo libro de la lista
    int extraer(int pos);
    int mayor();
    bool vacia();
    int posMayor();
    bool ordenada();
};