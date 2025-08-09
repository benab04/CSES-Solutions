#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e6;

vector<int> children[MAX];
int subtree_size[MAX];

void dfs(int node)
{
    subtree_size[node] = 1;

    for (int child : children[node])
    {
        dfs(child);
        subtree_size[node] += subtree_size[child];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int parent;
        cin >> parent;

        children[parent].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << subtree_size[i] - 1 << " ";
    }

    return 0;
}