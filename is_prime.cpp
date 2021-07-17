#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int isPrime(int n)
{

    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (!(n & 1)) //check if n is even
    {
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) //factor of n found
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 11;
    int check = isPrime(n);
    if (check == 1)

    {
        cout << "Prime\n";
    }
    else
    {
        cout << "Not Prime\n";
    }
    return 0;
}
