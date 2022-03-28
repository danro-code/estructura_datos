
class Pila {
private:
	class Nodo {
	public:
		int info;
		Nodo* sig;
	};

	Nodo* inicio;
public:
	Pila();
	~Pila();
	void insertar(int x);
	int extraer();
	void imprimir();
	int cantidad();
	bool vacia();
}; 
