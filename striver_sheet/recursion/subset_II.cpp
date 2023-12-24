class Solution {
private:
    void subset(int index, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
    {
        ans.push_back(temp);
        for(int i=index; i<nums.size(); i++)
        {
            if(i!=index&&nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            subset(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
       sort(nums.begin(), nums.end());
       vector<int> temp;
       vector<vector<int>> ans;
       subset(0, nums, temp, ans);
       return ans; 
    }
};

