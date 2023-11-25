//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    void solve(int arr[], int i, int j, int n)
    {
        if (n <= 0)
            return;

        int a = arr[i];
        int b = arr[j];

        solve(arr, i - 1, j - 1, n - 2);

        arr[n - 2] = a;
        arr[n - 1] = b;
    }
    void shuffleArray(int arr[], int n)
    {
        int i = n / 2 - 1;
        int j = n - 1;
        solve(arr, i, j, n);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.shuffleArray(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends