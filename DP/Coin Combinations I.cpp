#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<int> dp;

const int MOD = 1000000007;

int solve(int x, int n)
{
    if (x < 0)
        return 0;
    if (x == 0)
        return 1;
    if (dp[x] != -2)
        return dp[x];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (x < coins[i])
            continue;
        ans = (ans + solve(x - coins[i], n)) % MOD;
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

    int result = solve(x, n);

    cout << result << endl;

    return 0;
}