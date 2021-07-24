#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define lli long long int
#define rep(i, a, b) for (int i = a; i < b; i++)

const int N = 1e5 + 2, MOD = 1e9 + 7;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void bfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> ans;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        ans.push_back(x);
        for (int v : adj[x])
        {
            if (visited[v] != true)
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    //return ans;
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

    cout << "\nBFS\n";
    bfsOfGraph(nodes, list);
}