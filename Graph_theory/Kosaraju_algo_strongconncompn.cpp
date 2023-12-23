#include<stack>
#include<unordered_map>
#include<list>

void revdfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &trans)
{
    vis[node]=1;
    for(auto nbr:trans[node])
    {
        if(!vis[nbr])
        {
            revdfs(nbr, vis, trans);
        }
    }
}

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    vis[node]=1;
    for(auto nbr:adj[node])
    {
        if(!vis[nbr])
        {
            dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
         int a=edges[i][0];
         int b=edges[i][1];
         adj[a].push_back(b);
    }
    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    
    unordered_map<int, list<int>> trans;
    for(int i=0; i<v; i++)
    {
        vis[i]=0;
        for(auto nbr: adj[i])
        {
            trans[nbr].push_back(i);
        }
    }
    int cnt=0;
    while(!st.empty())
    {
        int top=st.top();
        st.pop();
        if(!vis[top])
        {
            cnt++;
            revdfs(top, vis, trans);
        }
    }
    return cnt;
}