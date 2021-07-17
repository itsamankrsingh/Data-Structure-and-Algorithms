#include <iostream>
#include <cstring>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Memoization
*/
int t[1001][1001];

int knapSack(int W, int wt[], int val[], int N)
{
    memset(t, -1, sizeof(t));
    if (N == 0 || W == 0)
    {
        return 0;
    }
    if (t[N][W] != -1)
    {
        return t[N][W];
    }
    int ans;
    if (wt[N - 1] <= W)
    {
        ans = max((val[N - 1] + knapSack(W - wt[N - 1], wt, val, N - 1)),
                  knapSack(W, wt, val, N - 1));
        t[N][W] = ans;
    }
    else
    {
        ans = knapSack(W, wt, val, N - 1);
        t[N][W] = ans;
    }
    return ans;
}

int main()
{
    inputOutput();
    int N, W;
    cin >> N >> W;
    int wt[N];
    int val[N];
    for (int i = 0; i < N; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> wt[i];
    }
    cout << knapSack(W, wt, val, N);
}