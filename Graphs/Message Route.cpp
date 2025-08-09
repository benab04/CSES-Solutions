#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;

void reconstructAndPrintPath(int end, int start)
{
    int curr = end;
    vector<int> path;

    while (curr != start)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (int node : path)
    {
        cout << node << " ";
    }

    return;
}

bool bfs(int start, int end)
{
    int steps = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == end)
        {
            return true;
        }

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                parent[neighbor] = node;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;
    adj.resize(n + 1, vector<int>());
    visited.resize(n + 1, false);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool found = bfs(1, n);

    if (found == false)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    reconstructAndPrintPath(n, 1);
}