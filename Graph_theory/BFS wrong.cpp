#include<unordered_map>
#include<set>
#include<queue>


void Adj_list(unordered_map<int, set<int>> &adjlist, vector<pair<int, int>> &edges)
{
    for(int i=0; i<edges.size(); i++)
    {
        int a=edges[i].first; int b=edges[i].second;
        adjlist[a].insert(b); adjlist[b].insert(a);
    }
}

void bfs(unordered_map<int, set<int>> &adjlist, unordered_map<int, bool> vis, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node); vis[node]=1;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto x:adjlist[front])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
        unordered_map<int, set<int>> adjlist;
        vector<int> ans; 
        unordered_map<int, bool> vis;
        Adj_list(adjlist, edges);
        for(int i=0; i<vertex; i++)
        {
            if(!vis[i]){
                bfs(adjlist, vis, ans, i);
            }
        }
        return ans;
}