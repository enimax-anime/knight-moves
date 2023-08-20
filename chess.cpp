#include <cctype>
#include <string>
#include <iostream>
#include "./utils.cpp"

using namespace std;

void test()
{
    for (int i = 0; i <= 63; i++)
    {
        for (int j = 0; j <= 63; j++)
        {
            cout << i << " " << j << endl;
            Graph g = consturctGraph();
            vector<int> result = moveFromTo(i, j, g);
            vector<int>::size_type currentValue = j;

            while (currentValue != i)
            {
                cout << numberToAlphaNum(currentValue) << endl;
                currentValue = result[currentValue];
            }

            cout << numberToAlphaNum(i) << endl;
        }
    }
}

int main()
{
    // Populate the graph with every possible
    // move
    Graph g = consturctGraph();

    // The initial and final position of the knight
    string fromString = "a1";
    string toString = "c2";

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
        cout << numberToAlphaNum(currentValue) << endl;
        currentValue = result[currentValue];
    }

    cout << numberToAlphaNum(from) << endl;

    test();
    return 0;
}
