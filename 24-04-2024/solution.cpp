//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int ways(int x, int y)
    {
        // code here.
        int MOD = 1000000007;
        int dp[x + 1][y + 1];
        for (int i = 0; i < x; i++)
        {
            dp[i][y] = 1;
        }

        for (int i = 0; i < y; i++)
        {
            dp[x][i] = 1;
        }

        for (int i = x - 1; i >= 0; i--)
        {
            for (int j = y - 1; j >= 0; j--)
            {
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.ways(x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends