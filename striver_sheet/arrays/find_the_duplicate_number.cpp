// 1) sort - then compare consecutive elements

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(); int k=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
                if(nums[i]==nums[i+1])
                    return nums[i];
        }  
            return 0;
    }
        
};

// 2) freq count - using map or array 

/*

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        map<int, int> freq;
        for(int i=0; i<n; i++)
        {
            freq[nums[i]]++;
        }
        for(auto x:freq)
        {
            if(x.second>1)
            {
                return x.first;
            }
        }
        return 0;
    }
};

*/