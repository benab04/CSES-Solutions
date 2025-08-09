#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> team;

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    team[node] = 1;
    visited[node] = true;
    while (!q.empty())
    {

        int current = q.front();

        q.pop();
        for (int neighbor : adj[current])
        {
            if (team[neighbor] != 0 && team[neighbor] == team[current])
            {
                cout << "IMPOSSIBLE" << endl;
                exit(0);
            }
            if (!visited[neighbor] && team[neighbor] == 0)
            {

                visited[neighbor] = true;
                q.push(neighbor);
                team[neighbor] = team[current] * -1;
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1, vector<int>());
    visited.resize(n + 1, false);
    team.resize(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (team[i] == 1)
        {
            cout << "1 ";
        }
        else
        {
            cout << "2 ";
        }
    }
    return 0;
}