#include <string>

class Arbol {
private:
    class Nodo {
    public:
        int info;
        std::string letra;
        std::string codigo;
        Nodo *izq;
        Nodo *der;
    };
    Nodo *raiz;
public:
    Arbol();
    ~Arbol();
    void insertar_n(Nodo *&reco, std::string letra, std::string codigo);
    void insertar(std::string letra,std::string codigo);
    bool existe(std::string x);
    void insertar_codigo();
    void borrar(Nodo *reco);
    void mostrar_Pre(Nodo *reco);
    void mostrar_Entre(Nodo *reco);
    void mostrar_Post(Nodo *reco);
    std::string buscar_Pre(Nodo *reco, std::string x);
    std::string buscar_Entre(Nodo *reco, std::string x);
    std::string buscar_Post(Nodo *reco, std::string x);
    void call_fun_recur(int y,std::string x);
};