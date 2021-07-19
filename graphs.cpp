#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int N = 1e5 + 2, MOD = 1e9 + 7;

vi adjacencyList[N];

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

signed main()
{
    inputOutput();
    int nodes, edges;
    cin >> nodes >> edges;
    vvi adjacencyMatrix(nodes + 1, vi(nodes + 1, 0));

    rep(i, 0, edges)
    {
        int x, y;
        cin >> x >> y;
        adjacencyMatrix[x][y] = 1;
        adjacencyMatrix[y][x] = 1;
    }

    cout << "Adjacency matrix of given graph: \n";
    rep(i, 1, edges + 1)
    {
        rep(j, 1, edges + 1)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    if (adjacencyMatrix[3][7] == 1)
    {
        cout << "There is an edge between 3 and 7\n";
    }
    else
    {
        cout << "No Edges\n";
    }

    /*
    Adjacency List
    */
    cout << "\n\n\n";
    cin >> nodes >> edges;

    rep(i, 0, edges)
    {
        int x, y;
        cin >> x >> y;
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    cout << "Adjacency List of the above graph is given by: \n";

    rep(i, 1, nodes + 1)
    {
        cout << i << " -> ";
        for (int x : adjacencyList[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
