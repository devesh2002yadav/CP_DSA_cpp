class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        vector<int> one;
        vector<int> two;
        if(numRows==1)
        {
            one.push_back(1);
            ans.push_back(one);
        } 
        if(numRows==2)
        {
            one.push_back(1);
            two.push_back(1);
            two.push_back(1);
            ans.push_back(one);
            ans.push_back(two);
        }
        if(numRows>2)
        {
            one.push_back(1);
            two.push_back(1);
            two.push_back(1);
            ans.push_back(one);
            ans.push_back(two);
            for(int i=2; i<numRows; i++)
            {
                vector<int> val;
                val.push_back(1);
                for(int j=1; j<i; j++)
                {
                    int push=ans[i-1][j-1]+ans[i-1][j];
                    val.push_back(push);
                }
                val.push_back(1);
                ans.push_back(val);
            }
        }
        return ans;
    }
};