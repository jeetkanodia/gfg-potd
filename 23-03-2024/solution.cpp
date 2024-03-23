//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> Series(int n)
    {
        // Code here
        int MOD = 1e9 + 7;
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        for (int i = 1; i < n; i++)
        {
            v.push_back((v[i] + v[i - 1]) % MOD);
        }
        return v;
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
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends