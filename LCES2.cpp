#include <iostream>
using namespace std;

int menu();

class Nodo
{
	public:
		int info;
		Nodo *sig;
		Nodo()
		{
			sig=NULL;
		}
		Nodo(int valor)
		{
		 info=valor;
		 sig=NULL;
		}			
};

class Lista
{
	public:
	Nodo *inicio, *auxiliar, *fin;
	int tam;
	Lista()
	{
	       inicio = NULL;
           fin = NULL;	
           tam=0;		
	}
	
	int Empty ( )
    {
    	return inicio == NULL ;
    }
    
    void Imprimir()
    {
            int i;
            auxiliar=inicio;
    		cout<<"La lista es: \n";
    		for(i=0; i<tam; i++)
    		{
                   cout<<auxiliar->info<<" -> ";
    			   auxiliar = auxiliar->sig;
            }
            cout<<"...(se repite)\n";
    }
    
     void BorrarLista()
    {
        auxiliar=inicio;
        while(auxiliar != NULL && auxiliar!=fin)
  		{
    			inicio=inicio->sig;
    			delete auxiliar;
    			auxiliar=inicio;
  		}
  		inicio = fin = NULL;
        tam=0;
        
  		cout<<"\nLISTA ELIMINADA\n\n";
    }
		
	void Insertar(int valor)
    {
         Nodo *temp, *anterior, *actual;
         int i;
		 temp = new Nodo(valor);
		 if(temp!=NULL)
		 {
             anterior = NULL; 
		     actual = inicio;
		     for(i=0;i<tam;i++)
		     {
                  if(valor > actual->info) 
                  {
    			      anterior = actual;
    			      actual = actual ->sig;
                  }
             }
            if ( anterior == NULL )   
            {
                 if(inicio == NULL)
                 {
                      temp->sig = temp;
                      inicio = temp;
                      fin = temp;
                 }
                 else
                 {
                     temp->sig = inicio;
    			     inicio = temp;
    			     fin->sig = inicio;
                 }
                 tam++;
    		}
            else 
            {
                 anterior->sig = temp;
                 temp->sig = actual;
                 if(anterior == fin)
                 {
                     fin=temp;
                 }
    			tam++;
    		}
        }   
    }
	    
    int Eliminar(int valor)
    {
        Nodo *temp, *anterior, *actual;
        int i;
            if ( valor==inicio->info ) 
            {
                 if(inicio==fin)
                 {
                    inicio=fin=NULL;
                 }
                 else
                 {
                     temp = inicio;
        		     inicio = inicio ->sig; 
        		     fin->sig=inicio;
        		     delete temp;
                 }
                 tam--;
                return 1;  
        	}
        	else   
            {
        		anterior = NULL;
        		actual = inicio; 
        
                for(i=0;i<tam;i++)
    		     {
                      if(valor != actual->info) 
                      {
        			      anterior = actual;
        			      actual = actual ->sig;
                      }
                 }
        		if ( actual != inicio)  
                {
        			temp = actual; 
        			anterior->sig = actual->sig;
        			if(temp==fin)
        			{
                        fin = anterior;
                    }
        			delete temp;
        			tam--;
        			return 1;
        		} 
        		
        	}  
        	 
        	return (0);
    }
    
    int buscar(int valor) {
         int cont=0,i;
         auxiliar=inicio;
        for(i=0;i<tam;i++)	{
              if(auxiliar->info == valor){
                   cont++;
              }
              auxiliar=auxiliar->sig;
  		}
  		return cont;
    }
    
    int modificar(int valor) {
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
		//Liberar la memoria asignada de manera dinámica
        auxiliar=inicio;
        while(auxiliar != NULL && auxiliar!=fin)
  		{
    			inicio=inicio->sig;
    			delete auxiliar;
    			auxiliar=inicio;
  		}
  		inicio = fin = NULL;
	}
};  //Fin de la clase Lista

int menu ()/*Lee la opción a ejecutar y la retorna al main*/
{
    int opcion;
    cout<<"MENU LISTA CIRCULAR SIMPLEMENTE ENLAZADA\n"<<endl;
	cout<<"[1] Insertar un dato en la lista.\n";
    cout<<"[2] Eliminar un dato de la lista.\n";
    cout<<"[3] Eliminar toda la lista.\n[4] Buscar un elemento\n";
    cout<<"[5] Modificar un dato.\n";
    cout<<"[6] Imprimir Lista (recorrer) la lista.\n[7] Salir\n";
    cout<<"Eliegir opcion: ";
    cin>>opcion;
    return opcion;
}

main()
{
      system("color f0");
    Lista objeto;
    int opc; 
	int var;
	int cont;
    do
    {
        system("cls");
        opc=menu();
		switch ( opc ) 
        {

		     case 1:
		          cout<<" Introduzca un numero:  ";
		          cin>>var;
		          objeto.Insertar ( var );
		          break;
		      case 2:
                   if(objeto.Empty())
                   {
                          cout<<"\nLista vacia.\n";
                   }
                   else
                   {
                          cout<<" Que valor desea eliminar?  ";
        		          cin>>var;
        		          if(objeto.Eliminar ( var ))
        		          {
                               cout<<"\nNodo eliminado. ";
                          }
                          else
                          {
                              cout<<"\nEl valor no se encuentra en la lista. ";
                          }
                    }
		          break;
              case 3:
                   if(objeto.Empty())
                   {
                          cout<<"\nLista vacia.\n";
                   }
                   else
                   {
                       objeto.BorrarLista();
                   }
		          break;
              case 4:
                   if(objeto.Empty())
                   {
                          cout<<"\nLista vacia.\n";
                   }
                   else
                   {
                          cout<<" ¿Que valor desea buscar?  ";
        		          cin>>var;
        		          cont=objeto.buscar ( var );
  		                  cout<<"El valor "<<var<<" aparece "<<cont<<" veces.\n";  
                    }
		          break;
              case 5:
                   if(objeto.Empty())
                   {
                          cout<<"\nLista vacia.\n";
                   }
                   else
                   {
                          cout<<" Que valor desea modificar?  ";
        		          cin>>var;
        		          if(objeto.modificar ( var ))
        		          {
                               cout<<"Dato modificado";
                          }
                          else
                          {
                              cout<<"No existe el dato";
                          }
                    }
		          break;
              case 6:
                   if(objeto.Empty())
                   {
                          cout<<"\nLista vacia.\n";
                   }
                   else
                   {
                       objeto.Imprimir();
                   }
		          break;
              case 7:
                   cout<<"Saliendo...\n\n";
		          break;
		     default:
    			     cout<<"Opcion invalida. \n\n" ;
    			break;
		}
		system("pause");
	}while(opc!=7);
}
