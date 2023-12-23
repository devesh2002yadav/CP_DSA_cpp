#include<unordered_map>
#include<queue>
#include<list>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t)
{                 
    unordered_map<int, list<int>> adj;
    for(int i=0; i<m; i++)
    {
        int a=edges[i].first;
        int b=edges[i].second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    parent[s]=-1;
    vis[s]=1;
    
    
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto i:adj[front])
        {
            if(!vis[i])
            {
                vis[i]=1;
                parent[i]=front;
                q.push(i);
            }
        }
    }
    vector<int> ans;
    int currentnode=t;
    ans.push_back(t);
    while(currentnode!=s)
    {
        currentnode=parent[currentnode];
        ans.push_back(currentnode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}