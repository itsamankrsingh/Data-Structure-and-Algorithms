#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int MOD = 1e9 + 7;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
iterative
*/
int power(int a, int n)
{
    a %= MOD;
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
        { // n is odd
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans;
}

/*
recursive
*/
int power_recursive(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int p = ((power(a, n >> 1) % MOD));
    if (n & 1)
    {
        return ((((p * p) % MOD) * a) % MOD);
    }
    else
    {
        return ((p * p) % MOD);
    }
}

signed main()
{
    inputOutput();
    int a, n;
    cin >> a >> n;
    cout << "Power Iterative-> " << power(a, n) << endl;
    cout << "Power Recursive-> " << power_recursive(a, n) << endl;
    return 0;
}