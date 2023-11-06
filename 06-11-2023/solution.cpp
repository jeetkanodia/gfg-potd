//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int hop = queries[i][0];
            int r = queries[i][1];
            int c = queries[i][2];
            if (hop == 1)
            {
                int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
                int sum = 0;
                for (int j = 0; j < 8; j++)
                {
                    int nr = r + dx[j];
                    int nc = c + dy[j];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m)
                    {
                        sum += mat[nr][nc];
                    }
                }
                ans.push_back(sum);
            }
            else
            {
                int dx[] = {-2, -2, 2, 2, -2, 2, 0, 0, -2, -2, 2, 2, -1, 1, -1, 1};
                int dy[] = {-2, 2, -2, 2, 0, 0, -2, 2, -1, 1, -1, 1, -2, -2, 2, 2};
                int sum = 0;
                for (int j = 0; j < 16; j++)
                {
                    int nr = r + dx[j];
                    int nc = c + dy[j];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m)
                    {
                        sum += mat[nr][nc];
                    }
                }
                ans.push_back(sum);
            }
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
        int n, m, q, ty, i, j;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        cin >> q;
        vector<int> queries[q];
        for (int k = 0; k < q; k++)
        {
            cin >> ty >> i >> j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }

        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for (int u : ans)
            cout << u << "\n";
    }
    return 0;
}
// } Driver Code Ends