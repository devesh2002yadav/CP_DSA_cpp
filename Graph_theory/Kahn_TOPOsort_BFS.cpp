#include<queue>
#include<list>
#include<unordered_map>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   // unordered_map<int, list<int>> adj;
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
    }
    vector<int> indeg(v);
    for(auto i:adj)
    {
        for(auto j:i)
        {
            indeg[j]++;
        }
    }
    queue<int> q;
    for(int i=0; i<v; i++)
    {
        if(indeg[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto nbr:adj[front])
        {
            indeg[nbr]--;
            if(indeg[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }
    return ans;
}