#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent; // To store parent cell for path reconstruction
vector<vector<char>> move_dir;         // To store the direction taken to reach each cell
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char directions[] = {'R', 'L', 'D', 'U'};

bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m &&
            (grid[x][y] == '.' || grid[x][y] == 'B') && !visited[x][y]);
}

string reconstructPath(pair<int, int> end, pair<int, int> start)
{
    string path;
    pair<int, int> curr = end;
    while (curr != start)
    {
        char dir = move_dir[curr.first][curr.second];
        path += dir;
        int px = parent[curr.first][curr.second].first;
        int py = parent[curr.first][curr.second].second;
        curr = {px, py};
    }
    reverse(path.begin(), path.end());
    return path;
}

string bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (isValid(nx, ny))
            {
                visited[nx][ny] = true;
                parent[nx][ny] = {cx, cy};
                move_dir[nx][ny] = directions[i];

                if (grid[nx][ny] == 'B')
                {
                    return reconstructPath({nx, ny}, {x, y});
                }

                q.push({nx, ny});
            }
        }
    }
    return "";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m));
    move_dir.assign(n, vector<char>(m));

    pair<int, int> start;
    bool found = false;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = {i, j};
                found = true;
            }
        }
    }

    if (!found)
    {
        cout << "NO\n";
        return 0;
    }

    string result = bfs(start.first, start.second);
    if (!result.empty())
    {
        cout << "YES\n"
             << result.size() << "\n"
             << result << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
