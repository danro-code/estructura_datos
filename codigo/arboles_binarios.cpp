#include <iostream>

#include "arboles_binarios.h"
using namespace std;

ArbolBinario::ArbolBinario()
{
    raiz = NULL;
}

ArbolBinario::~ArbolBinario()
{
    borrar(raiz);
}

void ArbolBinario::borrar(Nodo *reco)
{
    if (reco != NULL)
    {
        borrar(reco->izq);
        borrar(reco->der);
        delete reco;
    }
}


void ArbolBinario::insertar(int x)
{
    if (!existe(x))
    {
        Nodo *nuevo;
        nuevo = new Nodo();
        nuevo->info = x;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        if (raiz == NULL)
            raiz = nuevo;
        else
        {
            Nodo *anterior, *reco;
            anterior = NULL;
            reco = raiz;
            while (reco != NULL)
            {
                anterior = reco;
                if (x < reco->info)
                    reco = reco->izq;
                else
                    reco = reco->der;
            }
            if (x < anterior->info)
                anterior->izq = nuevo;
            else
                anterior->der = nuevo;
        }
    }
}

bool ArbolBinario::existe(int x)
{
    Nodo *reco = raiz;
    while (reco != NULL) 
    {
        if (x == reco->info)
                return true;
        else
            if (x>reco->info)
                reco = reco->der;
            else
                reco = reco->izq;
    }
    return false;
}


int ArbolBinario::cantidad() 
{
    cant = 0;
    cantidad(raiz);
    return cant;
}

void ArbolBinario::cantidad(Nodo *reco) 
{
    if (reco != NULL) 
    {
        cant++;
        cantidad(reco->izq);
        cantidad(reco->der);
    }
}

int ArbolBinario::cantidadNodosHoja() 
{
    cant = 0;
    cantidadNodosHoja(raiz);
    return cant;
}



void ArbolBinario::cantidadNodosHoja(Nodo *reco) 
{
    if (reco != NULL) {
        if (reco->izq == NULL && reco->der == NULL)
            cant++;
        cantidadNodosHoja(reco->izq);
        cantidadNodosHoja(reco->der);
    }
}

void ArbolBinario::imprimirEntreConNivel() 
{
    imprimirEntreConNivel(raiz, 1);
    cout << "\n";
}

void ArbolBinario::imprimirEntreConNivel(Nodo *reco, int nivel)  
{
    if (reco != NULL) {
        imprimirEntreConNivel(reco->izq, nivel + 1);
        cout<<reco->info <<"(" <<nivel <<") - ";
        imprimirEntreConNivel(reco->der, nivel + 1);
    }
}

int ArbolBinario::retornarAltura() 
{
    altura = 0;
    retornarAltura(raiz, 1);
    return altura;
}

void ArbolBinario::retornarAltura(Nodo *reco, int nivel)    
{
    if (reco != NULL) 
    {
        retornarAltura(reco->izq, nivel + 1);
        if (nivel>altura)
            altura = nivel;
        retornarAltura(reco->der, nivel + 1);
    }
}

 void ArbolBinario::mayorValor()
 {
    if (raiz != NULL) 
    {
        Nodo *reco = raiz;
        while (reco->der != NULL)
            reco = reco->der;
        cout<<"Mayor valor del árbol:" <<reco->info;
    }
}

void ArbolBinario::borrarMenor() 
{
     if (raiz != NULL) {
         Nodo *bor;
         if (raiz->izq == NULL)
         {
             bor = raiz;
             raiz = raiz->der;
             delete bor;
         }
         else {
             Nodo *atras = raiz;
             Nodo *reco = raiz->izq;
             while (reco->izq != NULL) 
             {
                 atras = reco;
                 reco = reco->izq;
             }
             atras->izq = reco->der;
             delete reco;
         }
     }
}

void ArbolBinario::imprimirPre()
{
    imprimirPre(raiz);
    cout << "\n";
}

void ArbolBinario::imprimirPre(Nodo *reco)
{
    if (reco != NULL)
    {
        cout << reco->info << "-";
        imprimirPre(reco->izq);
        imprimirPre(reco->der);
    }
}

void ArbolBinario::imprimirEntre()
{
    imprimirEntre(raiz);
    cout << "\n";
}

void ArbolBinario::imprimirEntre(Nodo *reco)
{
    if (reco != NULL)
    {
        imprimirEntre(reco->izq);
        cout << reco->info << "-";
        imprimirEntre(reco->der);
    }
}

void ArbolBinario::imprimirPost()
{
    imprimirPost(raiz);
    cout << "\n";
}

void ArbolBinario::imprimirPost(Nodo *reco)
{
    if (reco != NULL)
    {
        imprimirPost(reco->izq);
        imprimirPost(reco->der);
        cout << reco->info << "-";
    }
}

int main()
{
    ArbolBinario *arbol1 = new ArbolBinario();
    arbol1->insertar(300);
    arbol1->insertar(120);
    arbol1->insertar(65);
    arbol1->insertar(85);
    arbol1->insertar(250);
    arbol1->insertar(450);
    arbol1->insertar(20);
    arbol1->insertar(13);
    arbol1->insertar(2);
    cout<<"mostrar datos en: preorden: ";
    arbol1->imprimirPre();
    cout<<"mostrar datos en: entreorden: ";
    arbol1->imprimirEntre();
    cout<<"mostrar datos en: postorden: ";
    arbol1->imprimirPost();
    cout<<"Cantidad de nodos del árbol:" <<arbol1->cantidad() <<endl;
    cout<<"Cantidad de nodos hoja:" <<arbol1->cantidadNodosHoja()<<endl;
    cout<<"mostrar datos en entre orden junto al nivel del nodo:";
    arbol1->imprimirEntreConNivel();
    cout<<"Artura del arbol:";
    cout << arbol1->retornarAltura();
    cout << "\n";
    arbol1->mayorValor();
    cout << "\n";
    arbol1->borrarMenor();
    cout<<"Luego de borrar el menor dato:";
    arbol1->imprimirEntre();
    delete arbol1;
    return 0;
}
