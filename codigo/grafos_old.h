#include <vector>

class grafo {
	private:
		int grafo_tam;
		std::vector<int> arregloNodos;
		//FIXME:cambiar a lista? 
		std::vector<int> edge1Array;
		std::vector<int> edge2Array;
		void agregar_vertice(int nodo1, int nodo2);
		void borrar_vertice(int nodo1, int nodo2);
	public:
		grafo(int tam);
		void agregar_nodo(int nodo);
		void conectar_nodos(int nodo1, int nodo2);
		int mostar_nodos_conectados(void);
		int comp_nodo(int nodo);
		int comp_vertice(int nodo1 , int nodo2);
		void borrar_nodo(int nodo);
		void borrar_union_nodos(int nodo1, int nodo2);
		void mostrar_lista_nodos(void);
};