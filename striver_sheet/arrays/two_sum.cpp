// 1) brute force - run two for loops, check for sum pair

// 2) hashmap - 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        unordered_map<int, int> sum;
        for(int i=0; i<n; i++)
        {
            int one=nums[i];
            int find=target-one;
            if(sum.count(find)==1)
            {
                return {i, sum[find]};
            }
            else sum[one]=i;
        }
        return {};
    }
};