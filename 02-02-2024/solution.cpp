//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string s)
    {
        // Your code here
        int num = 0;
        bool minus = false;
        if (s[0] == '-')
            minus = true;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (i == 0 && minus)
                continue;
            else
            {
                if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
                {
                    num += s[i] - '0';
                    if (INT_MAX / 10 < num)
                        return minus == true ? num * -1 : num;
                    num = num * 10;
                    // cout<<num<<endl;
                }
                else
                    return -1;
            }
        }
        num = num / 10;
        return minus == true ? num * -1 : num;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}
// } Driver Code Ends