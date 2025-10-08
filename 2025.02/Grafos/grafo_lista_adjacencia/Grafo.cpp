#include "Grafo.h"
#include <iostream>


Grafo::Grafo(int vertices) {
    V = vertices;
    E = 0;
    adj.resize(V); // cria V listas vazias
}

int Grafo::num_vertices() {
    return V;
}

int Grafo::num_arestas() {
    return E;
}


// Adiciona aresta (grafo não direcionado)
void Grafo::adicionarAresta(int u, int v) {
    adj[u].push_back(v); // adiciona v à lista de u
    adj[v].push_back(u); // adiciona u à lista de v
}

// Mostra o grafo
void Grafo::mostrarGrafo() {
    for (int i = 0; i < V; i++) {
        cout << "Vértice " << i << ": ";
        for (int vizinho : adj[i]) {
            cout << vizinho << " ";
        }
        cout << endl;
    }
}

bool tem_aresta(Aresta e) {
    for (int vizinho : adj[e.u]) {
        if (vizinho == e.v) return true;
    }
    return false;
}


void remove_aresta(Aresta e) {
    if (!tem_aresta(e)) return;
    adj[e.u].erase(remove(adj[e.u].begin(), adj[e.u].end(), e.v), adj[e.u].end());
    adj[e.v].erase(remove(adj[e.v].begin(), adj[e.v].end(), e.u), adj[e.v].end());
    E--;
}

bool Grafo::eh_Conexo() {
    vector<bool> visitado(V, false);
    queue<int> q;

    q.push(0);
    visitado[0] = true;

    int count = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int viz : adj[u]) {
            if (!visitado[viz]) {
                visitado[viz] = true;
                q.push(viz);
                count++;
            }
        }
    }
    return count == V;
}
