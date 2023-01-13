
// DP

/*
How to calculate the number of valid combination of binary strings length of i (without consecutive ones)?

Let dpZero[i] is the number of valid combination of binary strings length of i and end at bit zero (without consecutive ones).
dpZero[i] = dpZero[i-1] + dpOne[i-1].

Let dpOne[i] is the number of valid combination of binary strings length of i and end at bit one (without consecutive ones).
dpOne[i] = dpZero[i-1], because we avoid consecutive ones.

Let dp[i] is the number of valid combination of binary strings length of i (without consecutive ones), dp[i] = dpZero[i] + dpOne[i], for example:
i = 0, dp[i] = dpZero[i] + dpOne[i] = 1 + 0 = 1, consider {""} empty as a valid one.
i = 1, dp[i] = dpZero[i] + dpOne[i] = 1 + 1 = 2, combinations are {"0", "1"}
i = 2, dp[i] = dpZero[i] + dpOne[i] = 2 + 1 = 3, combinations are {"00", "01", "10"}
i = 3, dp[i] = dpZero[i] + dpOne[i] = 3 + 2 = 5, combinations are {"000", "001", "010", "100", "101"}

Process from the most significant bit down to the least significant bit, k = 30...0, if the k_th bit of n is 1, we consider that bit as zero 
(to avoid consecutive ones) then we calculate number of combination of binary strings (without consecutive ones) of length k, that is dp[k].
Consider the example n = 21 binary representation as 10101, we have following valid combinations (where x can be 0 or 1) which less than or equal to n:
✔️ Group 1: 0xxxx, there are dp[4] = 8 combinations
✔️ Group 2: 100xx, there are dp[2] = 3 combinations.
✔️ Group 3: 10100, there is dp[0] = 1 combination.
✔️ Group 4: 10101 (value n ifself), there is 1 combination.
So there are total 8 + 3 + 1 + 1 = 13 combinations.
Let consider the example n = 58, binary representation as 111010, we have following valid combination (where x can be 0 or 1) which less than or equal to n:
✔️ Group 1: 0xxxxx, there are dp[5] = 13 combinations.
✔️ Group 2: 10xxxx, there are dp[4] = 8 combinations.
❌ Group 3: 110xxx, invalid because it contains consecutive ones
❌ Group 4: 11100x, invalid because it contains consecutive ones
So there are total 13 + 8 = 21 combinations.
We can see that if we met consecutive ones in our binary representation, the later groups will always invalid, so we just return result immediately, 
don't calculate anymore.

*/

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
