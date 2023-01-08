class Solution {
public:
    int maxPoints(vector<vector<int>>& p) 
    {
        int n=p.size();
        int val=1;
        for(int i=0; i<n-1; i++)
        {
            int cnt=1;
            map<float, int> dm;
            for(int j=i+1; j<n; j++)
            {
                float slope=(float)(p[i][1]-p[j][1])/(float)(p[i][0]-p[j][0]);
                if((p[i][1]-p[j][1]<0)&&(p[i][0]-p[j][0]==0))
                {
                    dm[abs(slope)]++;
                }
                else dm[slope]++;
            }
            for(auto x:dm)
            {
                cnt=max(cnt, x.second+1);
            }
            val=max(cnt, val);
        }
        return val;
    }
};