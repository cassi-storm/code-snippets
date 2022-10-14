#include <bits/stdc++.h>
using namespace std;

int bfs(int src, int sink, vector<vector<int>> &g, vector<vector<int>> &d, vector<int> &p)
{
    fill(p.begin(), p.end(), -1);
    queue<int> q;
    vector<int> f(sink + 1, 0);
    p[src] = 0;
    f[src] = (int)1e9 + 10;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == sink)
            break;
        for (auto i : g[node])
        {
            if (i != src && d[node][i] > 0 && p[i] == -1)
            {
                p[i] = node;
                f[i] = min(d[node][i], f[node]);
                q.push(i);
            }
        }
    }
    return p[sink] == -1 ? -1 : f[sink];
}

int get_max_flow(vector<vector<int>> &g, vector<vector<int>> &d)
{
    int n = g.size();
    int src = 0, sink = n - 1;
    int part_flow = 0, total_flow = 0;
    vector<int> p(n);
    while ((part_flow = bfs(src, sink, g, d, p)) != -1)
    {
        int node = sink, par;
        while (node != src)
        {
            par = p[node];
            d[par][node] -= part_flow;
            d[node][par] += part_flow;
            node = par;
        }
        total_flow += part_flow;
    }
    return total_flow;
}

int main()
{
    int n, e;
    int n1, n2, cp;
    cin >> n >> e;
    vector<vector<int>> d(n, vector<int>(n, 0));
    vector<vector<int>> g(n);
    for (int i = 0; i < e; ++i)
    {
        cin >> n1 >> n2 >> cp;
        --n1;
        --n2;
        d[n1][n2] = cp;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }
    int flow = get_max_flow(g, d);
    cout << flow << endl;
}
