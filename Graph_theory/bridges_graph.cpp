#include<unordered_map>
#include<list>

void dfs(int node, int par, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &res, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node]=true; 
    disc[node]=low[node]=timer++;
    for(auto nbr:adj[node])
    {
        if(nbr==par)
        {
            continue;
        }
        if(!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, res, adj, vis);
            low[node]=min(low[node], low[nbr]);
            if(low[nbr]>disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                res.push_back(ans);
            }
        }
        else
        {
            // back edge case
            low[node]=min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) 
{
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int timer=0; 
    vector<int> disc(v);
    vector<int> low(v);
    int par=-1;
    unordered_map<int, bool> vis;
    for(int i=0; i<v; i++){
        disc[i]=-1; low[i]=-1;
    }
    vector<vector<int>> res;
    for(int i=0; i<v; i++)
    {
     if(!vis[i])
     {
         dfs(i, par, timer, disc, low, res, adj, vis);
     }
    }
    return res;
}