class Solution {
    public:
    void sol(int s,int k,int n,vector<int> &an,vector<vector<int>> &ans)
    {
        if(k<=0)
        {
            if(n==0) ans.push_back(an);
            return;
        }
        
        for(int i=s;i<=9;i++)    
        {
            an.push_back(i);
            sol(i+1,k-1,n-i,an,ans);
            an.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        int mn=(k*(k+1))/2;
        int mx=45-((9-k)*(9-k+1))/2;
        vector<int> an;
        sol(1,k,n,an,ans);
        return ans;
    }
};