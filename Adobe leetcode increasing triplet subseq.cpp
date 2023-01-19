class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        int a=pow(2, 31)-1;
        int b=pow(2, 31)-1;
        int mn=nums[0];
        for(int i=0; i<n; i++)
        {
            if(nums[i]>b) return true;
            if(nums[i]>a) b=min(nums[i], b);
            a=min(nums[i], a);
        } 
        return false;
    }
};
