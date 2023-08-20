#include "./graph.cpp"

bool checkIfInRange(int num);
vector<int> findPossibleMoves(vector<vector<int>::size_type> placement);
Graph consturctGraph();
vector<int> alphaNumToIndex(string placement);
string indexToAlphaNum(vector<int> index);
string numberToAlphaNum(int elem);
vector<int>::size_type indexToNumber(string placement);
vector<int> moveFromTo(vector<int>::size_type from, vector<int>::size_type to, Graph &graph);

bool checkIfInRange(int num)
{
    if (num <= 7 && num >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<int> findPossibleMoves(vector<vector<int>::size_type> placement)
{
    vector<int> possibleMoves;

    for (int k = 0; k <= 1; k++)
    {
        vector<int>::size_type first = (k == 0) ? 2 : 1;
        vector<int>::size_type second = (k == 0) ? 1 : 2;

        for (vector<int>::size_type i = 0; i <= 1; i++)
        {
            for (vector<int>::size_type j = 0; j <= 1; j++)
            {
                vector<int>::size_type signX = (i * 2) - 1;
                vector<int>::size_type signY = (j * 2) - 1;

                vector<vector<int>::size_type> positionClone = placement;

                positionClone[0] += first * signX;
                positionClone[1] += second * signY;

                if (checkIfInRange(positionClone[0]) && checkIfInRange(positionClone[1]))
                {
                    possibleMoves.push_back(positionClone[0] * 8 + positionClone[1]);
                }
            }
        }
    }

    return possibleMoves;
}

Graph consturctGraph()
{
    Graph graph = Graph(64);

    for (vector<int>::size_type i = 0; i <= 7; i++)
    {
        for (vector<int>::size_type j = 0; j <= 7; j++)
        {
            vector<int> possibleMoves = findPossibleMoves({i, j});

            for (vector<int>::size_type k = 0; k < possibleMoves.size(); k++)
            {
                graph.addElement(i * 8 + j, possibleMoves[k]);
            }
        }
    }

    return graph;
}

vector<int> alphaNumToIndex(string placement)
{
    char alpha = placement[0];
    int num = placement[1] - '0';

    if (alpha >= 'A' && alpha <= 'Z')
    {
        alpha = alpha + 32;
    }

    vector<int> index = vector<int>(2);

    index[0] = alpha - 'a';
    index[1] = num;

    return index;
}

string indexToAlphaNum(vector<int> index)
{
    string result = "";

    result += (char)(index[0] + 97);
    result += (char)(index[1] + '1');

    return result;
}

string numberToAlphaNum(int elem)
{
    return indexToAlphaNum({elem / 8, elem % 8});
}

vector<int>::size_type indexToNumber(string placement)
{
    auto result = alphaNumToIndex(placement);
    return result[0] * 8 + result[1] - 1;
}

vector<int> moveFromTo(vector<int>::size_type from, vector<int>::size_type to, Graph &graph)
{
    vector<Node> toCheck = graph.getElements(from);
    vector<bool> visited = vector<bool>(64, false);
    vector<int> pathTaken = vector<int>(64);
    vector<int>::size_type start = 0;

    visited[from] = true;
    for(Node node : toCheck){
        pathTaken[node.value] = node.parent;
        visited[node.value] = true;

        if(node.value == to){
            return pathTaken;
        }
    }

    while (true)
    {
        vector<int>::size_type currentLength = toCheck.size();

        for (vector<int>::size_type i = start; i < currentLength; i++)
        {
            vector<Node> currentPlacement = graph.getElements(toCheck[i].value);

            for (vector<int>::size_type j = 0; j < currentPlacement.size(); j++)
            {
                if (currentPlacement[j].value == to)
                {
                    toCheck.push_back(currentPlacement[j]);
                    pathTaken[currentPlacement[j].value] = currentPlacement[j].parent;
                    return pathTaken;
                }
                else if (!visited[currentPlacement[j].value])
                {
                    toCheck.push_back(currentPlacement[j]);
                    visited[currentPlacement[j].value] = true;
                    pathTaken[currentPlacement[j].value] = currentPlacement[j].parent;
                }
            }
        }
        start = currentLength;
    }
}