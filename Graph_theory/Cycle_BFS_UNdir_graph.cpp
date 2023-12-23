#include<unordered_map>
#include<list>
#include<queue>


bool isCycleBFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, int src)
{
    unordered_map<int, int> parent;
    parent[src]=-1; vis[src]=1;
    queue<int> q;
    q.push(src); 
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto nbr:adj[front])
        {
            if(vis[nbr]==1&&nbr!=parent[front])
            {
                return true;
            }
            else if(!vis[nbr])
            {
                q.push(nbr);
                vis[nbr]=1;
                parent[nbr]=front;
            }
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
            bool ans=isCycleBFS(adj, vis, i);
            if(ans==1) return "Yes";
        }
    }
    return "No";
}