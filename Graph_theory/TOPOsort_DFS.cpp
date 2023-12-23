#include<stack>
#include<list>
#include<unordered_map>

void TPS(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &s)
{
    vis[node]=1;
    for(auto nbr:adj[node])
    {
        if(!vis[nbr])
        {
            TPS(nbr, adj, vis, s);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   // unordered_map<int, list<int>> adj;
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
    }
    vector<int> vis(v);
    stack<int> s;
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            TPS(i, adj, vis, s);
        }
    }
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}