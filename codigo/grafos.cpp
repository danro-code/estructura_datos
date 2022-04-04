#include <iostream>

#include "grafos.h"
using namespace std;

Grafo::Grafo(int numVertices) {
    this->numVertices = numVertices;
    matrizAdyacencia = new bool*[numVertices];
    for (int i = 1; i <= numVertices; i++) {
        matrizAdyacencia[i] = new bool[numVertices];
        for (int j = 1; j <= numVertices; j++)
            matrizAdyacencia[i][j] = false;
    }
}

void Grafo::agregarArista(int i, int j){
    matrizAdyacencia[i][j] = true;
    matrizAdyacencia[j][i] = true;
}


void Grafo::borrarArista(int i, int j) {
    matrizAdyacencia[i][j] = false;
    matrizAdyacencia[j][i] = false;
    cout << "arista borrada con exito"<<endl;
}


void Grafo::imprimir() {
    cout << "nodo: aristas"<<endl<<"    ";
    for (int k = 1; k <= numVertices; k++)
    {
        cout << k <<" ";
    }
    cout << endl;
    for (int i = 1; i <= numVertices; i++) {
        cout << i << " : ";
        for (int j = 1; j <= numVertices; j++)
            cout << matrizAdyacencia[i][j] << " ";
            cout << "\n";
    }
}

Grafo::~Grafo() {
        for (int i = 1; i <= numVertices; i++)
            delete[] matrizAdyacencia[i];
            delete[] matrizAdyacencia;
}

void Grafo::borrarNodo(int vertice){
    numVertices--;

}

int main() {
    int nodos,opcion,n1 = 0,n2 = 0;
    cout << "Bienvenido"<<endl;
    cout << "Ingrese cuantos nodos tiene el grafo: ";
    cin >> nodos;
    Grafo g(nodos);
    do
    {
        cout <<"Seleccione una opción:"<<endl;
        cout << "1.- agregar arista" <<endl;
        cout << "2.- mostrar grafo" <<endl;
        cout << "3.- borrar arista"<<endl;
		cout << "4.- borrar nodo" <<endl;
		cout << "0.- salir del programa"<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese el numero de los nodos que quiere unir: ";
            cout << "nodo 1: ";
            cin >> n1;
            cout << "nodo 2:";
            cin >> n2;
            g.agregarArista(n1, n2);
            break;
        case 2:
            g.imprimir();
            break;
		case 3:
            cout << "Ingrese el numero de los nodos donde se encuentra la arista: ";
            cout << "nodo 1: ";
            cin >> n1;
            cout << "nodo 2:";
            cin >> n2;
            g.borrarArista(n1,n2);
            break;
		case 4:
            cout << "borrando el ultimo nodo"<<endl;
            g.borrarNodo(4);
            break;
        default:
            cout << "\n";
            break;
        }
    } while (opcion != 0);
}