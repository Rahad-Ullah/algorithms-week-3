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
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));

    int n, e;
    cin >> n >> e;
    bool cycle = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leader_a = find(a);
        int leader_b = find(b);

        if (leader_a == leader_b)
            cycle = true;
        else
            dsu_union(a, b);
    }

    if (cycle)
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}