//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int help(int i, int j, int n, int m)
    {
        if (j == n)
            return 1;
        if (i > m)
            return 0;

        int pick = help(i * 2, j + 1, n, m);
        int not_pick = help(i + 1, j, n, m);

        return pick + not_pick;
    }
    int numberSequence(int m, int n)
    {
        return help(1, 0, n, m);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        Solution ob;
        cout << ob.numberSequence(m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends