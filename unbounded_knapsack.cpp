#include <iostream>
#include <cstring>
using namespace std;

void inputOutput()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int knapSack(int n, int w, int val[], int wt[])
{
    int t[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max((val[i - 1] + t[i][j - wt[i - 1]]), t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][w];
}

int main()
{
    inputOutput();
    int n, w;
    cin >> n >> w;

    int *val = new int[n];
    int *wt = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << knapSack(n, w, val, wt);
}