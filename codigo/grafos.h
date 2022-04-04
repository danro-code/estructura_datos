
class Grafo {
private:
    bool** matrizAdyacencia;
    int numVertices;
public:
    Grafo(int numVertices);
    void agregarArista(int i, int j);
    void borrarArista(int i, int j);
    void imprimir();
    void borrarNodo(int vertice);
    ~Grafo();
};