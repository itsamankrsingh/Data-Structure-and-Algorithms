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

vector<int> factors(int n)
{
    vector<int> factorList;
    //vector<int>::iterator it;

    for (int i = 1; i <= sqrt(n); i++)
    {
        //cout << "i->" << i << " ";
        if (n % i == 0)
        {
            factorList.push_back(i);
            if (i != sqrt(n))
            {
                factorList.push_back(n / i);
            }
        }
    }
    sort(factorList.begin(), factorList.end());
    /*for (it = factorList.begin(); it != factorList.end(); it++)
    {

        cout << *it << " ";
    }*/
    return factorList;
}

int kThSmallestFactor(int n, int k)
{
    vector<int> v;
    v = factors(n);
    if (k > v.size())
    {
        return -1;
    }
    int ans = v[k - 1];
    return ans;
}

int main()
{
    inputOutput();
    int n = 8;
    int k = 5;
    /*vector<int> v;
    vector<int>::iterator it;
    v = factors(n);
    //cout << "running";
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }*/

    cout << kThSmallestFactor(n, k);
}