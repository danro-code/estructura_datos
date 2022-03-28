#include <iostream>

#include "pilas.h"

using namespace std; 


Pila::Pila()
{
	inicio = NULL;
}

void Pila::insertar(int x)
{
	Nodo* nuevo;
	nuevo = new Nodo();
	nuevo->info = x;
	if (inicio == NULL)
	{
		inicio = nuevo;
		nuevo->sig = NULL;
	}
	else
	{
		nuevo->sig = inicio;
		inicio = nuevo;
	}
}

void Pila::imprimir()
{
	Nodo* reco = inicio;
	cout << "Listado de todos los elementos de la pila.\n";
	while (reco != NULL)
	{
		cout << reco->info << "-";
		reco = reco->sig;
	}
	cout << "\n";
}

int Pila::extraer()
{
	if (inicio != NULL)
	{
		int informacion = inicio->info;
		Nodo* bor = inicio;
		inicio = inicio->sig;
		delete bor;
		return informacion;
	}
	else
	{
		return -1;
	}
}

Pila::~Pila()
{
	Nodo* reco = inicio;
	Nodo* bor;
	while (reco != NULL)
	{
		bor = reco;
		reco = reco->sig;
		delete bor;
	}
}

int Pila::cantidad()
{
	Nodo* reco = inicio;
	int cant = 0;
	while (reco != NULL)
	{
		cant++;
		reco = reco->sig;
	}
	return cant;
}

bool Pila::vacia()
{
	if (inicio == NULL)
		return true;
	else
		return false;
}

int main(){
	int opcion,contenedor_top = 0,n = 0;
	Pila* pila1 = new Pila();
    do
    {
        cout <<"Bienvenido"<<endl;
        cout <<"Seleccione una opción:"<<endl;
        cout << "1.- agregar contenedor" <<endl;
        cout << "2.- quitar contenedor" <<endl;
        cout << "3.- mostrar lista de contenedores"<<endl;
		cout << "4.- mostrar numero de contenedores" <<endl;
		cout << "0.- salir del programa"<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
			cout<<"ingrese el nombre del contenedor que desea agregar:"<<endl;
			cin >>contenedor_top;
            pila1->insertar(contenedor_top);
            break;
        case 2:
            cout<<"removiendo contenedor"<<endl;
			pila1->extraer();
			cout<<"contenedor removido con éxito";
            break;
		case 3:
            pila1->imprimir();
            break;
		case 4:
			if (pila1->vacia())
			{
				cout << "pila vacía"<<endl;
			}
			else
			{
				n = pila1->cantidad();
            	cout << " Hay:"<< n <<"contenedores en la pila"<<endl;
			}
            break;
        default:
            cout << "\n";
            break;
        }
    } while (opcion != 0);
    
}

