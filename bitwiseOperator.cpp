#include <bits/stdc++.h>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool checkEvenOrOdd(int n)
{
    //odd return true
    if (n & 1)
        return true;

    //even return false
    return false;
}

/*
right shifting an integer “x” with an integer “y” 
denoted as ‘(x>>y)‘ is equivalent to dividing x with 2^y. 
*/
int rightShift(int x, int y)
{
    return x >> y;
}

/*left shifting an integer “x” with an integer “y”
 denoted as ‘(x<<y)’ is equivalent
  to multiplying x with 2^y (2 raised to power y). */
int leftShift(int x, int y)
{
    return x << y;
}

int main()
{
    inputOutput();
    int n;
    cin >> n;
    cout << n << endl;
    if (checkEvenOrOdd(n))
    {
        cout << "Odd\n";
    }
    else
    {
        cout << "Even\n";
    }

    int x, y;
    cin >> x >> y;

    cout << "Right Shift of " << x << " and " << y
         << " is-> " << rightShift(x, y) << endl;

    int a, b;
    cin >> a >> b;

    cout << "Left Shift of " << a << " and " << b
         << " is-> " << leftShift(a, b) << endl;

    return 0;
}