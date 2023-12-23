#include<unordered_map>
#include<list>
#include<limits.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<m; i++)
    {
        int a=g[i].first.first;
        int b=g[i].first.second;
        int w=g[i].second;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    vector<int> key(n+1);
    vector<int> par(n+1);
    vector<bool> mst(n+1);
    
    for(int i=0; i<=n; i++)
    {
        key[i]=INT_MAX;
        par[i]=-1;
        mst[i]=0;
    }
    key[1]=0; par[1]=-1;
    for(int i=1; i<n; i++)
    {
        int mini=INT_MAX; 
        int u;
        for(int v=1; v<=n; v++)
        {
            if(mst[v]==0&&key[v]<mini)
            {
                mini=key[v];
                u=v;
            }
        }
        mst[u]=1;
        for(auto it:adj[u])
        {
            int v=it.first;
            int w=it.second;
            if(mst[v]==0&&w<key[v])
            {
                par[v]=u;
                key[v]=w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> res;
    for(int i=2; i<=n; i++)
    {
        res.push_back({{par[i], i}, key[i]});
    }
    return res;
}
