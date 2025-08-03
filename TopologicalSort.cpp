#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];
vector<int> result;
void dfs(int source)
{
    visited[source] = true;
    for (int child : g[source])
    {
        if (visited[child] == false)
            dfs(child);
    }
    result.push_back(source);
}

int main()
{
    int node, edges;
    cin >> node >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
    }
    for (int i = 1; i <= node; i++)
    {
        if (visited[i] == false)
            dfs(i);
    }
    reverse(result.begin(), result.end());
    for (int i = 0; i <result.size(); i++)
    {
        cout << result[i] << " ";
    }
}





