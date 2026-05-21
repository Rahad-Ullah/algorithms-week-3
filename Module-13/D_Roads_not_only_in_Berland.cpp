#include <bits/stdc++.h>
using namespace std;

int par[1005];
int group_size[1005];

int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int a, int b)
{
    int leader_a = find(a);
    int leader_b = find(b);

    if (leader_a == leader_b)
        return;

    if (group_size[leader_a] >= group_size[leader_b])
    {
        par[leader_b] = leader_a;
        group_size[leader_a] += group_size[leader_b];
    }
    else
    {
        par[leader_a] = leader_b;
        group_size[leader_b] += group_size[leader_a];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    vector<pair<int, int>> rmv;
    vector<pair<int, int>> create;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        int leader_a = find(a);
        int leader_b = find(b);

        if (leader_a == leader_b)
        {
            rmv.push_back({a, b});
        }
        else
        {
            dsu_union(a, b);
        }
    }

    for (int j = 2; j <= n; j++)
    {
        int leader_1 = find(1);
        int leader_2 = find(j);
        if (leader_1 != leader_2)
        {
            create.push_back({1, j});
            dsu_union(1, j);
        }
    }

    cout << rmv.size() << "\n";
    for (int i = 0; i < rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << "\n";
    }

    return 0;
}