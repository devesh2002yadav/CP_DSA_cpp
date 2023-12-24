#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> val;
	sort(arr.begin(), arr.end());
	int rep=0;
	int mis=0;
	int sum=0;
	for(int i=0; i<n-1; i++)
	{
        if(arr[i]==arr[i+1])
		{
			rep=arr[i];
		}
	    sum+=arr[i];
	}
	sum+=arr[n-1];
	mis=(n*(n+1))/2-sum+rep;
	val=make_pair(mis, rep);
    return val;
}
