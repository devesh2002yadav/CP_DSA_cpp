class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        if(n==0) return 0;
        int len=1;
        int ans=1;
        for(int i=1; i<n; i++)
        {
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==nums[i-1]+1)
            {
                len++;
            }
            else len=1;
            ans=max(len, ans);
        }
        return ans;
    }
};