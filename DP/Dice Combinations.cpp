#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
const int MOD = 1000000007;

long long solve(long n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    long long ans = 0;

    for (int i = 1; i <= 6; i++)
    {
        ans = (ans + solve(n - i)) % MOD;
    }

    dp[n] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n;
    cin >> n;

    dp.resize(n + 1, -1);

    long long result = solve(n);
    cout << result << endl;

    return 0;
}