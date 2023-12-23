#include<algorithm>

bool cmpr(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeSet(vector<int> &par, vector<int> &rank, int n)
{
    for(int i=0; i<n; i++)
    {
        par[i]=i;
        rank[i]=0;
    }
}

int findPar(vector<int> &par, int node)
{
    if(par[node]==node)
    {
        return node;
    }
    return par[node]=findPar(par, par[node]);
}

int unionSet(int a, int b, vector<int> &par, vector<int> &rank)
{
    a=findPar(par, a);
    b=findPar(par, b);
    if(rank[a]<rank[b])
    {
        par[a]=b;
    }
    if(rank[a]>rank[b])
    {
        par[b]=a;
    }
    else
    {
        par[a]=b;
        rank[b]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(), edges.end(), cmpr);
    vector<int> par(n); 
    vector<int> rank(n);
    makeSet(par, rank, n);
    int minW=0;
    for(int i=0; i<edges.size(); i++)
    {
        int a=findPar(par, edges[i][0]);
        int b=findPar(par, edges[i][1]);
        int w=edges[i][2];
        if(a!=b)
        {
            minW+=w;
            unionSet(a, b, par, rank);
        }
    }
    return minW;
}