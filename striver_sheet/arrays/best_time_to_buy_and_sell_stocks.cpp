class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int ans=0;
        int start=prices[0];
        for(int i=1; i<n; i++)
        {
            if(prices[i]<start)
            {
                start=prices[i];
            }
            ans=max(ans, prices[i]-start);
        }
        return ans;
    }
};