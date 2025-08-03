//ProblemLink: https://cses.fi/problemset/task/1679/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
vector<int> result;
bool visited[N], inStack[N];
bool hasCycle = false;

void dfs(int node)
{
    visited[node] = true;
    inStack[node] = true;

    for (int child : graph[node])
    {
        if (!visited[child])
        {
            dfs(child);
        }
        else if (inStack[child])
        {
            hasCycle = true;
        }
    }

    inStack[node] = false;
    result.push_back(node);
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2); 
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    if (hasCycle)
    {
        cout << "IMPOSSIBLE";
        cout << endl;
    }
    else
    {
        reverse(result.begin(), result.end());
        for (int x : result)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
