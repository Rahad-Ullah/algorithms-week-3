#include <bits/stdc++.h>
using namespace std;

const long long INF = LONG_LONG_MAX;

class Edge
{
public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
long long dis[1005];

void bellman_ford(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edge_list)
        {
            int a = edge.a;
            int b = edge.b;
            long long c = edge.c;
            if (dis[a] != LONG_LONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    int s;
    cin >> s;
    dis[s] = 0;

    bellman_ford(n);

    bool has_negative_cycle = false;
    for (auto edge : edge_list)
    {
        int a = edge.a;
        int b = edge.b;
        long long c = edge.c;

        if (dis[a] != INF && dis[a] + c < dis[b])
        {
            has_negative_cycle = true;
            break;
        }
    }

    int t;
    cin >> t;
    vector<int> queries(t);
    for (int i = 0; i < t; i++)
    {
        cin >> queries[i];
    }

    if (has_negative_cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        for (int i = 0; i < t; i++)
        {
            int q = queries[i];
            if (dis[q] == INF)
                cout << "Not Possible" << endl;
            else
                cout << dis[q] << endl;
        }
    }

    return 0;
}