#include "grafo.h"
#include "iomanip"
#include <iostream>

using std::setw;
using std::cout;

#define INFINITO 0;

Grafo::Grafo()
{
    vertices = 0;
    nvertices = 0;
    aristas = 0;
}

void Grafo::AgregarVertice(char id)
{
        char* vertices_cpy = new char[nvertices +1];

        for (size_t i = 0; i < nvertices; i++)
        {
            vertices_cpy[i] = vertices[i];
        }

        vertices_cpy[nvertices] = id;


        if (nvertices !=0)
        {
            delete vertices;
        }
        
        vertices = vertices_cpy;
        //nvertices ++;
        
        //seccion de aristas


        //Aristas Filas
        int** aristasFilasCpy = new int*[nvertices+1];
        int** costosCpy = new int*[nvertices+1];
        for (size_t i = 0; i < nvertices; i++)
        {
            aristasFilasCpy[i] = aristas[i];
            costosCpy[i] = costos[i];
        }
        
        if(aristas !=0 )
            delete aristas;

        if(costos != 0)    
            delete costos;    

        aristas = aristasFilasCpy;
        costos = costosCpy;
        //Aristas columnas

        for (size_t i = 0; i < nvertices; i++)
        {
            int* aristasColCpy = new int[nvertices+1];
            int* costosColCpy = new int[nvertices+1];
            for (size_t j = 0; j < nvertices; j++)
            {
                aristasColCpy[j] =aristas[i][j]; 
                costosColCpy[j] = costos[i][j];

            }

            if (aristas[i]!=0)
            {
                delete aristas[i];
            }
 
            if(costos[i]!=0)
            {
                delete costos[i];
            }

            aristasColCpy[nvertices] = 0;
            costosColCpy[nvertices] = INFINITO;

            aristas[i] = aristasColCpy;
            costos[i] = costosColCpy;
            
        }
        
        int* aristaUltimaFila = new int[nvertices + 1];
        int* costosUltimaFila = new int[nvertices + 1];
        for (size_t i = 0; i <= nvertices; i++)
        {
            aristaUltimaFila[i] = 0;
            costosUltimaFila[i] = INFINITO;
        }
        aristas[nvertices] = aristaUltimaFila;
        costos[nvertices] = costosUltimaFila;

        nvertices++;
        



}

void Grafo::AgregarArista(char origen,char destino,int costo)
{
    int fila =  obtenerIndiceVertice(origen);
    int columna = obtenerIndiceVertice(destino);

    if (fila != -1 && columna != -1)
    {
    aristas[fila][columna] = 1;
    aristas[columna][fila] = 1;

     costos[fila][columna] = costo;
     costos[columna][fila] = costo;


    }
    



}

void Grafo::imprimir()
{

    cout << setw(2) << " ";
    for (size_t i = 0; i < nvertices; i++)
    {
        cout << setw(2) << vertices[i];
        
        
    }
            cout << "\n";


for (size_t i = 0; i < nvertices; i++)
{
    cout << setw(2) << vertices[i];
    for (size_t j = 0; j < nvertices; j++)
    {
        cout<< setw(2) << aristas[i][j] ;
    }
    cout << "\n";
}



//imprimiendo costo

    cout << setw(6) << " ";
    for (size_t i = 0; i < nvertices; i++)
    {
        cout << setw(6) << vertices[i];
        
        
    }
            cout << "\n";


for (size_t i = 0; i < nvertices; i++)
{
    cout << setw(6) << vertices[i];
    for (size_t j = 0; j < nvertices; j++)
    {
        cout<< setw(6) << costos[i][j];
    }
    cout << "\n";
}
    


}


int Grafo::obtenerIndiceVertice(char id)
{

    for (size_t i = 0; i < nvertices; i++)
    {
        if (vertices[i] == id)
        {
            return i;
        }
    }

    return -1;
}



void Grafo::floyd()
{
for(k = 0; k < nVertices; k++) {
		for(i = 0; i < nVertices; i++) {
			for(j = 0; j < nVertices; j++) {
				if(costo[i][k] + costo[k][j] < costo[i][j]) {
					costo[i][j] = costo[i][k] + costo[k][j];
				}
			}
		}
	}

}