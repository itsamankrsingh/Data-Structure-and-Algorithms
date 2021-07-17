#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> sieveOfEratosthenes(int n)
{
    int *primes = new int[n + 1];
    //memset(primes, 1, n + 1);
    for (int i = 0; i <= n; i++)
    {
        primes[i] = 1;
    }

    primes[0] = 0;
    primes[1] = 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        //cout << "i-> " << i << " primes[i]-> " << primes[i] << " ";
        //cout << endl;
        if (primes[i] == 1)
        {

            for (int j = 2; j * i <= n; j++)
            {
                //cout << "j-> " << j << " ";
                primes[i * j] = 0;
                //cout << " i*j-> " << i * j << " primes[i*j]-> " << primes[i * j] << "\n ";
            }
        }
        //cout << endl;
    }

    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        //cout << "i->" << i << " primes[i]->" << primes[i] << "\n";
        if (primes[i] == 1)
        {
            //cout << "running i->" << i << " ";
            ans.push_back(i);
            //cout << "ans[i]->" << ans[i] << endl;
        }
    }
    ///cout << endl;
    return ans;
}

int main()
{
    inputOutput();
    int n = 18;
    vector<int> v;
    vector<int>::iterator it;
    v = sieveOfEratosthenes(n);
    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i] << " ";
    }
    cout << endl;
}
