#include <cctype>
#include <string>
#include <iostream>
#include "./utils.cpp"

using namespace std;

int main()
{   
    // Populate the graph with every possible
    // move
    Graph g = consturctGraph();

    // The initial and final position of the knight
    string fromString = "a1";
    string toString = "h6";

    // Converting the alphanumeric position
    // to an int. For example,
    // "a1" -> [0, 0] -> 0 * 8 + 0 = 0
    // "h6" -> [7, 5] -> 7 * 8 + 5 = 61
    vector<int>::size_type from = indexToNumber(fromString);
    vector<int>::size_type to = indexToNumber(toString);

    // This vector is a map of what parent an index
    // must be approached from to get to the initial point
    // For example, if 'from' is 0 and 'to' is 61
    // the 61st index of this vector would have the value 51
    // the 51st index of this vector would have the value 34
    // the 34th index of this vector would have the value 17
    // the 17th index of this vector would have the value 0
    // Since we are at the initial point, this is our shortest path
    vector<int> result = moveFromTo(from, to, g);

    vector<int>::size_type currentValue = to;

    while (currentValue != from)
    {
        cout << (currentValue) << endl;
        currentValue = result[currentValue];
    }

    cout << (from) << endl;

    return 0;
}
