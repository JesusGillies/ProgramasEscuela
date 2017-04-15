#include <iostream>
#include <conio.h>
#include<stdlib.h>
using namespace std; 


struct Nodo{
	Nodo *siguiente; //puntero al siguiente nodo
	int edad;

};
void menu();
void insertar(Nodo *&, int);
void mostrarlista(Nodo *);
void buscar(Nodo *,int);
void eliminar(Nodo *&,int);
Nodo *lista=NULL;
int main()
{		
		menu();
		
	 return 0; 	 
}

void menu()
{
	int op,edad;
	do
	{
	
	cout<<"\n\n MENU DE DATOS PARA LISTA SIMPLE"; 
	cout<<"\n\n\[1] Insertar datos";
	cout<<"\n\n\[2] Mostrar datos";
	cout<<"\n\n\[3] Buscar dato";
	cout<<"\n\n\[4] Eliminar dato";
	cout<<"\n\n\[5] Salir";
	cout<<"\n\n\t Elegir opcion: "; 
	cin>>op;
	switch(op)
		{
			case 1:  cout<<"\n Ingrese el Dato  ";
	 				cin>>edad;
					insertar(lista,edad);
					cout<<"\n";
					system("pause"); 
			break;
			
			case 2:  mostrarlista(lista);
					cout<<"\n";
					system("pause"); 
			break; 
			
			case 3: cout<<"\n Digite el Dato a Buscar ";
					cin>>edad;
					buscar(lista,edad);
					cout<<"\n";
					system("pause"); 
			break;
			case 4: cout<<"\n Digite el Dato a Eliminar  ";
					cin>>edad;
					eliminar(lista,edad);
					cout<<"\n";
					system("pause");
			break;
		}
			    	 system("cls");
   	}while(op!=5);

}

void insertar(Nodo *&lista, int n)
{
	Nodo *nuevo_nodo= new Nodo();
	nuevo_nodo->edad=n;
	Nodo *aux1=lista;
	Nodo *aux2;
	
	while ((aux1!=NULL)&&(aux1->edad < n))
	
	{
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	
	if (lista==aux1)
	{
		lista=nuevo_nodo; 
	}
	else
	{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
	cout<<"\n\n\t El Dato  "<<n<<" Insertado Correctamete \n";
} //ia me aburri :(
void mostrarlista(Nodo *lista)
{
	Nodo *actual= new Nodo();//crear nuevo nodo
	actual=lista; //primer posicion de la  lsta
	//recorrer la lista
	while (actual!=NULL)
	{
		
		cout<<actual->edad<<" | ";
		actual=actual->siguiente;
	}
	
}

void buscar(Nodo *lista, int n)
{
		bool band = false;
		Nodo *actual= new Nodo();//crear nuevo nodo
		actual=lista; 
		//recorrer lista
		while ((actual!=NULL)&&(actual->edad <= n)) 
		{
			if(actual->edad==n) //si existe
			{
				band= true;
			}
			actual=actual->siguiente;
		}
		
	if(band== true)
	{
		cout<<"El Dato  "<<n<<"  SI a sido encontrado en la lista";
	}
	else
	{
		cout<<"El Dato "<<n<<"NO a sido encontrado en la lista";
	}
}

void eliminar(Nodo *&lista, int n)
{
	if(lista!=NULL)//LISTA VACIA?
	{
		Nodo *aux_borrar;
		Nodo *anterior=NULL;
		
		aux_borrar=lista;//señalando al inicio de la lista
		//recorrer la lista
		while((aux_borrar!=NULL)&&(aux_borrar->edad!=n))
		{
			anterior=aux_borrar;
			aux_borrar=aux_borrar->siguiente;
		}
		//NO ENCONTRADO 
		if(aux_borrar==NULL)
		{
			cout<<"\n El Dato NO existe";
		}
		//PRIMER ELEMENTO ES EL QUE SE ELIMINA
		else if(anterior==NULL)
		{
			lista=lista->siguiente;
			delete aux_borrar;
		}
		//elemento esta en la lista pero no es el primero
		else {
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar; 
		}
	}
}
