#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> coins;
vector<ll> dp;
int n;

const int MOD = 1e9 + 7;

long solve(int x)
{

    for (int coin : coins)
    {
        for (int i = 1; i <= x; i++)
        {
            if (i - coin >= 0)
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;

    cin >> n >> x;

    coins.resize(n);
    dp.resize(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    dp[0] = 1;

    ll result = solve(x);

    cout << result << endl;

    return 0;
}