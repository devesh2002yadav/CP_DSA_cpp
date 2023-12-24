class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n=nums.size();
        int z=0;
        int o=0;
        int t=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {
                z++;
            }
            if(nums[i]==1)
            {
                o++;
            }
            if(nums[i]==2)
            {
                t++;
            }
        }
        for(int i=0; i<z; i++)
        {
            nums[i]=0;
        }
        for(int i=z; i<z+o; i++)
        {
            nums[i]=1;
        }
        for(int i=z+o; i<n; i++)
        {
            nums[i]=2;
        }
    }
};

// or
// dutch national flag algo - sort inplace 3 elements in array

/*

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n=nums.size();
        int low=0; int mid=0; int high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low], nums[mid]);
                low++; mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

*/