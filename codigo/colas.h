 
class Cola {
private:
	class Nodo {
	public:
		int info;
		Nodo* sig;
	};

	Nodo* inicio; 
    Nodo* final; 
public:
	Cola();
	~Cola();
	void insertar(int x); 
	int extraer();  
	void imprimir();
	bool vacia();
	int imprimir_elemento();
	int imprimir_dato();

};