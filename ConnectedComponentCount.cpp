// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 6;
vector<int> graph[N];
bool visted[N];
void dfs(int vertex)
{
    visted[vertex] = true;
    for (int child : graph[vertex])
    {
        if (!visted[child])
            dfs(child);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visted[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}