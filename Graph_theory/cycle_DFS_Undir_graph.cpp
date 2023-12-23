#include<unordered_map>
#include<list>
#include<queue>


bool isCycleDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, int node, int parent)
{
    vis[node]=1;
        for(auto nbr:adj[node])
        {
            if(!vis[nbr])
            {
                bool check=isCycleDFS(adj, vis, nbr, node);
                if(check) return true;
            }
            else if(nbr!=parent)
            {
                return true;
            }
        }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    for(int i=0; i<m; i++){
        int a=edges[i][0]; int b=edges[i][1];
        adj[a].push_back(b); adj[b].push_back(a); 
    }
    unordered_map<int, bool> vis;
    for(int i=0; i<n; i++){
        if(!vis[i])
        {
            bool ans=isCycleDFS(adj, vis, i, -1);
            if(ans==1) return "Yes";
        }
    }
    return "No";
}
