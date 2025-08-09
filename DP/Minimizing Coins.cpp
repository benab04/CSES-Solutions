#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<long long> dp;

int solve(int x, int n)
{
    if (x < 0)
        return -1;
    // if (x < *(min_element(coins.begin(), coins.end())))
    //     return -1;
    if (x == 0)
        return 0;
    if (dp[x] != -2)
        return dp[x];

    long long ans = LONG_MAX;

    for (int i = 0; i < n; i++)
    {
        if (x < coins[i])
        {
            continue;
        }
        long long val = solve(x - coins[i], n);
        if (val != -1)
        {
            ans = min(ans, val + 1);
        }
    }

    if (ans == LONG_MAX)
    {
        dp[x] = -1;
        return -1;
    }

    dp[x] = ans;
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    coins.resize(n);
    dp.resize(x + 1, -2);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    long long result = solve(x, n);

    cout << result << endl;

    return 0;
}