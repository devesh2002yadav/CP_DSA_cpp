class Solution 
{
public:
    int numberOfBoomerangs(vector<vector<int>>& p) 
    {
        int ans=0;
        int n=p.size();
        if(n<3) return 0;
        for(int i=0; i<n; i++)
        {
            map<int, int> dm;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                   int d=(p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
                   dm[d]++;
                }
            }
        for(auto x:dm)
        {
            if(x.second>1)
            {
                ans+=(x.second)*(x.second-1);
            }
        }
        }
        return ans;
    }
};