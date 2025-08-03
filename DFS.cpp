#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> g[N];
bool visited[N];
vector<int>result;
void dfs(int vertex)
{
    //cout << vertex << endl;
    visited[vertex] = true;
    result.push_back(vertex);
    for (int child : g[vertex])
    {
       // cout << "Par " << vertex << " child " << child << endl;
        if (visited[child] == false)
            dfs(child);
    }
}
int main()
{
    int n, m,r;
    cin >> n >> m>>r;
    bool visited[n];
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(r);
    for(int i=0;i<result.size();i++)
    {
cout<<result[i]<<" ";
    }
    
}
