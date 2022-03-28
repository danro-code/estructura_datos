#include <iostream>
#include <string>

#include "arboles.h"
using namespace std;

Arbol::Arbol()
{
    raiz = NULL;
}

Arbol::~Arbol()
{
    borrar(raiz);
}

void Arbol::borrar(Nodo *reco)
{
    if (reco != NULL)
    {
        borrar(reco->izq);
        borrar(reco->der);
        delete reco;
    }
}

void Arbol::insertar_n(Nodo *&reco, string letra, string codigo){
    if (reco== NULL)
    {
        reco= new Nodo;
        reco->letra = letra;
        reco->codigo = codigo;
        reco->izq = reco->der = NULL;
    }
}

void Arbol::insertar(string letra,string codigo)
{
    Nodo **reco= &raiz;
    if(*reco!= NULL)
    {
        for(std::string::size_type i = 0; i < codigo.length(); i++)
        {
            if(codigo[i] == '.') reco= &((*reco)->izq);
            else if(codigo[i] == '-') reco= &((*reco)->der);
            else break;
        }
         insertar_n(*reco, letra, codigo);
    }else insertar_n(raiz, letra, codigo);
}
//FIXME:
bool Arbol::existe(string x)
{
    Nodo *reco = raiz;
    while (reco != NULL) 
    {
        if (reco->codigo == x)
        {
            return true;
        }else if (reco->letra ==x){
            return true;
        }
        //buscar
        if(reco->der != NULL){
            reco = reco->der;
        }else if (reco->izq != NULL){
            reco = reco->izq;
        }else return false;
    }
        /*if (x == reco->der->codigo)
                return true;
        else if (x == reco->izq->codigo)
                return true;
    }
    return false;*/
}

void Arbol::insertar_codigo(){
    string arbol[27][2]{  
                    {"ROOT", ""},  {"E", "."},    {"T", "-"},    {"I", ".."},   {"A", ".-"},   {"N", "-."},   
                    {"M", "--"},   {"S", "..."},  {"U", "..-"},  {"R", ".-."},  {"W", ".--"},  {"D", "-.."},  
                    {"K", "-.-"},  {"G", "--."},  {"O", "---"},  {"H", "...."}, {"V", "...-"}, {"F", "..-."}, 
                    {"L", ".-.."}, {"P", ".--."}, {"J", ".---"}, {"B", "-..."}, {"X", "-..-"}, {"C", "-.-."}, 
                    {"Y", "-.--"}, {"Z", "--.."}, {"Q", "--.-"}  
                    };
    for(int i = 0; i < 27; i++){
    insertar(arbol[i][0], arbol[i][1]);
    cout<<"sucess"; 
    }
}

void Arbol::mostrar_Pre(Nodo *reco){
    if (reco != NULL){
        cout <<"Letra: "<< reco->letra<<", "<<"Codigo: "<<reco->codigo<<endl;
        mostrar_Pre(reco->izq);
        mostrar_Pre(reco->der);
    }
}

void Arbol::mostrar_Entre(Nodo *reco){
    if (reco != NULL){
        mostrar_Pre(reco->izq);
        cout <<"Letra: "<< reco->letra<<", "<<"Codigo: "<<reco->codigo<<endl;
        mostrar_Pre(reco->der);
    }
}

void Arbol::mostrar_Post(Nodo *reco){
    if (reco != NULL){
        mostrar_Pre(reco->izq);
        mostrar_Pre(reco->der);
        cout <<"Letra: "<< reco->letra<<", "<<"Codigo: "<<reco->codigo<<endl;
    }
}

string Arbol::buscar_Pre(string x){
    string salida;
    while (reco != NULL)
    {
        if (reco->letra == x)
        {
            salida = reco->codigo;
            return salida;
        }else if (reco->codigo == x){
            salida = reco->letra;
            return salida;
        }
        if (reco->izq =)
        {
            /* code */
        }
        
        buscar_Pre(reco->izq,x);
        buscar_Pre(reco->der,x);
    }
    
    if (reco != NULL){

    }
    return salida;
}

string Arbol::buscar_Entre(Nodo *reco, string x){
    
}

string Arbol::buscar_Post(Nodo *reco, string x){

}

void Arbol::call_fun_recur(int y,std::string x){
    string out = " ";
    switch (y)
    {
    case 1:
        borrar(raiz);
        break;
    case 2:
        mostrar_Pre(raiz);
        break;
    case 3:
        mostrar_Entre(raiz);
        break;
    case 4:
        mostrar_Post(raiz);
        break;
    case 5:
        out = buscar_Pre(raiz, x);
        cout <<"resultado:"<<out<<endl;
        break;
    case 6:
        out = buscar_Entre(raiz, x);
        cout <<"resultado:"<<out<<endl;
        break;
    case 7:
        out = buscar_Post(raiz, x);
        cout <<"resultado:"<<out<<endl;
        break;
    default:
        break;
    }
}

int main(){
	int opcion;
    string x,genero,autor;
	Arbol *arbol1 = new Arbol();
    arbol1->insertar_codigo();
    do
    {
        cout <<"Bienvenido"<<endl;
        cout <<"Seleccione una opción:"<<endl;
        cout << "1.- convertir frase a codigo morse" <<endl;
        cout << "2.- convertir codigo morse a frase" <<endl;
        cout << "3.- buscar letra"<<endl;
        cout << "4.- buscar codigo"<<endl;
        cout << "5.- imprimir el arbol"<<endl;

		cout << "6.- mostar numero de libros" <<endl;
		cout << "0.- salir del programa"<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            break;
        case 2:
            break;
		case 3:
            cout << "ingrese la letra que desea buscar:"<<endl;
            cin >> x;
            arbol1->call_fun_recur(5, x);
            cout <<endl;
            break;
		case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            cout << "\n";
            break;
        }
    } while (opcion != 0);
    return 0;
}