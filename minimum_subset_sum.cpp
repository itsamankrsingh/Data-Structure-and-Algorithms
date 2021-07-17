#include <iostream>
#include <vector>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// Returns the minimum value of the difference of the two sets.
int subsetSum(int arr[], int sum, int n)
{
    // Create an array to store results of subproblems
    bool t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            // Initialize top row, except dp[0][0], as false. With
            // 0 elements, no other sum except 0 is possible
            if (i == 0)
            {
                t[i][j] = false;
            }
            // Initialize first column as true. 0 sum is possible
            // with all elements.
            if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }

    /*
        finding subset sum
    */
    // Fill the partition table in bottom up manner
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // Initialize difference of two sums.
    int diff = INT_MAX;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--)
    {
        if (t[n][j] == true)
        {
            //cout << (sum - 2 * j) << endl;
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

int minDifference(int arr[], int n)
{
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    //cout << sum << endl;
    return subsetSum(arr, sum, n);
}

int main()
{

    int arr[] = {1, 6, 11, 5};
    int n = 4;
    cout << minDifference(arr, n) << endl;
}