#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include <queue>
#include <stack>

class Grafo {
public:
    /** Constroi um grafo simples que possui o numero de vertices recebido por
     *  parametro e que nao possui arestas */
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);

    /** Insere uma aresta no grafo caso a aresta ainda nao exista no grafo e
     * nao seja um laco */
    void insere_aresta(Aresta e);

    /** Remove uma aresta do grafo caso a aresta exista no grafo */
    void remove_aresta(Aresta e);

    void imprime();

    // bool eh_passeio(std::vector<int> &seq_verts);

    bool eh_Conexo();

    bool caminho(int v, int w, int marcado[]);

    void busca_prof(int v);
    
    void busca_larg(int v, int pai[], int dist[]);
    
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;
};

#endif /* GRAFO_H */
