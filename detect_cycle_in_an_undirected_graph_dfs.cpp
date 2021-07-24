#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool dfsCycle(int current, int prev, vector<bool> &visited, vector<int> adj[])
{
    visited[current] = true;

    for (auto it : adj[current])
    {
        if (!visited[it])
        {
            if (dfsCycle(it, current, visited, adj))
            {
                return true;
            }
        }
        else if (it != prev)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V + 1, false);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (dfsCycle(i, -1, visited, adj))
            {
                return true;
            }
        }
    }
    return false;
}

signed main()
{
    inputOutput();
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> list[nodes];

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        list[x].push_back(y);
        list[y].push_back(x);
    }

    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (int x : list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    if (isCycle(nodes, list))
    {
        cout << "\nCycle Found\n";
    }
    else
    {
        cout << "\nCycle Not Found\n";
    }
}