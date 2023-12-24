class Solution {
public:
    void nextPermutation(vector<int>& A) 
    {
           int n=A.size();
           int k=-1;
           for(int i=n-2; i>=0; i--)
           {
               if(A[i]<A[i+1])
               {
                k=i;
                break;
               }
           }
           if(k==-1)
           {
               reverse(A.begin(), A.end());
           }
           else
           {
           int x=A[k];
           for(int i=n-1; i>k; i--)
           {
               if(A[i]>A[k])
               {
                    swap(A[i], A[k]);
                    break;
               }
           }
           reverse(A.begin()+k+1, A.end());
           }
    }
};