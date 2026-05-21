#include <bits/stdc++.h>
using namespace std;

int dp[50];

int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibo(n - 1) + fibo(n - 2) + fibo(n - 3) + fibo(n - 4);
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    cout << fibo(n) << endl;

    return 0;
}