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

vector<pair<lli, lli>> primeFactors(int n)
{
    vector<pair<lli, lli>> factorList;
    //vector<int>::iterator it;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n /= i;
                count++;
            }
            factorList.push_back(make_pair(i, count));
        }
    }
    if (n != 1)
    {
        factorList.push_back(make_pair(n, 1));
    }
    return factorList;
}

lli largestPrimeFactor(int n)
{
    vector<pair<lli, lli>> v;
    v = primeFactors(n);
    return v[v.size() - 1].first;
}

int main()
{
    inputOutput();
    int n = 36;
    /*vector<pair<lli, lli>> v;
    //vector<pair<lli, lli>>::iterator it;
    v = primeFactors(n);
    //cout << "running";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << "^" << v[i].second << endl;
    }*/

    cout << largestPrimeFactor(n);
    return 0;
}