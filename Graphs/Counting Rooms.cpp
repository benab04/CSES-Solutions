#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<bool>> visited;
vector<vector<char>> grid;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y])
    {
        return true;
    }
    return false;
}

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int x_new = x + dx[i];
        int y_new = y + dy[i];

        if (isValid(x_new, y_new))
        {
            visited[x_new][y_new] = true;
            dfs(x_new, y_new);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();

    cin >> n >> m;

    visited.assign(n, vector<bool>(m, false));
    grid.assign(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                ++rooms;
                dfs(i, j);
            }
        }
    }
    cout << rooms << "\n";
    return 0;
}