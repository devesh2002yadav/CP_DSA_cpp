class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) 
    {
        int n=rectangles.size();
        bool bo=false;
        map<pair<int, int>, int> cnt;
        for(auto x:rectangles)
        {
            cnt[{x[0], x[1]}]++;
            cnt[{x[0], x[3]}]--;
            cnt[{x[2], x[3]}]++;
            cnt[{x[2], x[1]}]--;
        }
        int plus=0;
        int minus=0;
        for(auto itr=cnt.begin(); itr!=cnt.end(); itr++)
        {
            if(itr->second!=0)
            {
                if(itr->second==1)
                {
                    plus++;
                }
                else if(itr->second==-1)
                {
                    minus++;
                }
                else if(abs(itr->second)!=1)
                {
                    return false;
                }
            }
        }
        if(plus==2&&minus==2) bo=true;
        return bo;
    }
};