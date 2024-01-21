//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int vertexCover(int num_nodes, vector<pair<int, int>> &edges)
    {
        // code here
        if (num_nodes == 0)
        {
            return 0;
        }
        // Initialize separate vectors for edges connected to two different vertices.
        vector<pair<int, int>> first_vertex_edges, second_vertex_edges;

        // Get the first edge to compare with other edges.
        int first_vertex = edges[0].first;
        int second_vertex = edges[0].second;
        int count_first_vertex = 0, count_second_vertex = 0;

        // Iterate through the edges to categorize them based on their vertices.
        for (auto edge : edges)
        {
            int vertex1 = edge.first;
            int vertex2 = edge.second;

            // Check if the current edge is not connected to the first vertex.
            if (!(vertex1 == first_vertex || vertex2 == first_vertex))
            {
                first_vertex_edges.push_back({vertex1, vertex2});
                count_first_vertex++;
            }

            // Check if the current edge is not connected to the second vertex.
            if (!(vertex1 == second_vertex || vertex2 == second_vertex))
            {
                second_vertex_edges.push_back({vertex1, vertex2});
                count_second_vertex++;
            }
        }

        // Recursively find the minimum vertex cover size for both sets of edges.
        return 1 + min(
                       vertexCover(count_first_vertex, first_vertex_edges),
                       vertexCover(count_second_vertex, second_vertex_edges));
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            edges.push_back({a, b});
        }
        Solution s;
        cout << s.vertexCover(n, edges) << endl;
    }
    return 0;
}
// } Driver Code Ends