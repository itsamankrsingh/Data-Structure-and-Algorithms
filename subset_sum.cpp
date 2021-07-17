#include <iostream>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool subsetSum(int arr[], int n, int sum)
{
    //base condition
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }

    if (arr[n - 1] > sum)
    {
        return subsetSum(arr, n - 1, sum);
    }
    return (subsetSum(arr, n - 1, sum - arr[n - 1]) || subsetSum(arr, n - 1, sum));
}

int main()
{

    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subsetSum(arr, n, sum) == true)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}