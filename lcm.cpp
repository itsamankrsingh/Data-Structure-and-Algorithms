#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long gcd(long long a, long long b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

vector<long long> lcmAndGcd(long long a, long long b)
{
    vector<long long> v;
    v.push_back(lcm(a, b));
    v.push_back(gcd(a, b));
    return v;
}

int main()
{
    inputOutput();
    int a = 15;
    int b = 20;
    cout << "gcd-> " << gcd(a, b) << endl;
    cout << "lcm-> " << lcm(a, b) << endl;
    vector<long long> v;
    v = lcmAndGcd(a, b);
    for (int i = 0; i < 2; i++)
    {
        cout << v[i] << " ";
    }
}