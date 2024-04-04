//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s)
    {

        // your code here
        int MOD = 1e9 + 7;
        long long ans = 0;
        int n = s.size();
        long long prev = 0, curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr = (prev * 10) % MOD + (i + 1) * (s[i] - '0') % MOD;
            prev = curr;
            ans = (ans + curr) % MOD;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking string
        string s;
        cin >> s;
        Solution ob;
        // calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
    }
    return 0;
}

// } Driver Code Ends