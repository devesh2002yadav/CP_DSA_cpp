class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int n=secret.length();
        string s1="";
        string s2="";
        int bulls=0;
        int cows=0;
        for(int i=0; i<n; i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(secret[i]==guess[i])
            {
                continue;
            }
            else if(secret[i]!=guess[i])
            {
                s1+=secret[i];
                s2+=guess[i];
            }
        }
        int nw=s1.size();
        set<char> ds;
        for(int i=0; i<nw; i++)
        {
            char ch=s1[i];
            ds.insert(ch);
        }
        for(int i=0; i<ds.size(); i++)
        {
            auto it = ds.begin();
            advance(it,i);
            int fi=0;
            int se=0;
            for(int j=0; j<nw; j++)
            {
                if(*it==s1[j])
                {
                    fi++;
                }
                if(*it==s2[j])
                {
                    se++;
                }
            }
            cows=cows+min(fi, se);
        }
        string one=to_string(bulls);
        one+='A';
        string two=to_string(cows);
        two+='B';
        string ans=one+two;
        return ans;
    }
};