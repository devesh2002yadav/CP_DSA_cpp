#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> ar) 
{
    int n=ar.size();
    unordered_map<int, int> mp;
    int sum=0;
    int ans=0;
    for(int i=0; i<n; i++)
    {
      sum+=ar[i];
      if(sum==0)
      {
        ans=i+1;
      }
      else
      {
        if(mp.find(sum)!=mp.end())
        {
          ans=max(ans, i-mp[sum]);
        }
        else mp[sum]=i;
      }
    }
    return ans;
}