#include "./graph.h"

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V, vector<Node>());
}

void Graph::addElement(int v, int w)
{
    Node n = {v, w};
    adj[v].push_back(n);
}

vector<Node> Graph::getElements(int v)
{
    return adj[v];
}