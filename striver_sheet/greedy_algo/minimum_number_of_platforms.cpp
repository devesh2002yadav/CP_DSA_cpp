
int calculateMinPatforms(int at[], int dt[], int n) 
{
    sort(at, at+n);
    sort(dt, dt+n);
    int temp=1;
    int ans=1;
    int ar=1;
    int dp=0;
    while(ar<n && dp<n)
    {
        if(at[ar]<=dt[dp])
        {
            temp++;
            ar++;
        }
        else
        {
            temp--;
            dp++;
        }
        ans=max(ans, temp);
    }
    return ans;
}
