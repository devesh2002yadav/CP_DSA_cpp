class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=-1*INT_MAX;
        int temp=0;
        for(int i=0; i<n; i++)
        {
            vector<int> star;
            int sum=0;
             for(int j=temp; j<n; j++)
             {
                 star.push_back(nums[j]);
             }
             for(int j=0; j<temp; j++)
             {
                 star.push_back(nums[j]);
             }
             for(int j=0; j<n; j++)
             {
                 sum+=star[j]*j;
             }
             temp++;
             ans=max(ans, sum);
        }
        return ans;
    }
};