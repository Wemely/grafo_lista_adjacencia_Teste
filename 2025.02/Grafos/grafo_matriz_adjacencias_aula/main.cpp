#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo g1(6);
        g1.imprime();

        Aresta e(0, 5);
        g1.insere_aresta(e);
        g1.insere_aresta(Aresta(2, 4));
        cout << "\n";
        g1.imprime();

        g1.remove_aresta(Aresta(1, 3));
        g1.insere_aresta(Aresta(2, 2));
        cout << "\n";
        g1.imprime();

    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
