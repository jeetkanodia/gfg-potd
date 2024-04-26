//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>> &mat)
    {
        // Code here
        int i = 0, j = 0;
        int dir = 1;
        while (i >= 0 && j >= 0 && i < n && j < m)
        {
            if (mat[i][j] == 1)
            {
                mat[i][j] = 0;
                dir = (dir % 4) + 1;
            }

            if (dir == 1)
                j++;
            else if (dir == 2)
                i++;
            else if (dir == 3)
                j--;
            else
                i--;
        }
        if (dir == 1)
            j--;
        else if (dir == 2)
            i--;
        else if (dir == 3)
            j++;
        else
            i++;

        return {i, j};
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends