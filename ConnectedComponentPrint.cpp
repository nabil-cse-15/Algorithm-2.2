#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 6;
vector<int> graph[N];
vector<vector<int>> cc;
vector<int> current_cc;
bool visted[N];
void dfs(int vertex)
{
    current_cc.push_back(vertex);
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

    for (int i = 1; i <= n; i++)
    {
        if (!visted[i])
        {
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
        }
    }
    cout << cc.size() << endl; // count connected component
    for (auto c_cc : cc)
    {
        for (int vertex : c_cc)
        {
            cout << vertex << " "; // print connected component
        }
        cout << endl;
    }
}