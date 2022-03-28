#include <iostream>

#include "colas.h"

using namespace std; 

void Menu_Usuario(Cola *cola1);
void Menu_Admin(Cola *cola1);
void obtener_turno(Cola *cola1);
void ver_turno(Cola *cola1);
void sig_turno(Cola *cola1);

Cola::Cola()
{
    inicio = NULL;
    final = NULL;
}

Cola::~Cola()
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

void Cola::insertar(int x)
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (vacia()) 
    {
        inicio = nuevo;
        final = nuevo;
    }
    else {
        final->sig = nuevo;
        final = nuevo;
    }
}

int Cola::extraer()
{
    if (!vacia())
    {
        int informacion = inicio->info;
        Nodo *bor = inicio;
        if (inicio == final)
        {
            inicio = NULL;
            final = NULL;
        }
        else 
        {
            inicio = inicio->sig;
        }
        delete bor;
        return informacion;
    }
    else
        return -1;
}

void Cola::imprimir()
{
    Nodo *reco = inicio;
    cout << "Listado de todos los elementos de la cola.\n";
    while (reco != NULL)
    {
        cout << reco->info << "-";
        reco = reco->sig;
    }
    cout << "\n";
}

bool Cola::vacia()
{
    if (inicio == NULL)
        return true;
    else
        return false;
}
//FIXME:bug no da el ultimo dato bien 
int Cola::imprimir_elemento(){
    Nodo *reco = final;
    if (reco != NULL)
    {
        //cout << reco->info <<endl;
        return reco->info ;
    }
    else
    {
        //cout << "\n cola vacia"<<endl;
        return 0;
    }
}

int Cola::imprimir_dato(){
    Nodo *reco = inicio;
    if (reco != NULL)
    {
        return reco->info ;
    }
    else
    {
        return 0;
    }
}

int main(){
    int opcion,op2;
    Cola *cola1 = new Cola();
    do
    {
        cout <<"Bienvenido"<<endl;
        cout <<"Seleccione una opción:"<<endl;
        cout << "1.- usuario" <<endl;
        cout << "2.- Administrador" <<endl;
        cout << "0.- salir del programa"<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            Menu_Usuario(cola1);
            break;
        case 2:
            Menu_Admin(cola1);
            break;
        default:
            cout << "\n";
            break;
        }
    } while (opcion != 0);
    
}

void Menu_Usuario(Cola *cola1){
    int op2;
    cout << "\n 1.- Obtener turno"<<endl;
    cout << "2.- Ver turno actual"<<endl;
    cout << "3.- Regresar"<<endl;
    cin >> op2;
        switch (op2)
    {
    case 1:
        obtener_turno(cola1);
        break;
    case 2:
        ver_turno(cola1);
        break;
    }
}

void Menu_Admin(Cola *cola1){
    int op2;
    cout << "\n 1.- Ver turno actual"<<endl;
    cout << "2.- siguiente turno"<<endl;
    cout << "3.- Regresar"<<endl;
    cin >> op2;
    switch (op2)
    {
    case 1:
        ver_turno(cola1);
        break;
    case 2:
        sig_turno(cola1);
        break;
    }
}

void obtener_turno(Cola *cola1){
    int actual;
    cout <<"Su turno es:";
    actual = cola1->imprimir_elemento();
    actual++;
    cout<<actual<<endl;
    cola1->insertar(actual);
    //cola1->imprimir();
}

void ver_turno(Cola *cola1){
    int turno;
    turno = cola1->imprimir_dato();
    cout <<"El turno actual es: "<<turno<<endl;
}

void sig_turno(Cola *cola1){
    int turno = 0;
    turno = cola1->extraer();
    cout << turno<<endl;
    //cola1->imprimir_elemento();
}