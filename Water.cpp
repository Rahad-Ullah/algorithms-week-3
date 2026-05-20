#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        int max1_idx = -1, max2_idx = -1;
        int max1_val = -1, max2_val = -1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] > max1_val)
            {
                max2_val = max1_val;
                max2_idx = max1_idx;

                max1_val = a[i];
                max1_idx = i;
            }
            else if (a[i] > max2_val)
            {
                max2_val = a[i];
                max2_idx = i;
            }
        }

        int left_idx = min(max1_idx, max2_idx);
        int right_idx = max(max1_idx, max2_idx);

        cout << left_idx << " " << right_idx << endl;
    }

    return 0;
}