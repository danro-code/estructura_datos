#include <iostream>
#include <string> 

#include "listas_enlazadas.h"
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

void ListaEnlazada::insertar(int pos, int x,string a,string b,string c)
{
    if (pos <= cantidad() + 1)    
    {
        Nodo *nuevo = new Nodo();
        nuevo->info = x;
        nuevo->autor = a;
        nuevo->titulo = b;
        nuevo->genero = c; 
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
        cout <<"#"<< reco->info <<", titulo:"<<reco->titulo;
        cout << ", Autor:"<<reco->autor<<", genero:"<<reco->genero<<"\n-----\n";
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

bool ListaEnlazada::existe(string b) 
{
    Nodo *reco = inicio;
    while (reco != NULL) 
    {
        if (reco->titulo == b)
            return true;
        reco = reco->sig;
    }
    return false;
}


int main(){
	int opcion,n = 0,pos1,pos2;
    string titulo,genero,autor;
	ListaEnlazada *lista = new ListaEnlazada();
    do
    {
        cout <<"Bienvenido"<<endl;
        cout <<"Seleccione una opción:"<<endl;
        cout << "1.- agregar libro" <<endl;
        cout << "2.- quitar libro" <<endl;
        cout << "3.- mostrar lista de libros"<<endl;
        cout << "4.- buscar libro"<<endl;
        cout << "5.- intercambiar posición de los libros"<<endl;
		cout << "6.- mostar numero de libros" <<endl;
		cout << "0.- salir del programa"<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            n = lista->cantidad();
            if(n==0){
                n=1;
            }else
            {
                ++n;
            }
			cout <<"\n ingrese los datos del libro que desea agregar:"<<endl;
            cout <<"ingrese el autor:"<<endl;
            cin >> autor;
            cout <<"ingrese el titulo:"<<endl;
            cin >>titulo;
            cout <<"ingrese el genero:"<<endl;
            cin >> genero;
            lista->insertar(n,n,autor,titulo,genero);
            break;
        case 2:
            //FIXME:intercambiar primero para evitar errores en numeracion
            cout << "ingrese en que posición se encuentra el libro:"<<endl;
            cin >> n;
            lista->borrar(n);
            break;
		case 3:
            lista->imprimir();
            break;
		case 4:
            cout << "ingrese el libro que desea buscar:"<<endl;
            cin >> titulo;
            if(lista->existe(titulo)){
                cout <<"El titulo se encuentra disponible"<<endl;
            }else{
                cout <<"Titulo no disponible"<<endl;
            }
            break;
        case 5:
            //FIXME:aqui tambien error numeracion
            cout <<"En que posición se encuentran los libros que desea intercambiar:"<<endl;
            cout <<"libro 1:"<<endl;
            cin>>pos1;
            cout <<"libro 2:"<<endl;
            cin>>pos2;
            lista->intercambiar(pos1,pos2);
            break;
        case 6:
            n = lista->cantidad();
            cout<<"\n el numero de libros actuales es:"<<n<<endl;
            break;
        default:
            cout << "\n";
            break;
        }
    } while (opcion != 0);
}