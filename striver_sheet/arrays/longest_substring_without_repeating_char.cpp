// 1) brute force - two for loops - O(n*n)

/*

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans=0;
        int n=s.length();
        if(n==0) return 0;
        for(int i=0; i<n; i++)
        {
            unordered_set<char> st;
            int x=0;
            for(int j=i; j<n; j++)
            {
                x++;
                st.insert(s[j]);
                if(st.size()!=x)
                {
                    ans=max(ans, x-1);
                    break;
                }
                if (j==n-1)
                {
                    ans = max(ans, x); 
                }
            }
        }
        if(ans==0) return 1;
        return ans;
    }
};

*/

// 2) optimised - hashmap - O(2*n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans=0;
        int n=s.length();
        unordered_set<char> st;
        int left=0;
        if(n==0) return 0;
        for(int right=0; right<n; right++)
        {
            char cur=s[right];
            while(st.count(cur))
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(cur);
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};