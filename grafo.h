#ifndef GRAFO_H
#define GRAFO_H

class Grafo
{
    private:
        char * vertices;
        int nvertices;
        int ** aristas;
        int ** costos;

    public:
        Grafo();
        void AgregarVertice(char id);
        void AgregarArista(char vertice_Origen , char vertice_Destino, int costos);
        void imprimir();
        int obtenerIndiceVertice(char id);
        void floyd();
};

#endif