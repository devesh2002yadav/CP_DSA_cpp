class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> ans;
        vector<int> dp(n,1);
        sort(nums.begin(), nums.end());
        int flag=-1;
        int mx=1;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if((nums[i]%nums[j])==0&&dp[i]<(dp[j]+1))
                {
                    dp[i]=dp[j]+1;
                    mx=max(mx, dp[i]);
                }
            }
        }
        for(int i=n-1; i>=0; i--)
        {
            if(mx==dp[i]&&(flag==-1||(flag%nums[i])==0))
            {
                ans.push_back(nums[i]);
                mx--;
                flag=nums[i];
            }
        }
        return ans;
    }
};