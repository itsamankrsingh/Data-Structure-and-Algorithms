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

int knapSack(int W, int wt[], int val[], int N)
{
    int t[N + 1][W + 1];

    //initialization
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max((val[i - 1] + t[i - 1][j - wt[i - 1]]), t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[N][W];
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