#include <bits/stdc++.h>
using namespace std;

// DP Approach
int solve_dp(int n)
{
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp > 0)
        {
            if (temp % 10 == 0)
            {
                temp /= 10;
                continue;
            }

            dp[i] = min(dp[i], dp[i - (temp % 10)] + 1);
            temp /= 10;
        }
    }
    return dp[n];
}

// Greedy Approach
int solve_greedy(int n)
{
    vector<int> digits;

    int ans = 0;
    int n1;
    while (n > 0)
    {

        ++ans;
        n1 = n;
        while (n1 != 0)
        {
            int digit = n1 % 10;
            digits.push_back(digit);
            n1 /= 10;
        }

        int max_digit = *max_element(digits.begin(), digits.end());
        n = n - max_digit;
        digits.clear();
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int result = solve_dp(n);

    cout << result << endl;

    return 0;
}