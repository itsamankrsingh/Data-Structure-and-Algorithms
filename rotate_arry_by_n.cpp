#include <iostream>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Solution
{
public:
    //Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(int arr[], int k, int n)
    {
        int temp[k];
        for (int i = 0; i < k; i++)
        {
            temp[i] = arr[i];
        }
        /*for (int i = 0; i < k; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;*/
        for (int i = 0; i + k < n; i++)
        {
            arr[i] = arr[i + k];
            //cout << "i-> arr[i]-> " << arr[i] << endl;
        }
        for (int i = n - k, j = 0; i < n, j < k; i++, j++)
        {
            // cout << "i-> " << i << endl;

            //cout << arr[j] << " ";
            arr[i] = temp[j];
        }
        //cout << endl;

        /*for(int i=0;i<d;i++){
            arr[n-d+i]=temp[i];
        }*/

        for (int i = 0; i < n; i++)
        {
            //cout << "i-> ";
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    inputOutput();
    int arr[] = {1, 2, 3, 4, 5};
    Solution s = Solution();
    s.rotateArr(arr, 3, 5);
}