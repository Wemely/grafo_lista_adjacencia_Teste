#include "Grafo.h"
#include <iostream>

using  namespace std;


// Programa principal
int main() {

    try{ 
        int V = 5; // número de vértices
        Grafo g(V);

        // Adicionando algumas arestas
        g.adicionarAresta(0, 1);
        g.adicionarAresta(0, 4);
        g.adicionarAresta(1, 2);
        g.adicionarAresta(1, 3);
        g.adicionarAresta(1, 4);
        g.adicionarAresta(2, 3);
        g.adicionarAresta(3, 4);

        // Mostrando o grafo
        g.mostrarGrafo();

    }
    catch(const exception &e){
        cerr << " exception "<< e.what() << '\n';
    }

    return 0;
}