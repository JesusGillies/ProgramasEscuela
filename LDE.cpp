#include <iostream>
using namespace std;

int menu();

class Nodo
{
	public:
		int info;
		Nodo *sig;
		Nodo *ant;
		Nodo()
		{
			sig=NULL;
			ant=NULL;
		}
		Nodo(int valor)
		{
    		 info=valor;
    		 sig=NULL;
    		 ant=NULL;
		}			
};

class Lista
{
	public:
	Nodo *inicio, *auxiliar;
	Lista()
	{
	       inicio = NULL;			
	}
	
	int Empty ( )
    {
    	return inicio == NULL ;
    
    }
		
	void Insertar(int valor)
    {
         Nodo *temp, *actual;
		 temp = new Nodo(valor);
		 auxiliar= NULL;
         actual = inicio;
		   
                     while ( actual != NULL && valor > actual->info ) 
                    {
                        auxiliar = actual;
            			actual = actual ->sig;
            		}
            		
                    if(auxiliar == NULL) 
                    {
            			temp->sig = inicio;
            			temp->ant = NULL;
            			if(actual!=NULL)
            			{
                                        inicio->ant = temp;
                        }
                        inicio = temp;
            		}
                    else 
                    {
                         if(actual!=NULL)
                         {
                            auxiliar->sig =temp;
                			temp->sig = actual;
                			temp->ant=auxiliar;
                			actual->ant=temp;        
                         }
                         else
                         {
                             temp->ant = auxiliar;
                             auxiliar->sig = temp;
                         }
            		}
    }
	
	void Imprimir1()
    {
        auxiliar=inicio;
    		cout<<"La lista es: \nNULL<-" ;
    		while ( auxiliar != NULL )   
            {
                   cout<<auxiliar->info<<" <-> ";
    			   auxiliar = auxiliar->sig;
    		} 
            cout<<"NULL\n";
    }
    
    void Imprimir2()
    {
        Nodo *temp;
        auxiliar=inicio;
        while ( auxiliar != NULL )   
        {
              temp=auxiliar;
  			   auxiliar = auxiliar->sig;
  		} 
  		cout<<"Recorrido al reves: \n" ;
    	while(temp!=NULL)
        {
            cout<<temp->info<<" - ";
		    temp = temp->ant;
        }	
        cout<<"NULL\n";
    }
    
    void BorrarLista()
    {
        auxiliar=inicio;
        while(auxiliar != NULL)
  		{
    			inicio=inicio->sig;
    			delete auxiliar;
    			auxiliar=inicio;
  		}
  		cout<<"\nLISTA ELIMINADA\n\n";
    }
    
    int Eliminar(int valor)
    {
        Nodo *temp, *actual;
            if ( valor==inicio->info ) 
            {
        		temp = inicio;
        		inicio = inicio ->sig; 
                if(inicio!=NULL) //Eliminamos la relacion anterior
                {
                   inicio->ant=  NULL;
                }   
        		delete temp;
                return 1;  
        	}
        	else   
            {
        		auxiliar = inicio;
        		actual = inicio->sig; 
        
        		while ( actual != NULL && valor != actual->info) 
                {
        			auxiliar = actual;
        			actual = actual->sig;	
        		} 
        
        		/* Al final del ciclo while el nodo actual debe ser el nodo que tiene la 
                cadena y procedemos a desatarlo*/
        		if ( actual != NULL )  
                {
                     temp=actual;
                     if(actual->sig==NULL)
                     {
                          auxiliar->sig = NULL; 
                          actual->ant = NULL;               
                     }
                     else
                     {
                         auxiliar->sig = actual->sig;
                         actual->sig->ant = auxiliar;
                         actual->sig = NULL;
                         actual->ant = NULL;
                     }
        			delete temp;
        			return 1;
        		} 
        	}  
        	return (0);
    }
    
    int buscar(int valor)
    {
         int cont=0;
         auxiliar=inicio;
         while(auxiliar != NULL){
              if(auxiliar->info == valor){
                   cont++;
              }
              auxiliar=auxiliar->sig;
  		}
  		return cont;
    }
    
    int modificar(int valor)
    {
         int bandera;
         bandera=buscar(valor);
         if(bandera>0) {
              Eliminar(valor);
              cout<<"Nuevo dato: ";
              cin>>valor;
              Insertar(valor);
              return 1;
         }
         return 0;
    }
    
	//DESTRUCTOR
	~Lista()
	{
		Nodo *recorre;
		recorre=inicio;
		while(recorre != NULL)
		{
			inicio=inicio->sig;
			delete recorre;
			recorre=inicio;
		}
	}
};  //Fin de la clase Lista

int menu ()/*Lee la opción a ejecutar y la retorna al main*/
{
    int opcion;
    cout<<"MENU LISTA DOBLEMENTE ENLAZADA\n"<<endl;
    cout<<"[1] Insertar un dato en la lista.\n";
    cout<<"[2] Eliminar un dato de la lista.\n";
    cout<<"[3] Eliminar toda la lista.\n";
    cout<<"[4] Buscar un dato\n";
    cout<<"[5] Modificar un dato\n";
    cout<<"[6] Imprimir Lista al derecho (recorrer) la lista.\n";
    cout<<"[7] Imprimir Lista al reves (recorrer).\n";
    cout<<"[8] Salir\n";
    cout<<"Elegir opcion: ";
    cin>>opcion;
    return opcion;
}

main(){
       system("color f0");
    Lista objeto;
    int opc; 
	int var;
	int cont;
    do{
        system("cls");
        opc=menu();
		switch ( opc ) {
		     case 1:
		          cout<<" Introduzca un numero:  ";
		          cin>>var;
		          objeto.Insertar ( var );
		          break;
		      case 2:
                   if(objeto.Empty()){
                          cout<<"\nLista vacia.\n";
                   }
                   else{
                          cout<<" ¿Que valor desea eliminar?  ";
        		          cin>>var;
        		          if(objeto.Eliminar ( var )){
                               cout<<"\nNodo eliminado. ";
                          }
                          else {
                              cout<<"\nEl valor no se encuentra en la lista. ";
                          }
                    }
		          break;
              case 3:
                   if(objeto.Empty()){
                          cout<<"\nLista vacia.\n";
                   }
                   else{
                       objeto.BorrarLista();
                   }
		          break;
              case 4:
                   if(objeto.Empty()){
                          cout<<"\nLista vacia.\n";
                   }
                   else{
                          cout<<" Que valor desea buscar?  ";
        		          cin>>var;
        		          cont=objeto.buscar ( var );
  		                  cout<<"El valor "<<var<<" aparece "<<cont<<" veces.\n";  
                    }
		          break;
              case 5:
                   if(objeto.Empty()){
                          cout<<"\nLista vacia.\n";
                   }
                   else {
                          cout<<" Que valor desea modificar?  ";
        		          cin>>var;
        		          if(objeto.modificar ( var )){
                               cout<<"Dato modificado";
                          }
                          else{
                              cout<<"No existe el dato";
                          }
                    }
		          break;
              case 6:
                   objeto.Imprimir1();
		          break;
              case 7:
                   objeto.Imprimir2();
		          break;
              case 8:
                   cout<<"Saliendo...\n\n";
		          break;
		     default:
    			     cout<<"Opcion invalida. \n\n" ;
    			break;
		}
		system("pause");
	}while(opc!=8);
}
