#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices)
{
    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices); // resize função altera o número de elementos no vetor. 
    for (int i = 0; i < num_vertices; i++)
    {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices()
{
    return num_vertices_;
}

int Grafo::num_arestas()
{
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e)
{
    if (matriz_adj_[e.v1][e.v2] != 0)
    {
        return true;
    }
    return false;
}

void Grafo::insere_aresta(Aresta e)
{
    if (!tem_aresta(e) && (e.v1 != e.v2))
    {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e)
{
    if (tem_aresta(e))
    {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;

        num_arestas_--;
    }
}

void Grafo::imprime()
{
    for (int v = 0; v < num_vertices_; v++)
    {
        cout << v << ":";
        for (int u = 0; u < num_vertices_; u++)
        {
            if (matriz_adj_[v][u] != 0)
            {
                cout << " " << u;
            }
        }
        cout << "\n";
    }
}

bool Grafo::caminho(int v, int w, int marcado[])
{
    if (v == w)
    {
        printf("%d-", v);
        return true;
    }
    marcado[v] = 1;
    for (int u = 0; u < num_vertices_; u++)
        if (matriz_adj_[v][u] != 0)
            if (marcado[u] == 0)
                if (caminho(u, w, marcado))
                {
                    printf("%d-", v);
                    return true;
                }
    return false;
}

bool Grafo::eh_Conexo(){
    vector<int> verificar[num_vertices_];
    for(int i=0, i < num_vertices_ , i ++ ){
        verificar[i] = 0;
    }

    busca_prof(0,verificar);

    for(int u=0, u < num_vertices_ , u++ ){
        if(!verificar[u]){
            return false;
        }
    }

    return true;

}

void Grafo::busca_prof(int v)
{
    // Criacao e inicializacao do vetor marcado
    stack<int> pilha;
    int marcado[];
    pilha.push(v);
    while (!pilha.empty())
    {
        int w = pilha.top();
        pilha.pop();
        if (marcado[w] == 0)
        {
            printf("%d\n", w);
            marcado[w] = 1;
            for (int u = (num_vertices_ - 1); u >= 0; u--){ 
                if (matriz_adj_[w][u] != 0){ 
                    if (marcado[u] == 0){ 
                        pilha.push(u);
                    }        
                }        
            }           
        }
    }
}

void Grafo::busca_larg(int v, int pai[], int dist[])
{
    // Criacao e inicializacao do vetor marcado
    // Inicializacao dos vetores pai e dist
    queue<int> fila;
    int marcado[];
    marcado[v] = 1;
    pai[v] = -1;
    dist[v] = 0;
    fila.push(v);
    while (!fila.empty())
    {
        int w = fila.front();
        fila.pop();
        printf("%d\n", w);
        for (int u = 0; u < num_vertices_; u++)
        {
            if (matriz_adj_[w][u] != 0)
            {
                if (marcado[u] == 0)
                {
                    marcado[u] = 1;
                    pai[u] = w;
                    dist[u] = dist[w] + 1;
                    fila.push(u);
                }
            }
        }
    }
}
