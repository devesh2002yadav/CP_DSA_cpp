class Solution {
public:
    void comb(int index, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &ans)
    {
        if(index==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index]<=target)
        {
            ds.push_back(candidates[index]);
            comb(index, candidates, target-candidates[index], ds, ans);
            ds.pop_back();
        }
        comb(index+1, candidates, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int n=candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        comb(0, candidates, target, ds, ans);
        return ans;
    }
};