#include <iostream>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool subsetSum(int arr[], int n, int sum)
{
    bool t[n + 1][sum + 1];

    //initialization
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{

    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subsetSum(arr, n, sum) == true)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}