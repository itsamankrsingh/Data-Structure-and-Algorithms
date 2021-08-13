#include <iostream>
#include <cstring>
using namespace std;

void inputOutput()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

long long int count(int coins[], int n, int sum)
{
    long long int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }

            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j] + t[i][j - coins[i - 1]]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    /*for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }*/

    return t[n][sum];
}

int main()
{
    inputOutput();
    int sum, n;
    cin >> sum >> n;
    int *coins = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << count(coins, n, sum) << endl;

    return 0;
}