#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int parent;
    int value;
};

class Graph
{
    int V;
    vector<vector<Node>> adj;

public:
    Graph(int V);

    void addElement(int v, int w);

    vector<Node> getElements(int v);
};

#endif
