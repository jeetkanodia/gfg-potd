//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int firstElement(int n)
    {
        // code here
        int arr[] = {1, 1, 1};
        int MOD = 1000000007;

        for (int i = 1; i < n; i++)
        {
            arr[2] = arr[0];
            arr[0] = (arr[0] + arr[1]) % MOD;
            arr[1] = arr[2];
        }

        return arr[1];
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
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends