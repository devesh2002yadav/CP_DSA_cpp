// 1) O(n*n) - two for loops - 

/*

int subarraysWithSumK(vector<int> a, int b) 
{
    int n=a.size();
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int xorr=0;
        for(int j=i; j<n; j++)
        {
            xorr=xorr^a[j];
            if(xorr==b)
            {
                ans++;
            }
        }
    }
    return ans;
}

*/


// 2) optimal - hashmap - O(nlogn)

#include<map>
int subarraysWithSumK(vector<int> a, int b) 
{
    int n=a.size();
    int ans=0;
    map<int, int> mp;
    int xorr=0;
    mp[xorr]++;
    for(int i=0; i<n; i++)
    {
        xorr=xorr^a[i];
        int xr=xorr^b;
        ans+=mp[xr];
        mp[xorr]++;
    }
    return ans;
}