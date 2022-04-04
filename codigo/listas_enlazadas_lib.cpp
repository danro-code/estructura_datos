#include <iostream>
#include <string> 

#include "listas_enlazadas_lib.h"
using namespace std;


ListaEnlazada::ListaEnlazada()
{
    inicio = NULL;
}

ListaEnlazada::~ListaEnlazada()
{
    Nodo *reco = inicio;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}

int ListaEnlazada::cantidad()
{
    Nodo *reco = inicio;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

void ListaEnlazada::insertar(int pos, int x)
{
    if (pos <= cantidad() + 1)    
    {
        Nodo *nuevo = new Nodo();
        nuevo->info = x;
        if (pos == 1)
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
        else
            if (pos == cantidad() + 1)    
            {
                Nodo *reco = inicio;
                while (reco->sig != NULL) 
                {
                    reco = reco->sig;
                }
                reco->sig = nuevo;
                nuevo->sig = NULL;
            }
            else 
            {
                Nodo *reco = inicio;
                for (int f = 1; f <= pos - 2; f++)
                {
                    reco = reco->sig;
                }
                Nodo *siguiente = reco->sig;
                reco->sig = nuevo;
                nuevo->sig = siguiente;
            }
    }
}


int ListaEnlazada::extraer(int pos) 
{
    if (pos <= cantidad())    
    {
        int informacion;
        Nodo *bor;
        if (pos == 1) 
        {
            informacion = inicio->info;
            bor = inicio;
            inicio = inicio->sig;
        }
        else 
        {
            Nodo *reco;
            reco = inicio;
            for (int f = 1; f <= pos - 2; f++)
            {
                reco = reco->sig;
            }
            Nodo *prox = reco->sig;
            reco->sig = prox->sig;
            informacion = prox->info;
            bor = prox;
        }
        delete bor;
        return informacion;
    }
    else
        return -1;
}

void ListaEnlazada::borrar(int pos)
{
    if (pos <= cantidad())    
    {
        Nodo *bor;
        if (pos == 1) 
        {
            bor = inicio;
            inicio = inicio->sig;
        }
        else {
            Nodo *reco;
            reco = inicio;
            for (int f = 1; f <= pos - 2; f++)
            {
                reco = reco->sig;
            }
            Nodo *prox = reco->sig;
            reco->sig = prox->sig;
            bor = prox;
        }
        delete bor;
    }
}

void ListaEnlazada::intercambiar(int pos1, int pos2) 
{
    if (pos1 <= cantidad() && pos2 <= cantidad())    
    {
        Nodo *reco1 = inicio;
        for (int f = 1; f < pos1; f++)
        {
            reco1 = reco1->sig;
        }
        Nodo *reco2 = inicio;
        for (int f = 1; f < pos2; f++)
        {
            reco2 = reco2->sig;
        }
        int aux = reco1->info;
        reco1->info = reco2->info;
        reco2->info = aux;
    }
}

bool ListaEnlazada::vacia()
{
    if (inicio == NULL)
        return true;
    else
        return false;
}


int ListaEnlazada::mayor() 
{
    if (!vacia()) 
    {
        int may = inicio->info;
        Nodo *reco = inicio->sig;
        while (reco != NULL) 
        {
            if (reco->info > may)
            {
                may = reco->info;
            }
            reco = reco->sig;
        }
        return may;
    }
    else
        return -1;
}

void ListaEnlazada::imprimir()
{
    Nodo *reco = inicio;
    cout << "Listado completo.\n";
    while (reco != NULL)
    {
        cout << reco->info << "-";
        reco = reco->sig;
    }
    cout << "\n";
}


int ListaEnlazada::posMayor() 
{
    if (!vacia())    
    {
        int may = inicio->info;
        int x = 1;
        int pos = x;
        Nodo *reco = inicio->sig;
        while (reco != NULL)
        {
            if (reco->info > may) 
            {
                may = reco->info;
                pos = x;
            }
            reco = reco->sig;
            x++;
        }
        return pos;
    }
    else
        return -1;
}

bool ListaEnlazada::ordenada() 
{
    if (cantidad()>1) 
    {
        Nodo *reco1 = inicio;
        Nodo *reco2 = inicio->sig;
        while (reco2 != NULL) 
        {
            if (reco2->info<reco1->info) 
            {
                return false;
            }
            reco2 = reco2->sig;
            reco1 = reco1->sig;
        }
    }
    return true;
}

bool ListaEnlazada::existe(int x) 
{
    Nodo *reco = inicio;
    while (reco != NULL) 
    {
        if (reco->info == x)
            return true;
        reco = reco->sig;
    }
    return false;
}
