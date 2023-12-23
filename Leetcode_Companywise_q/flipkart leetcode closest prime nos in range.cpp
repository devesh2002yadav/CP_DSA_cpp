class Solution {
 public:   
    int check_prime(int n){
    if(n==2) return 1;
 
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
    }
public:
    vector<int> closestPrimes(int left, int right) 
    {
        vector<int> pr;
        vector<int> ans;
        if(left==1) left++;
        while(left<=right)
        {
            if(check_prime(left)==1)
            {
                pr.push_back(left);
            }
            left++;
        }
        int x=pr.size();
        if(x<2)    
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else
        {
            vector<int> df;
            int mn=100000000;
            int val=0;
            for(int i=0; i<x-1; i++)
            {
                int dif=pr[i+1]-pr[i];
                df.push_back(dif);
                mn=min(mn, dif);
            }
            for(int j=0; j<df.size(); j++)
            {
                if(df[j]==mn)
                {
                    val=j;
                    break;
                }
            }
            ans.push_back(pr[val]);
            ans.push_back(pr[val+1]);
            return ans;
        }
    }
};