#include<bits/stdc++.h>
using namespace std;
#define unordered_map
template <typename T>

class graph
{
    public:
         map<T, list<T>> adj;
         void addEdge(T a, T b, bool dir)
         {
            adj[a].push_back(b);
            if(dir==0)
            {
                adj[b].push_back(a);
            }
         }
         void printADJLIST()
         {
            for(auto x:adj)
            {
                cout<<x.first<<"-------->";
                for(auto y:x.second)
                {
                    cout<<y<<" ";
                }
                cout<<endl;
            }
         }
};

int main() 
{
    int n; cin>>n;
    int m; cin>>m;
    graph<int> dev;
    for(int i=0; i<n; i++)
    {
        int a; int b;
        cin>>a; cin>>b;
        dev.addEdge(a,b,0);
    }
    dev.printADJLIST();
    return 0;
}