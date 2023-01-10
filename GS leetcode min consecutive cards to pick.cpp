class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        int ans=1000000; // or INT_MAX
        int n=cards.size();
        unordered_map<int, int> dm;
        for(int i=0; i<n; i++)
        {
            if(dm.find(cards[i])!=dm.end())
            {
                ans=min(ans, i-dm[cards[i]]+1);
            }
            dm[cards[i]]=i;
        }
        if(ans==1000000) return -1;
        else return ans;
    }
};
