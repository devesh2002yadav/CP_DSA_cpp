#include<queue>
#include<list>
#include<unordered_map>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int a=edges[i].first-1;
        int b=edges[i].second-1;
        adj[a].push_back(b);
    }
    vector<int> indeg(n);
    for(auto i:adj)
    {
        for(auto j:i.second)
        {
            indeg[j]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(indeg[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        cnt++;
        for(auto nbr:adj[front])
        {
            indeg[nbr]--;
            if(indeg[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }
    if(cnt==n) return false;
    else return true;
}