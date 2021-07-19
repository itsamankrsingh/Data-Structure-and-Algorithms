#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define lli long long int

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int euclid_gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return euclid_gcd(b, a % b);
}

int gcd(int n, int arr[])
{
    if (n == 1)
    {
        return arr[0];
    }
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = euclid_gcd(res, arr[i]);
    }
    return res;
}

int main()
{
    inputOutput();
    int n = 6;
    int arr[] = {1, 9, 2, 50, 7, 15, 36};
    cout << gcd(n, arr);
}