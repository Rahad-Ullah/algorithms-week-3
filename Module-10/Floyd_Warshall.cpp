#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj_matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_matrix[i][j] = 0; // Distance to self is 0
            else
                adj_matrix[i][j] = INT_MAX; // Initialize with infinity
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_matrix[a][b] = c;
        // adj_matrix[b][a] = c;   // for undirected graph
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj_matrix[i][k] != INT_MAX && adj_matrix[k][j] != INT_MAX)
                {
                    if (adj_matrix[i][k] + adj_matrix[k][j] < adj_matrix[i][j])
                    {
                        adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                    }
                }
            }
        }
    }

    // print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_matrix[i][j] == INT_MAX)
                cout << "@ ";
            else
                cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    // detect negative cycle
    for (int i = 0; i < n; i++)
    {
        if (adj_matrix[i][i] < 0)
        {
            cout << "Negative cycle detected!" << endl;
            break;
        }
    }

    return 0;
}