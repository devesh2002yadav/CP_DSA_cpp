#include <algorithm>

bool comparator(vector<int> &a, vector<int> &b)
{
    return a[2]>b[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    sort(jobs.begin(), jobs.end(), comparator);
    int mx=0;
    int dl=0;
    int no=0;
    for(int i=0; i<n; i++)
    {
        dl=max(dl, jobs[i][1]);
    }
    bool slots[dl+1];
    for(int i=0; i<=dl; i++)
    {
        slots[i]=false;
    }
    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        for(int j=jobs[i][1]; j>0; j--)
        {
            if(slots[j]==false)
            {
                mx=mx+jobs[i][2];
                no+=1;
                slots[j]=true;
                break;
            }
        }
    }
    ans.push_back(no);
    ans.push_back(mx);
    return ans;
}