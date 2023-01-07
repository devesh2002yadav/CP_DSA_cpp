class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {
        int x1=p1[0];
        int y1=p1[1];
        int x2=p2[0];
        int y2=p2[1];
        int x3=p3[0];
        int y3=p3[1];
        int x4=p4[0];
        int y4=p4[1];
        int d1=abs((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        int d2=abs((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        int d3=abs((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4));
        int d4=abs((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        int d5=abs((x4-x2)*(x4-x2)+(y4-y2)*(y4-y2));
        int d6=abs((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4));
        set<int> ds;
        ds.insert(d1);
        ds.insert(d2);
        ds.insert(d3);
        ds.insert(d4);
        ds.insert(d5);
        ds.insert(d6);
        int k=ds.size();
        if(k!=2) return false;
        else
        {
            vector<int> dv;
            for(auto it=ds.begin(); it!=ds.end(); it++)
            {
                dv.push_back(*it);
            }
            int a=dv[0];
            int b=dv[1];
            if(b==2*a) return true;
        }
        return false;
    }
};