class Solution {
public:
    void part(int index, string &s, vector<string> &ds, vector<vector<string>> &ans)
    {
        if(index==s.length())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<s.length(); i++)
        {
            if(palindrome(s, index, i))
            {
                ds.push_back(s.substr(index, i-index+1));
                part(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    bool palindrome(string s, int st, int end)
    {
        while(st<end)
        {
            if(s[st]!=s[end])
            {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> ds;
        part(0, s, ds, ans);
        return ans;
    }
};