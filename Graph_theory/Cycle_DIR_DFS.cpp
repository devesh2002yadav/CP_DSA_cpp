#include<unordered_map>
#include<list>

bool checkDFSCycle(int node, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsvis, unordered_map<int, list<int>> &adj)
{
    vis[node]=1; dfsvis[node]=1;
    for(auto nbr:adj[node])
    {
        if(!vis[nbr])
        {
            bool cycleYes=checkDFSCycle(nbr, vis, dfsvis, adj);
            if(cycleYes) return true;
        }
        
        // here both vis and dfsvis are true
        else if(dfsvis[nbr])
        {
            return true;
        }
    }
    dfsvis[node]=0;
    return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int a=edges[i].first; int b=edges[i].second;
        adj[a].push_back(b);
    }
    unordered_map<int, bool> vis;
    unordered_map<int, bool> dfsvis;
    for(int i=1; i<n; i++)
    {
        if(!vis[i])
        {
            bool cycfind=checkDFSCycle(i, vis, dfsvis, adj);
            if(cycfind==1) return true;
        }
    }
    return false;
}