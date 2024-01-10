//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        // Complete the function
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = n;

        int ans = 0;

        for (int i = n - 1; i > -1; i--)
        {
            sum = (sum + (arr[i] % k) + k) % k;

            if (!mp.count(sum))
                mp[sum] = i;
            else
                ans = max(ans, mp[sum] - i);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.longSubarrWthSumDivByK(arr, n, k) << "\n";
    }
    return 0;
}

// } Driver Code Ends