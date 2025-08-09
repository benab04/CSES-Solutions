#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> component;
int num_components = 0;

void dfs(int city)
{
    component[num_components - 1].push_back(city + 1);
    visited[city] = true;
    for (int neighbor : adj[city])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    visited.assign(n, false);

    for (int i = 0; i < m; i++)
    {
        int city1, city2;
        cin >> city1 >> city2;
        city1--;
        city2--;
        adj[city1].push_back(city2);
        adj[city2].push_back(city1);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ++num_components;
            component.push_back(vector<int>());
            dfs(i);
        }
    }

    cout << num_components - 1 << "\n";
    for (int i = 0; i < num_components - 1; i++)
    {
        cout << component[i][0] << " " << component[i + 1][0] << "\n";
    }

    return 0;
}