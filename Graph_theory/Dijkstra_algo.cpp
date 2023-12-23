#include<unordered_map>
#include<list>
#include<set>
#include<vector>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) 
{
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<edges; i++)
    {
        int a=vec[i][0];
        int b=vec[i][1];
        int c=vec[i][2];
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++)
    {
        dist[i]=INT_MAX;
    }
    set<pair<int, int>> st;
    dist[source]=0;
    st.insert(make_pair(0, source));
    while(!st.empty())
    {
        auto top=*(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;
        st.erase(st.begin());
        for(auto nbr:adj[topNode])
        {
            if(nodeDist+nbr.second<dist[nbr.first])
            {
                auto record=st.find(make_pair(dist[nbr.first], nbr.first));
                if(record!=st.end())
                {
                    st.erase(record);
                }
                dist[nbr.first]=nodeDist+nbr.second;
                st.insert(make_pair(dist[nbr.first], nbr.first));
            }
        }
    }
    return dist;
}