#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using  namespace std;

struct Aresta {
    int u, v;
    Aresta(int u, int v) : u(u), v(v) {}
};

class Grafo{
public:
    Grafo(int vertices);
    int num_vertices();
    int num_arestas();
    void adicionarAresta(int u, int v);
    void mostrarGrafo();
    void remove_aresta(Aresta e);
    bool eh_Conexo();
    bool tem_aresta(Aresta e);

private:
    
    int V; // número de vértices
    int E; // número de arestas
    vector<vector<int>> adj; // lista de adjacência

};

#endif