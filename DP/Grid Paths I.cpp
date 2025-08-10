#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<char>> grid;
vector<vector<int>> dp;

int dx[] = {1, 0};
int dy[] = {0, 1};

int solve(int i, int j)
{

    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '*')
        return 0;

    if (i == grid.size() - 1 && j == grid[0].size() - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    for (int k = 0; k < 2; k++)
    {
        int di = i + dx[k];
        int dj = j + dy[k];

        ans = (ans + solve(di, dj)) % MOD;
    }

    return dp[i][j] = ans;
}

int main()
{
    int n;
    cin >> n;

    grid.resize(n, vector<char>(n));
    dp.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = solve(0, 0);
    cout << result << endl;

    return 0;
}