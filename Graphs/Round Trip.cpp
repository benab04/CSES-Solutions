#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;

int sp = 0, ep;

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (sp != 0)
        {
            // cout << "Cycle already found, skipping further exploration from " << u << endl;
            return;
        }
        // cout << "Visiting edge from " << u << " to " << v << endl;
        if (parent[u] == v)
        {
            // cout << "Skipping back edge from " << u << " to " << v << endl;
            continue;
        }
        if (!vis[v])
        {
            vis[v] = true;
            parent[v] = u;
            dfs(v);
        }
        else
        {
            // cout << v << " is already visited" << endl;
            sp = v;
            ep = u;
            return;
        }
    }
    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1, false);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (sp != 0)
        {
            break;
        }
        if (!vis[i])
        {
            sp = 0;
            vis[i] = true;
            parent[i] = -1;
            dfs(i);
        }
    }

    if (sp == 0)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        vector<int> cycle;

        cycle.push_back(sp);

        while (ep != sp && ep != -1)
        {
            cycle.push_back(ep);
            ep = parent[ep];
        }
        cycle.push_back(sp);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for (int i = 0; i < cycle.size(); i++)
        {
            cout << cycle[i] << " ";
        }
    }
    return 0;
}