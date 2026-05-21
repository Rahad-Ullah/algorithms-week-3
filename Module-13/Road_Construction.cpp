#include <bits/stdc++.h>
using namespace std;

int par[100005];
int group_size[100005];
int cmp, mx;

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
        mx = max(mx, group_size[leader_a]);
    }
    else
    {
        par[leader_a] = leader_b;
        group_size[leader_b] += group_size[leader_a];
        mx = max(mx, group_size[leader_b]);
    }

    cmp--;
}

int main()
{
    int n, e;
    cin >> n >> e;
    cmp = n;
    mx = 1;

    for (int i = 0; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << mx << endl;
    }

    return 0;
}