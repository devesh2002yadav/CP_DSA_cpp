class Solution {
public:
    int findIntegers(int n) 
    {
        vector<int> dp(32);
        vector<int> dpz(32);
        vector<int> dpo(32);
        int ans=0;
        int chk=0;
        dpz[0]=dp[0]=1;
        for(int i=1; i<32; i++)
        {
            dpo[i]=dpz[i-1];
            dpz[i]=dpz[i-1]+dpo[i-1];
            dp[i]=dpz[i]+dpo[i];

        }
        for(int j=30; j>=0; j--)
        {
            int bit=(n>>j)&1;
            if(bit==1)
            {
                ans+=dp[j];
                if(chk==1) return ans;
            }
            chk=bit;
        }
        return ans+1;
    }
};