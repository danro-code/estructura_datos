
class ArbolBinario {
private:
    class Nodo {
    public:
        int info;
        Nodo *izq;
        Nodo *der;
    };
    Nodo *raiz;
    int cant;
    int altura;
public:
    ArbolBinario();
    ~ArbolBinario();
    void insertar(int x);
    bool existe(int x);
    void imprimirEntre();
    void imprimirPre();
    void imprimirPost();
    int cantidad();
    int cantidadNodosHoja();
    void imprimirEntreConNivel();
    int retornarAltura();
    void mayorValor();
    void borrarMenor();
    void borrar(Nodo *reco);
    void imprimirEntre(Nodo *reco);
    void imprimirPre(Nodo *reco);
    void imprimirPost(Nodo *reco);
    void cantidad(Nodo *reco);
    void cantidadNodosHoja(Nodo *reco);
    void imprimirEntreConNivel(Nodo *reco, int nivel);
    void retornarAltura(Nodo *reco, int nivel);
};