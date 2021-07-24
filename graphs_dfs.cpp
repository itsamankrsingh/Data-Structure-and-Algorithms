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
void dfs(int node, vector<bool> &visited, vector<int> adj[], vector<int> &dfsList)
{
    visited[node] = true;
    dfsList.push_back(node);
    for (auto it : adj[node])
    {
        if (visited[it] == false)
        {
            dfs(it, visited, adj, dfsList);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V + 1, false);
    vector<int> dfsList;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, dfsList);
        }
    }
    return dfsList;
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

    cout << "\nDFS\n";
    vector<int> dfsList = dfsOfGraph(nodes, list);
    for (int i = 0; i < nodes; i++)
    {
        cout << dfsList[i] << " ";
    }
}