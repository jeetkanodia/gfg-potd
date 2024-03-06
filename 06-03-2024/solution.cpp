//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> search(string pattern, string text)
    {
        // code here.
        vector<int> v;
        int n = text.size();
        int m = pattern.size();
        for (int i = 0; i < n; i++)
        {
            int temp = i;
            int j = 0;
            while (i < n && j < m)
            {
                if (text[i] == pattern[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i = temp;
                    j = 0;
                    break;
                }
            }
            if (j == m)
            {
                j = 0;
                v.push_back(temp + 1);
            }
            i = temp;
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends