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
bool checkForCycle(int current, int V, vector<bool> &visited, vector<int> adj[])
{
    vector<int> parent(V, -1);

    // Create a queue for BFS
    queue<pair<int, int>> q;

    visited[current] = true;
    q.push({current, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push({it, node});
            }
            else if (parent != it)
            {
                return true;
            }
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
            if (checkForCycle(i, V, visited, adj))
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