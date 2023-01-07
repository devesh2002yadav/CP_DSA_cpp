class Solution {
public:
    int trailingZeroes(int n) 
    {
        int five=0;
        for(int i=5; i<=n; i=i+5)
        {
            int x=i;
            while(x%5==0&&x>0)
            {
               five++;
               x/=5;
            }
        }
        return five;
    }
};
