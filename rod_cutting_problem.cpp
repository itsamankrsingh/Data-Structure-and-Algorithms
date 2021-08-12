#include <iostream>
#include <cstring>
using namespace std;

void inputOutput()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int cutRod(int price[], int n)
{
    int *length = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        length[i] = i + 1;
    }

    /*for (int i = 1; i < n + 1; i++)
    {
        cout << length[i] << " ";
    }
    cout << endl;*/

    int t[n + 1][n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                t[i][j] = max((price[i - 1] + t[i][j - length[i - 1]]), t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    /*for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }*/
    return t[n][n];
}

int main()
{
    inputOutput();
    int n;
    cin >> n;

    int *price = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    cout << cutRod(price, n);
}