#include<unordered_map>
#include<list>

// dfs to check cycle in directed graph ...

class Solution {
public:
    
bool canFinish(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++)
        {
            int a=edges[i][0]; int b=edges[i][1];
            adj[a].push_back(b);
        }
        unordered_map<int, bool> vis;
        unordered_map<int, bool> dfsvis;
        for(int i=1; i<n; i++)
        {
            if(!vis[i])
            {
                bool cycfind=checkDFSCycle(i, vis, dfsvis, adj);
                if(cycfind==1) return false;
            }
        }
        return true;
    }

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
        
        // here both vis and dfsvis are true ...
        else if(dfsvis[nbr])
        {
            return true;
        }
    }
    dfsvis[node]=0;
    return false;
}

};
