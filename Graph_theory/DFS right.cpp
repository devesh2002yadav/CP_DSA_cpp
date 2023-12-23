#include<unordered_map>
#include<set>
#include<queue>
#include<list>


void dfs(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &vis, int node, vector<int> &components)
{
    components.push_back(node);
    vis[node]=1;
    for(auto x:adjlist[node]){
        if(!vis[x])
        {
            dfs(adjlist, vis, x, components);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjlist;
    for(int i=0; i<E; i++)
    {
        int a=edges[i][0]; int b=edges[i][1];
        adjlist[a].push_back(b); adjlist[b].push_back(a);
    }
    vector<vector<int>> ans;
    unordered_map<int, bool> vis;
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            vector<int> components;
            dfs(adjlist, vis, i , components);
            ans.push_back(components);
        }
    }
    return ans;
}