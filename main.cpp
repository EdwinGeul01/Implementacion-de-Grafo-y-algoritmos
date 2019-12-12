#include "grafo.h"

int main()
{

    Grafo gr;
    gr.AgregarVertice('A');
    gr.AgregarVertice('B');
    gr.AgregarVertice('C');
    gr.AgregarVertice('D');
    gr.AgregarVertice('E');
    gr.AgregarArista('A','B',10);
    gr.AgregarArista('A','C',20);
    gr.AgregarArista('D','A',30);
    gr.AgregarArista('D','C',40);



    gr.imprimir();



}