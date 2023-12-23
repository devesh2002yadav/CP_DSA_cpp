class Solution {
public:
    string customSortString(string order, string s) 
    {
        string st="";
        for(int i=0; i<order.size(); i++)
        {
            for(int j=0; j<s.size(); j++)
            {
                if(order[i]==s[j])
                {
                    st+=order[i];
                }
            }
        }
        map<char, int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        for(auto x:mp)
        {
            int k=0;
            for(int j=0; j<st.size(); j++)
            {
                if(x.first==st[j])
                {
                    k++;
                }
            }
            if(k==0)
            {
                if(x.second>0)
                {
                    while(x.second>0)
                    {
                        st+=x.first;
                        x.second--;
                    }
                }
            }
        }
        return st;
    }
};