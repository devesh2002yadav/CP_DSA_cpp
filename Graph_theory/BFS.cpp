#include<bits/stdc++.h>
using namespace std;
#include <unordered_map>
#include <map>
#include <queue>
#include <set>


void makeAdjList(unordered_map<int, set<int>>&value, vector<pair<int, int>>&edges )
{
        for(int i=0; i<edges.size(); i++){
            int a=edges[i].first; int b=edges[i].second;
            value[a].insert(b); value[b].insert(a);
        }
}

void BFS(unordered_map<int, set<int>>&value, map<int, bool> vis, vector<int>& ans, int node)
         {
            queue<int> q;
            q.push(node);
            vis[node]=1;
            while(!q.empty())
            {
                int front = q.front(); q.pop();
                ans.push_back(front);
                for(auto i:value[front])
                {
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }
         }      

int main() 
{
    int n; cin>>n; int m; cin>>m;
    vector<pair<int, int>> edges;
    for(int i=0 ; i<m; i++)
    {
        int a; int b;
        cin>>a;
        cin>>b;
        edges.push_back(make_pair(a,b));
    }
    unordered_map<int, set<int>> value;
    vector<int> ans;
    map<int, bool> vis;
    makeAdjList(value, edges);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            BFS(value, vis, ans, i);
        }
    } 
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}