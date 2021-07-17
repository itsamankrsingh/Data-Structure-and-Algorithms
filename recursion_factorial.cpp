#include <iostream>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int Factorial(int n)
{
    cout << "I am calculating F(" << n << ")\n";
    if (n == 0)
    {
        return 1;
    }
    int F = n * Factorial(n - 1);
    cout << "Done! F(" << n << ") = " << F << endl;
    return F;
}

int main()
{
    inputOutput();
    int n;
    cin >> n;
    cout << Factorial(n);
}
