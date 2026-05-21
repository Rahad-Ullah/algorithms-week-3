#include <bits/stdc++.h>
using namespace std;

int dp[100005];

bool can_reach(int n)
{
    if (n == 1)
        return true;
    if (n < 1)
        return false;

    if (dp[n] != -1)
        return dp[n];

    bool opt1 = false;
    bool opt2 = false;

    if (n % 2 == 0)
    {
        opt1 = can_reach(n / 2);
    }

    opt2 = can_reach(n - 3);

    return dp[n] = opt1 || opt2;
}

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            cin >> n;

            for (int i = 0; i <= n; i++)
                dp[i] = -1;

            if (can_reach(n))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}