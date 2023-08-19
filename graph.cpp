#include "./graph.h"

Graph::Graph(vector<int>::size_type size)
{
    this->V = size;
    adj.resize(size, vector<Node>());
}

void Graph::addElement(vector<int>::size_type v, vector<int>::size_type w)
{
    Node n = {v, w};
    adj[v].push_back(n);
}

vector<Node> Graph::getElements(vector<int>::size_type v)
{
    return adj[v];
}