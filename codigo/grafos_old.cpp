
#include <iostream>
#include <vector>
#include <map>
//#include <tuple>

#include "grafos_old.h"
#include "listas_enlazadas_lib.h"

using namespace std;

//Constructor
grafo::grafo(int tam){
	cout << "grafo object being created with max nodos tam:" << tam << "\n\n";
	grafo_tam = tam;
	// cout << "grafo object created"<<endl;
}

void grafo::agregar_nodo(int nodo){
	arregloNodos.push_back(nodo);
	cout << "adding nodo" << endl;
}

void grafo::agregar_vertice(int nodo1, int nodo2){
	edge1Array.push_back(nodo1);
	edge2Array.push_back(nodo2);
	cout << "adding edge" << nodo1 << nodo2 <<"\n";
}
void grafo::conectar_nodos(int nodo1, int nodo2){
	agregar_vertice(nodo1,nodo2);
	agregar_vertice(nodo2,nodo1);
}

int grafo::comp_nodo(int nodo){
	/*
	Checks the nodo 
	Returns 1 if the nodo is found 0 otherwise
	*/

	for(int i=0; i< arregloNodos.size(); i++){
		if (arregloNodos[i] == nodo){
			cout << "The nodo exists\n";
			return 1;
		}
	}
	return 0;
}
int grafo::comp_vertice(int nodo1, int nodo2){
	/*
	Checks the edge (nodo1,nodo2)
	Returns 1 if the edge is found 0 otherwise
	*/
	for(int i=0; i< edge1Array.size(); i++){
		if (edge1Array[i] == nodo1 && edge2Array[i] == nodo2){
			return 1;
		}
	}
	return 0;
}

void grafo::borrar_nodo(int nodo){
	/*
	Deletes the nodo from the arregloNodos
	*/
	int out;
	out = comp_nodo(nodo);
	if (out ==1 ){
		int count = 0;
		//find the nodo and delete it
		//Using an iterator to go through the vector
		for (vector<int>::const_iterator i = arregloNodos.begin(); i != (arregloNodos.end());i++){
			if (*i == nodo){
				arregloNodos.erase(arregloNodos.begin() + count);
			}
			count++; 
		}

	}
	else{
	}
}

void grafo::mostrar_lista_nodos(void){
	/*
	Prints the nodo list
	*/
	for (vector<int>::const_iterator i = arregloNodos.begin(); i != (arregloNodos.end());i++){
		cout << "nodo :" << (*i) <<endl;
	}
}

void grafo::borrar_union_nodos(int nodo1, int nodo2){
	/*
	Delete the edge (nodo1, nodo2)
	(nodo2, nodo1)
	*/
	borrar_vertice(nodo1,nodo2);
	borrar_vertice(nodo2,nodo1);
}

void grafo::borrar_vertice(int nodo1, int nodo2){
	/*
	Deletes the edge (nodo1, nodo2)
	If the edge does not exist, then nothing is done.
	*/

	int out;
	out = comp_vertice(nodo1, nodo2);
	if (out ==1 ){ //The edge exists
		int count = 0;
		//find the nodo and delete it
		//Using an iterator to go through the vector
		for (vector<int>::const_iterator i = edge1Array.begin(); i != (edge1Array.end());i++){
			if (*((edge1Array.begin() + count)) == nodo1 && *((edge1Array.begin() + count)) == nodo2){
				edge1Array.erase(edge1Array.begin() + count);
				edge2Array.erase(edge2Array.begin() + count);
			}
			count++; 
		}

	}
	else{ //The edge does not exist. Dont do anything.
	}
}

int grafo::mostar_nodos_conectados(void ){
	/*
	Computes the connected compoonents of the UNDIRECTED grafo
	stores the components in an map :(nodo, component_number)  
	private data: connected_components
	Suggestion: Maybe this is the update function!
	And we need another function that can access the connected components and give it
	to you
	*/


	//Create an adjacency list
	//ListaEnlazada *lista_adyacencia = new ListaEnlazada();
	map< int, vector<int> > adjacency_list;
	int count = 0;
	//Go through the edge list and create the adjacency list
	for (vector<int>::const_iterator i = edge1Array.begin(); i != (edge1Array.end());i++){
		adjacency_list[edge1Array[count]].push_back(edge2Array[count]);
		count++;
	}
	// print the connected components
	for (map< int , vector<int> >::iterator it = adjacency_list.begin();it != adjacency_list.end();it++){
		vector<int> value_list = it->second;
		for (int i =0;i<value_list.size();i++){
		}
	}

	// Create a map from nodo to components
	map<int,int> component_number;
	count = 0;
	for (int k=0;k<arregloNodos.size();k++){
		if (component_number.find(count) == component_number.end()){
			//if not assigned a component_number - start a BFS
			int nodo = arregloNodos[k];
			int original_nodo = nodo;
			vector<int> first_nodos = adjacency_list[nodo];
			for (int i=0; i<first_nodos.size();i++){
			}
			while(!first_nodos.empty()){
				int curr_nodo = first_nodos.back();
				first_nodos.pop_back();
				if (component_number.find(curr_nodo) == component_number.end()){
					//If current nodo is not assigned a component number
					component_number[curr_nodo] = original_nodo;
					vector<int> curr_nodo_list = adjacency_list[curr_nodo];
					for (int l = 0; l<curr_nodo_list.size() ; l++){
					}
					int nodo_list_len = curr_nodo_list.size();
					for (int j = 0;j<nodo_list_len;j++){
						first_nodos.push_back(curr_nodo_list.back());
						curr_nodo_list.pop_back();
					}

				}

			}

		}else{
			//The nodo is assigned a component number

		}
		count++;
	}
	cout << "\n\nConnected Components\n";
	for (int l=0;l<arregloNodos.size();l++){   
		int nodo = arregloNodos[l];
		cout << "nodo is:" << nodo << "  connected_component:" << component_number[nodo] << endl;

	}
	return 1;
}

int main(){
	int count;
	grafo grafo1(10);

	grafo1.agregar_nodo(1);

	grafo1.agregar_nodo(2);
	grafo1.agregar_nodo(3);
	grafo1.agregar_nodo(4);
	grafo1.agregar_nodo(5);
	grafo1.agregar_nodo(6);
	grafo1.agregar_nodo(7);
	grafo1.agregar_nodo(8);
	grafo1.agregar_nodo(9);
	grafo1.agregar_nodo(10);
	grafo1.agregar_nodo(11);

	// grafo1.conectar_nodos(1,2);
	grafo1.conectar_nodos(1,3);
	grafo1.conectar_nodos(2,4);
	grafo1.conectar_nodos(2,5);
	grafo1.conectar_nodos(6,7);
	grafo1.conectar_nodos(7,8);
	// grafo1.conectar_nodos(8,9);
	grafo1.conectar_nodos(9,10);
	grafo1.conectar_nodos(10,11);


	// grafo1.conectar_nodos(3,4);

	// grafo1.deleteEdge(1,3);
	grafo1.borrar_union_nodos(1,100);
	grafo1.comp_nodo(1);

	grafo1.comp_nodo(2);
	grafo1.comp_vertice(1,2);
	grafo1.comp_vertice(1,3);
	grafo1.comp_vertice(2,4);

	// grafo1.deletenodo(1);
	grafo1.comp_nodo(1);
	grafo1.mostrar_lista_nodos();
	grafo1.borrar_nodo(100);
	cout << "\n\n\nDONE!!!"<<endl;

	count = grafo1.mostar_nodos_conectados();
    return 0;
}