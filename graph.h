#ifndef GRAPH_H
#define GRAPH_H

#include "vector"

using namespace std;

struct Node
{
    vector<int>::size_type parent;
    vector<int>::size_type value;
};

class Graph
{
    vector<int>::size_type V;
    vector<vector<Node>> adj;

public:
    Graph(vector<int>::size_type V);

    void addElement(vector<int>::size_type v, vector<int>::size_type w);

    vector<Node> getElements(vector<int>::size_type v);
};

#endif
