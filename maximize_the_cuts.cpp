#include <iostream>
#include <cstring>
using namespace std;

void inputOutput()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int dp[10005];

int func(int n, int x, int y, int z)
{

    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;

    if (n >= x)
    {
        op1 = func(n - x, x, y, z);
    }

    if (n >= y)
    {
        op2 = func(n - y, x, y, z);
    }

    if (n >= z)
    {
        op3 = func(n - z, x, y, z);
    }

    return dp[n] = 1 + max(op1, max(op2, op3));
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    memset(dp, -1, sizeof(dp));

    int a = func(n, x, y, z);

    if (a < 0)
    {
        return 0;
    }

    return a;
}

int main()
{
    inputOutput();
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << maximizeTheCuts(n, x, y, z) << endl;

    return 0;
}