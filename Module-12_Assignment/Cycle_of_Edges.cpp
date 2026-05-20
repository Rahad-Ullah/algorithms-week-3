#include <bits/stdc++.h>
using namespace std;

int par[100005];
int group_size[100005];

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
    int cycleCounter = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leader_a = find(a);
        int leader_b = find(b);

        if (leader_a == leader_b)
            cycleCounter++;
        else
            dsu_union(a, b);
    }

    cout << cycleCounter << endl;

    return 0;
}