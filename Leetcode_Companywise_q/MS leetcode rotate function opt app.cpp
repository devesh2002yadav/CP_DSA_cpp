class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            ans+=nums[i]*i;
            sum+=nums[i];
        }
        int val=ans;
        for(int i=0; i<n; i++)
        {
            int nw=ans+sum-nums[n-1-i]*(n);
            val=max(val, nw);
            ans=nw;
        }
        return val;
    }
};